# Assignment for Week 4: _Final assessment_

@author Alexander Gómez

@date 2020-January-20

## Content

This folder contains:

- _msp432p401r.lds_ linker file
- _Makefile_ The elaborated mutiplatform makefile
- _sources.mk_ Aids the Makefile specifying the sources and includes to compile 
- **src** folder
  - _main.c_ Main program to compile
  - _memory.c_ Memory Functions definition file
**More TBD**
  - Other files, for the MSP432 files compilation
- **include** folder. Contains the drivers for the MSP432

### Targets

**More TBD**

This **Makefile** can build 4 kinds of files:

- **\<FILE>.i** - Builds a \<FILE>.i Preprocessed file
- **\<FILE>.asm** - Dumps \<FILE>.asm Assembly file
- **\<FILE>.d** - Builds \<FILE>.d Dependency file
- **\<FILE>.o** - Builds a \<FILE>.o Object file

Example - This dumps the Assembly code of memory.c for the MSP432:
```
make memory.asm PLATFORM=MSP432
```
Other Targets:

- **compile-all** - Compiles all source files in project, but does not link.
- **build** - Builds all object files in project (links as well) and the output file
- **clean** - Removes all generated files

Example - Make the output file, try it in the unix computer then remove the generated files (The platform is not specified because the host is the default platform):
```
make build
./c1m4.out
make clean
```
## References for this part of the course

**More TBD**
