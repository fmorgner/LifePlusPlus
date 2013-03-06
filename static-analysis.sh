#!/usr/bin/env bash

scan-build -o ./reports clang -g -std=c++11 -stdlib=libc++ -lncurses -lc++abi -lpthread -lc++ src/CCell.cpp src/CWorld.cpp src/main.cpp -Iinclude -o Life++
