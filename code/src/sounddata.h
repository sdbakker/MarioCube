#ifndef __SOUNDDATA_H__
#define __SOUNDDATA_H__

#define SAMPLE_RATE_11025

/**
 * 10 files: bits, Hz
 * Total size: 124592 bytes
 */

#if defined(SAMPLE_RATE_8000)
#define SAMPLE_RATE 8000
#include "sounds/raw/smb_stage_clear_8000.h"
#include "sounds/raw/smb_powerup_appears_8000.h"
#include "sounds/raw/smb_jump_small_8000.h"
#include "sounds/raw/smb_gameover_8000.h"
#include "sounds/raw/smb_coin_8000.h"
#include "sounds/raw/smb_1_up_8000.h"
#include "sounds/raw/a_8000.h"
#elif defined(SAMPLE_RATE_11025)
#define SAMPLE_RATE 11025
#include "sounds/raw/smb_powerup_appears_11025.h"
#include "sounds/raw/smb_jump_small_11025.h"
#include "sounds/raw/smb_1_up_11025.h"
#include "sounds/raw/smb_coin_11025.h"
#include "sounds/raw/smb_stage_clear_11025.h"
#include "sounds/raw/a_11025.h"
#include "sounds/raw/smb_powerup_11025.h"
#include "sounds/raw/smb_stomp_11025.h"
#include "sounds/raw/smb_kick_11025.h"
#include "sounds/raw/smb_pause_11025.h"
#elif defined(SAMPLE_RATE_22050)
#define SAMPLE_RATE 22050
#include "sounds/raw/smb_world_clear_22050.h"
#endif

#define SOUNDS 10

uint_farptr_t sound_offset[SOUNDS];
#define INIT_SOUND_OFFSETS() \
    do { \
		sound_offset[0] = (uint_farptr_t)pgm_get_far_address(smb_powerup_appears_data0); \
		sound_offset[1] = (uint_farptr_t)pgm_get_far_address(smb_jump_small_data0); \
		sound_offset[2] = (uint_farptr_t)pgm_get_far_address(smb_coin_data0); \
		sound_offset[3] = (uint_farptr_t)pgm_get_far_address(smb_1_up_data0); \
		sound_offset[4] = (uint_farptr_t)pgm_get_far_address(smb_stage_clear_data0); \
		sound_offset[5] = (uint_farptr_t)pgm_get_far_address(a_data0); \
		sound_offset[6] = (uint_farptr_t)pgm_get_far_address(smb_powerup_data0); \
		sound_offset[7] = (uint_farptr_t)pgm_get_far_address(smb_stomp_data0); \
		sound_offset[8] = (uint_farptr_t)pgm_get_far_address(smb_kick_data0); \
		sound_offset[9] = (uint_farptr_t)pgm_get_far_address(smb_pause_data0); \
	} while(0)

const uint32_t sound_length[SOUNDS] = {
	(uint32_t)smb_powerup_appears_length,
	(uint32_t)smb_jump_small_length,
	(uint32_t)smb_coin_length,
	(uint32_t)smb_1_up_length,
	(uint32_t)smb_stage_clear_length,
	(uint32_t)a_length,
	(uint32_t)smb_powerup_length,
	(uint32_t)smb_stomp_length,
	(uint32_t)smb_kick_length,
	(uint32_t)smb_pause_length,
};

#endif
