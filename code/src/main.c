// EDIT: To make this program work with an ATMega1280, use PWM pin 10 as speakerPin.

/*
 * speaker_pcm
 *
 * Plays 8-bit PCM audio on pin 11 using pulse-width modulation (PWM).
 * For Arduino with Atmega168 at 16 MHz.
 *
 * Uses two timers. The first changes the sample value 8000 times a second.
 * The second holds pin 11 high for 0-255 ticks out of a 256-tick cycle,
 * depending on sample value. The second timer repeats 62500 times per second
 * (16000000 / 256), much faster than the playback rate (8000 Hz), so
 * it almost sounds halfway decent, just really quiet on a PC speaker.
 *
 * Takes over Timer 1 (16-bit) for the 8000 Hz timer. This breaks PWM
 * (analogWrite()) for Arduino pins 9 and 10. Takes Timer 2 (8-bit)
 * for the pulse width modulation, breaking PWM for pins 11 & 3.
 *
 * References:
 *     http://www.uchobby.com/index.php/2007/11/11/arduino-sound-part-1/
 *     http://www.atmel.com/dyn/resources/prod_documents/doc2542.pdf
 *     http://www.evilmadscientist.com/article.php/avrdac
 *     http://gonium.net/md/2006/12/27/i-will-think-before-i-code/
 *     http://fly.cc.fer.hr/GDM/articles/sndmus/speaker2.html
 *     http://www.gamedev.net/reference/articles/article442.asp
 *
 * Michael Smith <michael@hurts.ca>
 */

#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "sounddata.h"

//#define DEBUG
#define USE_RAND

#if !defined(SAMPLE_RATE)
#define SAMPLE_RATE 8000
#endif

/*
 * The audio data needs to be unsigned, 8-bit, 8000 Hz, and small enough
 * to fit in flash. 10000-13000 samples is about the limit.
 *
 * sounddata.h should look like this:
 *     const int sounddata_length=10000;
 *     const unsigned char sounddata_data[] PROGMEM = { ..... };
 *
 * You can use wav2c from GBA CSS:
 *     http://thieumsweb.free.fr/english/gbacss.html
 * Then add "PROGMEM" in the right place. I hacked it up to dump the samples
 * as unsigned rather than signed, but it shouldn't matter.
 *
 * http://musicthing.blogspot.com/2005/05/tiny-music-makers-pt-4-mac-startup.html
 * mplayer -ao pcm macstartup.mp3
 * sox audiodump.wav -v 1.32 -c 1 -r 8000 -u -1 macstartup-8000.wav
 * sox macstartup-8000.wav macstartup-cut.wav trim 0 10000s
 * wav2c macstartup-cut.wav sounddata.h sounddata
 *
 * (starfox) nb. under sox 12.18 (distributed in CentOS 5), i needed to run
 * the following command to convert my wav file to the appropriate format:
 * sox audiodump.wav -c 1 -r 8000 -u -b macstartup-8000.wav
 */


static volatile uint32_t sample;
static volatile char isPlaying;
static uint8_t sound_index;
static uint8_t lastSample;
static uint32_t sounddata_length;
static uint_farptr_t sounddata_data;

#define enable_amplifier()	PORTC |= _BV(PORTC0)
#define disable_amplifier()	PORTC &= ~(_BV(PORTC0))

void stopPlayback(void)
{
    disable_amplifier();

    /* Disable playback per-sample interrupt. */
    TIMSK3 &= ~_BV(OCIE3A);

    /* Disable the per-sample timer completely. */
    TCCR3B &= ~_BV(CS30);

    /* Disable the PWM timer. */
    TCCR1B &= ~_BV(CS10);

}

void startPlayback(void)
{
    /* PWM fast mode */
	/* 8-bit */
    TCCR1A = (TCCR1A & ~(_BV(WGM11))) | _BV(WGM10);
    TCCR1B = (TCCR1B & ~(_BV(WGM13))) | _BV(WGM12);

    /* enable OC1A */
    TCCR1A = _BV(COM1A1) | (TCCR1A  & (~_BV(COM1A0)));

    /* No prescale */
    TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);

    // Set initial pulse width to the first sample. */
    cli();
    OCR1A = pgm_read_byte_far(sounddata_data) / 2;

    /* Set up Timer 3 to send a sample every interrupt. */
    /* Set CTC mode (Clear Timer on Compare Match) */
    TCCR3B = (TCCR3B & ~_BV(WGM13)) | _BV(WGM12);
    TCCR3A &= ~(_BV(WGM11) | _BV(WGM10));

    /* No prescaler */
    TCCR3B = (TCCR3B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);

    OCR3A = F_CPU / SAMPLE_RATE;

    /* Enable interrupt */
    TIMSK3 |= _BV(OCIE3A);

    lastSample = pgm_read_byte_far(sounddata_data + sounddata_length - 1);
    sample = 0;

    /* Enable amplifier */
    PORTC |= _BV(PORTC0);

	isPlaying = 1;

    sei();
}

ISR(INT0_vect) {
	asm volatile ("nop");
}

ISR(TIMER3_COMPA_vect) {
    if (isPlaying) {
        if (sample >= sounddata_length) {
			stopPlayback();
			EIMSK |= _BV(INT0);
			isPlaying = 0;
		} else {
            OCR1A = pgm_read_byte_far(sounddata_data + sample) / 2;
        }

        sample++;
    }
}

#define SND_PWR_APPEAR	0
#define SND_JUMP_SMALL	1
#define SND_COIN		2
#define SND_1UP			3
#define SND_STAGE_CLR	4
#define SND_A			5
#define SND_PWR_UP		6
#define SND_STOMP		7
#define SND_KICK		8
#define SND_PAUSE		9

/* use distributions of size 2^n - 1 */
const uint8_t sound_distribution[] = {
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_COIN,
	SND_JUMP_SMALL,
	SND_JUMP_SMALL,
	SND_JUMP_SMALL,
	SND_JUMP_SMALL,
	SND_1UP,
	SND_1UP,
	SND_1UP,
	SND_1UP,
	SND_PWR_APPEAR,
	SND_PWR_APPEAR,
	SND_PWR_APPEAR,
	SND_PWR_APPEAR,
	SND_A,
	SND_A,
	SND_A,
	SND_A,
	SND_PWR_UP,
	SND_PWR_UP,
	SND_PWR_UP,
	SND_PWR_UP,
	SND_STOMP,
	SND_STOMP,
	SND_STOMP,
	SND_STOMP,
	SND_KICK,
	SND_KICK,
	SND_KICK,
	SND_KICK,
	SND_PAUSE,
	SND_PAUSE,
	SND_PAUSE,
	SND_PAUSE,
	SND_STAGE_CLR,
	SND_STAGE_CLR,
};

#define SOUND_DIST_LENGTH  (sizeof(sound_distribution) / sizeof(uint8_t))

void main(void)
{
	uint8_t __sreg_copy__ = 0;

    DDRA = 0x00;
    PORTA = 0xff;

    DDRB = 0x00;
    PORTB = 0xff;

    DDRC = 0x00 | _BV(DDC0);
    PORTC = 0xff & ~_BV(PORTC0);

    DDRD = 0x00 | _BV(DDD5);
    PORTD = 0xff; /*& ~_BV(PORTD5)*/;

    /* power reduction */
    PRR0 |= _BV(PRTIM0);     /* disable Timer/Counter0 */
    PRR0 |= _BV(PRTIM2);     /* disable Timer/Counter2 */
    PRR0 |= _BV(PRUSART0);   /* disable USART0 */
    PRR0 |= _BV(PRUSART1);   /* disable USART1 */
    PRR0 |= _BV(PRTWI);      /* disable TWI */
    PRR0 |= _BV(PRSPI);      /* disable SPI */
    PRR0 |= _BV(PRADC);      /* disable ADC */

#if !defined(DEBUG)
    MCUCR |= _BV(JTD);       /* disable On-chip debug */
#else
#warning On-Chip debug enabled
#endif

    sound_index = 0;;
    isPlaying = 0;

    INIT_SOUND_OFFSETS();

    SMCR =  _BV(SM1);    /* Power-down */
    SMCR |= _BV(SE);

	/* Button int0, falling edge */
    EICRA |=  _BV(ISC01);
    EIMSK |= _BV(INT0);

    for (;;) {

        if (!isPlaying) {
           uint8_t soundfile_index;

           PORTC &= ~_BV(PORTC0);

		   /* sleep block */
		   asm volatile("in %0,__SREG__"			"\n\t"
				    	"sei"          				"\n\t"
						"sleep"        				"\n\t"
						"out __SREG__,%0"			"\n\t"
						:"+r" (__sreg_copy__));

		   /* disable button interrupt */
		   EIMSK &= ~(_BV(INT0));

		   enable_amplifier();
           _delay_us(10);

           soundfile_index = sound_distribution[sound_index];
           sounddata_data = sound_offset[soundfile_index];
           sounddata_length = sound_length[soundfile_index];

           startPlayback();

#if defined(USE_RAND)
           sound_index = rand() & SOUND_DIST_LENGTH /* for lengths 2^n - 1 */;
#else
           sound_index++;
#endif
           if (sound_index >= SOUND_DIST_LENGTH) {
               sound_index = 0;
		   }
        }
    }
}
