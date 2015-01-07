#!/bin/bash

grep length *.raw | awk -F' ' '{ print $3 }' | sed -e 's/;//' | paste -sd '+' - | bc
