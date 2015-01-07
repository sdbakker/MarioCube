#ifndef __SOUNDDATA_H__
#define __SOUNDDATA_H__

/**
 * 9 files: 8bits, 8000Hz
 * Total size: 121160 bytes
 */

#define SOUNDS 9

uint_farptr_t sound_offsets[SOUNDS];
#define INIT_SOUND_OFFSETS()     do { EOF

cntr=0
for FILE in smb_coin_b8r8000.raw
smb_flagpole_b8r8000.raw
smb_jumpsmall_b8r8000.raw
smb_mariodie_b8r8000.raw
smb_pipe_b8r8000.raw
smb_stage_clear_b8r8000.raw
smb_stomp_b8r8000.raw
smb_vine_b8r8000.raw
smb_warning_b8r8000.raw
do
    echo "\t\tsound_offset[] = (uint_farptr_t)((uint16_t)(&smb_warning_data0)); \" >> sounddata_new.h
    cntr=1
done

echo "\t} while(0)" >> sounddata_new.h
echo "" >> sounddata_new.h
echo "const uint32_t sound_length[SOUNDS] = {" >> sounddata_new.h

for FILE in smb_coin_b8r8000.raw
smb_flagpole_b8r8000.raw
smb_jumpsmall_b8r8000.raw
smb_mariodie_b8r8000.raw
smb_pipe_b8r8000.raw
smb_stage_clear_b8r8000.raw
smb_stomp_b8r8000.raw
smb_vine_b8r8000.raw
smb_warning_b8r8000.raw
do
    echo "\tsmb_warning_length," >> sounddata_new.h
done

echo "};" >> sounddata_new.h
echo "" >> sounddata_new.h
echo "#endif" >> sounddata_new.h


