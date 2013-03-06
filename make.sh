#!/usr/bin/env bash

clang -std=c++11 -stdlib=libc++ -lncurses -lc++abi -lpthread -lc++ src/CCell.cpp src/CWorld.cpp src/main.cpp -Iinclude -o Life++

