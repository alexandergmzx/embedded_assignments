# Assignment for Week 2: _Compilation with GCC and GNU Make_

@author Alexander Gómez

@date 2019-December-26

## Overview

This assignment is about learning:

- __Compiling and Invoking GCC__
- __Build Systems using GNU Toolsets__
- __C-Make and makefile creation__
- __GNU Binary Utilities__

## Content

This folder contains:

- _msp432p401r.lds_ linker file
- **src** folder
  - **_Makefile_** The elaborated mutiplatform makefile
  - _sou
rces.mk_ Aids the Makefile specifying the sources and includes to compile 
  - _main.c_ Main program to compile
  - _memory.c_ Memory Functions definition file
  - Other files, specifically for the MSP432 compilation
- **include** folder. Contains the drivers for the MSP432

## Running the makefile

For using this application you have to move to the **_src_** directory.

Use: make \[TARGET] \[PLATFORM-OVERRIDES]

With the possible platforms being the **HOST** Unix Computer and the **MSP432** Microcontroller.

### Targets

This **Makefile** can build 4 kinds of files:

- **<FILE>.i** - Builds a <FILE>.i Preprocessed file
- **<FILE>.asm** - Dumps <FILE>.asm Assembly file
- **<FILE>.d** - Builds <FILE>.d Dependency file
- **<FILE>.o** - Builds a <FILE>.o Object file

Example - This dumps the Assembly code of memory.c for the MSP432:
```
make memory.asm PLATFORM=MSP432
```
Other Targets:

- **compile-all** - Compiles all source files in project, but does not link.
- **build** - Builds all object files in project (links as well) and the output file
- **clean** - Removes all generated files

Example - Make the output file, try it in the unix computer then remove the generated files:
```
make build
./c1m2.out
make clean
```
## References for this part of the course

Some References checked for this assignment:

- [Github Readme Basic writing and formatting syntax](https://help.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax)
- [GNU Make book through examples](https://makefiletutorial.com/)
- [Cheat Sheet by bavo.van.achte](https://cheatography.com/bavo-van-achte/cheat-sheets/gnumake/)

