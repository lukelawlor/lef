#!/bin/sh
bin_dir=~/.local/bin
mkdir -p $bin_dir
cp cg $bin_dir
gcc -O3 -march=native lef.c -o $bin_dir/lef
strip $bin_dir/lef
