#!/usr/bin/env bash

clang -O3 -std=c++11 -stdlib=libc++ -lncurses -lc++abi -lpthread -lc++ src/CCell.cpp src/CWorld.cpp src/main.cpp -Iinclude -o Life++

