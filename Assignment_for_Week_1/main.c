/*
 * @file	- Assignment_for_Week_1/main.c
 *
 * @brief	- This is the implementation of the stats functions
 *
 * @author Alexander Gomez
 *
 * @date 2020-April-25
 * 
 * MIT License
 *
 * Copyright (c) 2020 J. Alexander Gómez G.
 *
 */

/* Data Set array */
unsigned char test[40] = { 34, 201, 190, 154,   8, 194,   2,   6,
                          114, 88,   45,  76, 123,  87,  25,  23,
                          200, 122, 150, 90,   92,  87, 177, 244,
                          201,   6,  12,  60,   8,   2,   5,  67,
                            7,  87, 250, 230,  99,   3, 100,  90};

#include <stdio.h>
#include <string.h>
#include "stats.h"


int main(void) {
  printf("test array:\n");
  print_array(test);

  print_statistics(test);

  printf("\nsorted array:\n");
  //sort_array(test);
  print_array(test);

  return 0;
}
