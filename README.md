# GrAAL - GeneRic Array Algorithms Library

## Summary

**[1. Introduction](#1-introduction)**

**[2. The Algorithms](#2-the-algorithms)**

**[3. Compiling](#3-compiling)**

**[4. Using library](#4-using-library)**

**[5. Authorship](#5-authorship)**

## 1. Introduction

The GrAAL is a series of functions that represent typical algorithms for array manipulation.
This project was developed following instructions and orientations given by Prof. Selan Rodrigues dos Santos.
By building this generic library we want to demonstrate the importance of programming abstraction, and code reuse while developing an application in the next exercise.

## 2. The Algorithms

We developed 11 algorithms based on problemas described at `docs/problems.pdf` file.

> Please, read the document to understand the problems.

## 3. Compiling

This project was developed using [CMake](http://cmake.org) and [GTest](https://github.com/google/googletest),
so you must have these softwares installed on your machine to compile successfully.

With these programs ready, you can use:

`mkdir build` (if is necessary)

`cd build`

`cmake ..`

`make`

and, finally run with `./run_tests`.

## 4. Using library

After these steps, you can use the compiled library in all your C++ future projects.

> Note: You may need change in `CMakeLists.txt` the location of installation of the library.

## 5. Authorship

This C++ library was developed by Victor Raphaell Vieira Rodrigues < victor@agenciaatwork.com >.

© IMD/UFRN 2019.
