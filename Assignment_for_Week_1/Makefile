#------------------------------------------------------------------------------
# Simple make file for gcc
#
# Use: make [TARGET]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      <FILE>.i - Builds a <FILE>.i preprocessed file
#      <FILE>.asm - Dumps <FILE>.asm assembly file
#      <FILE>.d - Builds <FILE>.d dependency file
#      compile-all - Compiles all source files in project
#      build - Builds all object files in project (links as well)
#      clean - Removes all generated files
#
# Author: alexandergmzx
# Date:   January 13, 2019
#
#------------------------------------------------------------------------------
MAIN = main

TARGET = stats

GEN_FLAGS = -g -v 

SRCS = $(TARGET).c $(MAIN).c

CC = gcc
CFLAGS = $(GEN_FLAGS)
CPPFLAGS = $(INCLUDES)
LDFLAGS = -Wl,-Map=$(TARGET).map -lm
SIZE = size

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
ASMS = $(SRCS:.c=.asm)
PREP = $(SRCS:.c=.i)

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map 



