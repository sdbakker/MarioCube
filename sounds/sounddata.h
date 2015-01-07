#ifndef __SOUNDDATA_H__
#define __SOUNDDATA_H__

/**
 * Sound files: 8bits, 8000Hz
 */

#include "smb_coin_b8r8000.raw"
#include "smb_flagpole_b8r8000.raw"
#include "smb_jumpsmall_b8r8000.raw"
#include "smb_mariodie_b8r8000.raw"
#include "smb_pipe_b8r8000.raw"
#include "smb_stage_clear_b8r8000.raw"
#include "smb_stomp_b8r8000.raw"
#include "smb_vine_b8r8000.raw"
#include "smb_warning_b8r8000.raw"

/**
 * Total size: 121160 bytes
 */

#define SOUNDS              9
#define FIRST_SOUND_OFFSET  (uint_farptr_t)((uint16_t)(&smb_coin_b8r8000_data))

const uint_farptr_t sound_offset[SOUNDS] = {
    (uint_farptr_t)((uint16_t)(&smb_coin_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_flagpole_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_jumpsmall_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_mariodie_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_pipe_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_stage_clear_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_stomp_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_vine_b8r8000_data)),
    (uint_farptr_t)((uint16_t)(&smb_warning_b8r8000_data))
};

const uint32_t sound_length[SOUNDS] = {
    smb_coin_b8r8000_length,
    smb_flagpole_b8r8000_length,
    smb_jumpsmall_b8r8000_length,
    smb_mariodie_b8r8000_length,
    smb_pipe_b8r8000_length,
    smb_stage_clear_b8r8000_length,
    smb_stomp_b8r8000_length,
    smb_vine_b8r8000_length,
    smb_warning_b8r8000_length
};

const uint8_t sound_distribution[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8
}

#define SOUND_DIST_LENGTH  (sizeof(sound_distribution) / sizeof(uint8_t))

#endif
