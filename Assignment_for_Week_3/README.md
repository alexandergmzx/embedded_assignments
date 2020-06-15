# Assignment for Week 3: _Memory Types, Segments and Management_

MIT License

Copyright (c) 2020 J. Alexander Gómez G.

@date 2019-January-7

## Overview

This assignment is about learning:

- **Memory Organization**
- **Memory Segments**
- **Symbol tables**

# Content

- misc.h : Header file for misc.c . Contains 1 variable defined.
- misc.c :	Aid script. Contains a function and some definitions.
- main.c : Main script.
- msp432p401r.lds : Linker script for building the .out executable.
- Memory segments by definition.csv : Document that explains where is each symbol in memory and its attributes.

## Usage

Build the executable with the following command:

```
arm-none-eabi-gcc -o main.out main.c misc.c -Wl,-T msp432p401r.lds -Wl,-Map=main.map --specs=nosys.specs
```

This command creates:

- main.out :  The ELF executable for the MSP432.
- main.map : The map of the memory for analysis.


Optionally you can run the following command to get more information:

```
arm-none-eabi-objdump main.out -D > main_objdump.txt
arm-none-eabi-nm -pn main.out > main_nm.txt
```

## References for this part of the course

- [nm Binary Utility](https://sourceware.org/binutils/docs/binutils/nm.html)
