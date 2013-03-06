#!/usr/bin/env bash

mkdir -p build/Release/

clang -O3 -g0 -std=c++11 -stdlib=libc++ -lncurses -lc++abi -lpthread -lc++ src/CCell.cpp src/CWorld.cpp src/main.cpp -Iinclude -o build/Release/Life++
