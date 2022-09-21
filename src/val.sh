#! /usr/bin/env bash

mkdir -p buildvalgrind
cd buildvalgrind
svn co svn://svn.valgrind.org/valgrind/trunk/@14960 valgrind
cd valgrind
./autogen.sh
./configure --prefix=/usr/local
make && sudo make install