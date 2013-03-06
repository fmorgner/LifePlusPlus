#!/usr/bin/env bash

mkdir -p build/Debug
clang -O0 -g -std=c++11 -stdlib=libc++ -lncurses -lc++abi -lpthread -lc++ src/CCell.cpp src/CWorld.cpp src/main.cpp -Iinclude -o build/Debug/Life++
