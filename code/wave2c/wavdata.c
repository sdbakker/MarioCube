/* wave2c, a WAV file to GBA C source converter.
 * Copyright (c) 2003 by Mathieu Brethes.
 *
 * Contact : thieumsweb@free.fr
 * Website : http://thieumsweb.free.fr/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "wavdata.h"
#include <stdint.h>

/* Loads a wave header in memory, and checks for its validity. */
/* returns NULL on error, a malloced() wavSound* otherwise.    */
wavSound * loadWaveHeader(FILE * fp) {
	char c[5];
	int nbRead;
	int chunkSize;
	int subChunk1Size;
	int subChunk2Size;
	short int audFormat;
	short int nbChannels;
	int sampleRate;
	int byteRate;
	short int blockAlign;
	short int bitsPerSample;
	wavSound *w;

	c[4] = 0;

	nbRead=fread(c, sizeof(char), 4, fp);
	
	// EOF ?
	if (nbRead < 4) return NULL;
	
	// Not a RIFF ?
	if (strcmp(c, "RIFF") != 0) {
		printf("Not a RIFF: %s\n", c);
		return NULL;
	}

	nbRead=fread(&chunkSize, sizeof(int), 1, fp);
	
	// EOF ?
	if (nbRead < 1) return NULL;

	nbRead=fread(c, sizeof(char), 4, fp);
	
	// EOF ?
	if (nbRead < 4) return NULL;
	
	// Not a WAVE riff ?
	if (strcmp(c, "WAVE") != 0) {
		printf("Not a WAVE: %s\n", c);
		return NULL;
	}

	nbRead=fread(c, sizeof(char), 4, fp);
	
	// EOF ?
	if (nbRead < 4) return NULL;
	
	// Not a "fmt " subchunk ?
	if (strcmp(c, "fmt ") != 0) {
		printf("No fmt subchunk: %s\n", c);
		return NULL;
	}

	// read size of chunk.
	nbRead=fread(&subChunk1Size, sizeof(int), 1, fp);
	if (nbRead < 1) return NULL;

	// is it a PCM ?
	if (subChunk1Size != 16) {
		printf("Not PCM fmt chunk size: %x\n", subChunk1Size);
		return NULL;
	}
	
	nbRead=fread(&audFormat, sizeof(short int), 1, fp);
	if (nbRead < 1) return NULL;

	// is it PCM ?
	if (audFormat != 1) {
		printf("No PCM format (1): %x\n", audFormat);
		return NULL;
	}

	nbRead=fread(&nbChannels, sizeof(short int), 1, fp);
	if (nbRead < 1) return NULL;

	// is it mono or stereo ?
	if (nbChannels > 2 || nbChannels < 1) {
		printf("Number of channels invalid: %x\n", nbChannels);
		return NULL;
	}

	nbRead=fread(&sampleRate, sizeof(int), 1, fp);
	if (nbRead < 1) return NULL;

	nbRead=fread(&byteRate, sizeof(int), 1, fp);
	if (nbRead < 1) return NULL;

	nbRead=fread(&blockAlign, sizeof(short int), 1, fp);
	if (nbRead < 1) return NULL;

	nbRead=fread(&bitsPerSample, sizeof(short int), 1, fp);
	if (nbRead < 1) return NULL;
	
	nbRead=fread(c, sizeof(char), 4, fp);
	
	// EOF ?
	if (nbRead < 4) return NULL;
	
	// Not a data section ?
	if (strcmp(c, "data") != 0) {
		printf("Not a data subchunk: %s\n", c);
		return NULL;
	}

	nbRead=fread(&subChunk2Size, sizeof(int), 1, fp);
	if (nbRead < 1) return NULL;

	// Now we can generate the structure...
	
	w = (wavSound *) malloc(sizeof(wavSound));
	// out of memory ?
	if (w == NULL) {
		printf("Out of memory, sorry\n");	
		return w;
	}

	w->sampleRate = sampleRate;
	w->numChannels = nbChannels;
	w->bitsPerSample = bitsPerSample;
	w->dataLength = subChunk2Size;

	return w;
}

/* Loads the actual wave data into the data structure. */
void saveWave(FILE * fpI, wavSound *s, FILE * fpO, char * name) {
	long filepos;
	int i;
	int realLength;
	unsigned char stuff8;
	uint16_t stuff16;

	filepos = ftell(fpI);
	
	/* Print general information) */
	fprintf(fpO, "#ifndef __%s_H__\n#define __%s_H__\n\n", name, name);
	fprintf(fpO, "// %s sound made by wav2c (adapted by simon@simbits.nl)\n\n", name);
	fprintf(fpO, "#define %s_sampleRate %d\n", name, s->sampleRate);

	realLength = (s->dataLength / s->numChannels / s->bitsPerSample * 8);

	fprintf(fpO, "#define %s_length %d\n\n", name, realLength);

	/* Is it a stereo file ? */
	if (s->numChannels == 2) {
		fprintf(fpO, "const signed char %s_dataL[]={", name);
		/* 8-bit ? convert 0-255 to -128-127 */
		if (s->bitsPerSample == 8) {
			for (i = 0 ; i < realLength ; i++) {
				fread(&stuff8, sizeof(unsigned char), 1, fpI);
				fprintf(fpO, "%d, ", -128 + stuff8);
				// read right output and forget about it
				fread(&stuff8, sizeof(unsigned char), 1, fpI);
				if ((i % 20) == 0) fprintf(fpO, "\n");
			}
			// reset file position;
			fseek(fpI, filepos, SEEK_SET);
			fprintf(fpO, "};\n\n");
			fprintf(fpO, "const signed char %s_dataR[]={", name);
			for (i = 0 ; i < realLength ; i++) {
				// read left output and forget about it
				fread(&stuff8, sizeof(unsigned char), 1, fpI);
				fread(&stuff8, sizeof(unsigned char), 1, fpI);
				fprintf(fpO, "%d, ", -128 + stuff8);
				if ((i % 20) == 0) fprintf(fpO, "\n");
			}
			fprintf(fpO, "};\n");
		}
		/* 16-bit ? convert signed 16 to signed 8 */
		else {
			for (i = 0 ; i < realLength ; i++) {
				// We take only MSB of wave data...
				fread(&stuff8, sizeof(char), 1, fpI);
				fread(&stuff8, sizeof(char), 1, fpI);
				fprintf(fpO, "%d, ", (signed char)stuff8);
				// read right output and forget about it
				fread(&stuff8, sizeof(char), 1, fpI);
				fread(&stuff8, sizeof(char), 1, fpI);
				if ((i % 20) == 0) fprintf(fpO, "\n");
			}
			// reset file position;
			fseek(fpI, filepos, SEEK_SET);
			fprintf(fpO, "};\n\n");
			fprintf(fpO, "const signed char %s_dataR[]={", name);
			for (i = 0 ; i < realLength ; i++) {
				// read left output and forget about it
				fread(&stuff8, sizeof(char), 1, fpI);
				fread(&stuff8, sizeof(char), 1, fpI);
				fread(&stuff8, sizeof(char), 1, fpI);
				fread(&stuff8, sizeof(char), 1, fpI);
				fprintf(fpO, "%d, ", (signed char)stuff8);
				if ((i % 20) == 0) fprintf(fpO, "\n");
			}
			fprintf(fpO, "};\n");
		}
	}
	/* Monaural file */
	else {
        int block = 0;

		if (s->bitsPerSample == 8) {
			printf("real length: %d\n", realLength);
			fprintf(fpO, "#define __%s_data%d \\\n", name, block);
			for (i = 1 ; i <= realLength ; i++) {
				fread(&stuff8, sizeof(unsigned char), 1, fpI);
				fprintf(fpO, "0x%.2x, ", stuff8);
                if ((i % 5400) == 0 && i > 0) {
                    block++;
					fprintf(fpO, "\n\n#define __%s_data%d \\\n", name, block);
                } else if ((i % 20) == 0 && i > 0) fprintf(fpO, "\\\n");
			}

			fprintf(fpO, "\n\n");
			for (i=block; i>=0; i--) {
				fprintf(fpO, "const uint8_t %s_data%d[] PROGMEM = { __%s_data%d };\n", name, i, name, i);
			}
		} else {
			printf("16-bit file\n");
			fprintf(fpO, "const uint8_t %s_data%d[] PROGMEM = {\n", name, block);
			for (i = 0 ; i < realLength ; i++) {
				uint16_t stuff16;
				//fread(&stuff8, sizeof(uint8_t), 1, fpI);
				//fprintf(fpO, "0x%.2x, ", (uint8_t)stuff8);
				//fread(&stuff8, sizeof(uint8_t), 1, fpI);
				//fprintf(fpO, "0x%.2x, ", (uint8_t)stuff8);
				
				fread(&stuff16, sizeof(uint8_t), 2, fpI);
				fprintf(fpO, "0x%.2x, ", (uint8_t)(stuff16 >> 8));
				fprintf(fpO, "0x%.2x, ", (uint8_t)(stuff16 & 0x00ff));

				if ((i % 20) == 0 && i > 0) fprintf(fpO, "\n");
                if ((i % 5400) == 0 && i > 0) {
                    block++;
                    fprintf(fpO, "};\n");
                    fprintf(fpO, "const uint8_t %s_data%d[] PROGMEM = {\n", name, block);
                }
			}
		}
	}

	fprintf(fpO, "\n#endif /* __%s_H__ */\n", name);
}
		



