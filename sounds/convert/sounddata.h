#ifndef __SOUNDDATA_H__
#define __SOUNDDATA_H__

/**
 * 10 files: bits, Hz
 * Total size: 124592 bytes
 */
#include "smb_coin_8bit.raw"
#include "smb_flagpole_8bit.raw"
#include "smb_gameover_8bit.raw"
#include "smb_jumpsmall_8bit.raw"
#include "smb_kick_8bit.raw"
#include "smb_mariodie_8bit.raw"
#include "smb_pipe_8bit.raw"
#include "smb_stage_clear_8bit.raw"
#include "smb_stomp_8bit.raw"
#include "smb_vine_8bit.raw"

#define SOUNDS 10

uint_farptr_t sound_offset[SOUNDS];
#define INIT_SOUND_OFFSETS() \
    do { \
		sound_offset[0] = (uint_farptr_t)pgm_get_far_address(smb_coin_8bit_data0); \
		sound_offset[1] = (uint_farptr_t)pgm_get_far_address(smb_flagpole_8bit_data0); \
		sound_offset[2] = (uint_farptr_t)pgm_get_far_address(smb_gameover_8bit_data0); \
		sound_offset[3] = (uint_farptr_t)pgm_get_far_address(smb_jumpsmall_8bit_data0); \
		sound_offset[4] = (uint_farptr_t)pgm_get_far_address(smb_kick_8bit_data0); \
		sound_offset[5] = (uint_farptr_t)pgm_get_far_address(smb_mariodie_8bit_data0); \
		sound_offset[6] = (uint_farptr_t)pgm_get_far_address(smb_pipe_8bit_data0); \
		sound_offset[7] = (uint_farptr_t)pgm_get_far_address(smb_stage_clear_8bit_data0); \
		sound_offset[8] = (uint_farptr_t)pgm_get_far_address(smb_stomp_8bit_data0); \
		sound_offset[9] = (uint_farptr_t)pgm_get_far_address(smb_vine_8bit_data0); \
	} while(0)

const uint32_t sound_length[SOUNDS] = {
	(uint32_t)smb_coin_8bit_length,
	(uint32_t)smb_flagpole_8bit_length,
	(uint32_t)smb_gameover_8bit_length,
	(uint32_t)smb_jumpsmall_8bit_length,
	(uint32_t)smb_kick_8bit_length,
	(uint32_t)smb_mariodie_8bit_length,
	(uint32_t)smb_pipe_8bit_length,
	(uint32_t)smb_stage_clear_8bit_length,
	(uint32_t)smb_stomp_8bit_length,
	(uint32_t)smb_vine_8bit_length,
};

#endif
