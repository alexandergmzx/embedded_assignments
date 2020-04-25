# Assignment for Week 1: **Embedded System Development Components**

# Overview

This assignment is about learning to:

- "Version control" systems with Github
- "C Standardization and Team Coding Standards" (Jack Ganssle's firmware development standard)
- GCC (GNU compiler Colection) introduction

The assignmet was to declare, define and implement functions that, given an array, prints some statistics of the content. Then the files should be compiled with the GCC. 

The compilation and running can be done with these commands:
```
gcc main.c stats.c -o main.out -std=c99
./main.out
```

# Content

This folder contains:

- __**stats.h**__	The function Declaration header 
- __**stats.c**__	The function Definition file
- __**main.c**__	The function Implementation file

Additionaly this folder contains a __makefile__, which can ease the compilation, gives some information that will be learned later.

# Reference cards (Cheat sheets)

Some Cheat sheets were used for this assignment:

- [Atlassian **Git** Cheat sheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)
- [J. H. Silverman **C** Reference Card (ANSI)](https://www.math.brown.edu/~jhs/)
- [wiki C reference](https://en.cppreference.com/w/c)
