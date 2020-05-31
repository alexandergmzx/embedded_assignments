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
# Use: make [TARGET] [PLATFORM-OVERRIDES] [FUNCTION] [DEBUG]
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
#      HOST - Default platform, compile for the host computer.
#      MSP432 - Target cross-compiled platform.
#
# Example : make build PLATFORM=MSP432 FUNCTION=COURSE1 DEBUG=VERBOSE	
#			# This builds all the object files for the MSP432, 
			#	activates the course1() function and prints the debug messages. 
#
# @author	Alexander Gómez
# @date 	2020-May-1
#
##############################################################################

include sources.mk

# Platform Overrides
PLATFORM = HOST
# Activate the function
FUNCTION = COURSE1
# Set the debug to NO
DEBUG = NODEBUG
# Target.out 
TARGET = c1m4

# General GCC compiler flags for both platforms
CFLAGS = -Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99

CPPFLAGS = -D$(FUNCTION) -D$(DEBUG) -MMD -MP

# Check for platform
ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds 
	CPU = cortex-m4 		
	ARCH = armv7e-m 		
	SPECS = nosys.specs 

	FLOATABI = hard
	FPU = fpv4-sp-d16

	ISAFLAG = -mthumb 

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc				# Compiler
	LD = arm-none-eabi-ld				# Loader
	CFLAGS += $(ISAFLAG) \
		-mcpu=$(CPU) \
		-march=$(ARCH) \
		--specs=$(SPECS) \
		-mfloat-abi=$(FLOATABI) \
		-mfpu=$(FPU)				# Compiler Flags

	CPPFLAGS += -DMSP432 $(INCLUDES)		# C-PreProcessor Flags

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
    OBJDMP = arm-none-eabi-objdump		

else
	# Compiler Flags and Defines
	CC = gcc 
	# GCC includes a preprocessor, Compiler, linker and loader.
	# CFLAGS = $(GEN_FLAGS)			# Compiler Flags
	CPPFLAGS += -DHOST $(INCLUDES)		# C-PreProcessor Flags
	LDFLAGS = -Wl,-Map=$(TARGET).map 	# Loader Flags, 
	# This also generates the -Map file for the full build
	SIZE = size
    	OBJDMP = objdump
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
	$(SIZE) $< $@

$(TARGET).asm: build
	$(OBJDMP) --disassemble $(TARGET).out > $(TARGET).asm

clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map $(TARGET).asm

