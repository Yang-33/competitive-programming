#!/bin/bash

Tm="*.TM"
Home="/mnt/c/home/"
Base="competitive-programming/"
Tm_dir=".TM.d"


cd ${Home}${Base}${Tm.dir}

for File in `\find . -maxdepth 1 -type f -name "${Tm}"`
do
    sed -i -e "s|update|update|g" ${File}
done

echo ".TM file have been all updated."
