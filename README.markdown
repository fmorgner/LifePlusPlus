# README

This file talks about some aspects of Life++, where it originated, how to build it and how to debug it

## Where did Life++ come from

Once upon a time there was no space... just kidding. Life++ started as sort of a training on C++ for myself.
I always wanted to implement a version of the famous "Game of Life" and it appeared to me, that now is the
right time since I'm going to start my bachelor studies in Informatics (I think I'm going to concentrate on
software development). Being that i used to programm in C++ some years ago and having programmed for the last
couple of years more or less in Objective-C I needed a refresher on C++.

## Building Life++

First you are going to need some amino acids and... ahw couldn't help, sorry! Building Life++ is rather easy
since it uses the CMake build environment. It is receommended by the CMake comunity that you build "out-of-source".
To do so, simply create a directory for your build files (call it build for example) change into it and call
"cmake .." (without the quotes of course). After CMake finishes its magic you can simply execute "make" and
Life qill be build. Note however, that using "cmake .." without specifying the build type leads to the generation
of a non optimized build without debug symbols. Therefore I recommend that you specify either "-DCMAKE_BUILD_TYPE=Release"
or "-DCMAKE_BUILD_TYPE=Debug".

## Debugging Life++

This time no lame jokes, I promise! It is essential, that you run cmake supplying "-DCMAKE_BUILD_TYPE=Debug"
as a prameter, so that debug symbols are included in the generated executable. Please note that if you ran
cmake before without specifying "-DCMAKE_BUILD_TYPE=Debug", you need to delete all generated files and run
cmake again. After that, just load Life++ in you debugger of choice, should be LLDB, and hack away!