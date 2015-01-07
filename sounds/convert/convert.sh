#!/bin/bash

HEADER=$1
files=0

rm *.raw
rm *_conv.wav
rm $HEADER

for FILE in `ls *.wav`
do
    OUTFILE=${FILE%%.*}_conv.wav
    RAW_FILE=${FILE%%.*}.raw

    echo -e "converting $FILE"

    sox -V2 $FILE -c 1 -b 8 -r 8000 -u -1 $OUTFILE vol 0.25
    ./wav2c $OUTFILE $RAW_FILE ${FILE%%.*}
    files=$((files+1))
done

TOTAL_SIZE=`./total_size.sh`

cat > $HEADER << EOF
#ifndef __SOUNDDATA_H__
#define __SOUNDDATA_H__

/**
 * $files files: ${BITS}bits, ${RATE}Hz
 * Total size: ${TOTAL_SIZE} bytes
 */
EOF

for FILE in `ls *.raw`
do
    echo -e "#include \"${FILE}\"" >> $HEADER
done

cat >> $HEADER << EOF

#define SOUNDS $files

uint_farptr_t sound_offset[SOUNDS];
#define INIT_SOUND_OFFSETS() \\
    do { \\
EOF

cntr=0
for FILE in `ls *.raw`
do
    echo -e "\t\tsound_offset[${cntr}] = (uint_farptr_t)pgm_get_far_address(${FILE%%.*}_data0); \\" >> $HEADER
    cntr=$((cntr+1))
done

echo -e "\t} while(0)" >> $HEADER
echo -e "" >> $HEADER
echo -e "const uint32_t sound_length[SOUNDS] = {" >> $HEADER

for FILE in `ls *.raw`
do
    echo -e "\t(uint32_t)${FILE%%.*}_length," >> $HEADER
done

echo -e "};" >> $HEADER
echo -e "" >> $HEADER
echo -e "#endif" >> $HEADER
