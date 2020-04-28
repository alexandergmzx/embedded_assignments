#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

##############################################################################
# Simple make file to support two build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      <FILE>.i - Builds a <FILE>.i preprocessed file
#      <FILE>.asm - Dumps <FILE>.asm assembly file
#      <FILE>.d - Builds <FILE>.d dependency file
#      compile-all - Compiles all source files in project, but does not link.
#      build - Builds all object files in project (links as well)
#      clean - Removes all generated files
#
# Platform Overrides:
#      HOST - Default platform
#      MSP432 - Target cross-compiled platform
#
# Example : make build PLATFORM=MSP432 		
#			# This builds all the object files for the MSP432 
#
# @author	alexandergmzx
# @date 	2020-December-26
#
##############################################################################

include sources.mk

# Platform Overrides
PLATFORM = HOST

TARGET = c1m2

# General flags for both platforms
GEN_FLAGS = -Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99

# Check for platform
ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds 
	CPU = cortex-m4 		
	ARCH = armv7e-m 		
	SPECS = nosys.specs 	
	EXTRA = -mthumb \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc				# Compiler
	LD = arm-none-eabi-ld				# Loader
	CFLAGS = $(GEN_FLAGS) $(EXTRA) \
			-mcpu=$(CPU) \
			-march=$(ARCH) \
			--specs=$(SPECS)			# Compiler Flags

	CPPFLAGS = -DMSP432 $(INCLUDES)		# C-PreProcessor Flags

	LDFLAGS = -Wl,-Map=$(TARGET).map\
		  -L -T../$(LINKER_FILE)	# Loader Flags
										# This also generates the Map file for the full build


	# Architecture specific source codes
	SOURCE = main.c \
			 memory.c \
			 startup_msp432p401r_gcc.c \
			 system_msp432p401r.c \
			 interrupts_msp432p401r_gcc.c 
	
	SIZE = arm-none-eabi-size			

else
	# Compiler Flags and Defines
	CC = gcc 
	# GCC includes a preprocessor, Compiler, linker and loader.
	CFLAGS = $(GEN_FLAGS)			# Compiler Flags
	CPPFLAGS = -DHOST $(INCLUDES)		# C-PreProcessor Flags
	LDFLAGS = -Wl,-Map=$(TARGET).map 	# Loader Flags, This also generates the -Map file for the full build
	SIZE = size
endif

# Pattern Matching - Associate source files with:
OBJS = $(SRCS:.c=.o)	# Object files
DEPS = $(SRCS:.c=.d)	# Dependency files
ASMS = $(SRCS:.c=.asm)	# Assembly files
PREP = $(SRCS:.c=.i)	# Preprocessed files

# Dependency Files for each source file 
%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@
# Preprocessed output of implementation files
%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@
# Assembly output files
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@
# Individual object files
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Special target names/non-file targets
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

.PHONY: clean

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map 

