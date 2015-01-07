#!/bin/bash

set -x

INDIR=$1
OUTDIR=$2
SAMPLERATE=$3
TMPDIR=.wav

WAV2C=wav2c

mkdir $TMPDIR
mkdir $OUTDIR

for f in `ls -1 $1/*`
do
	name=`basename $f`
	name=${name%%.*}

	echo "converting $name"
	sox --norm $f -c 1 -b 8 $TMPDIR/${name}_${SAMPLERATE}.wav rate $SAMPLERATE dither -s
	$WAV2C .wav/${name}_${SAMPLERATE}.wav raw/${name}_${SAMPLERATE}.h $name
done
