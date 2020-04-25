/*
 * @file	- Assignment_for_Week_1/main.c
 *
 * @brief	- This is the implementation of the stats functions
 *
 * @author Alexander Gomez
 *
 * @date 2020-April-25
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  printf("test array:\n");
  print_array(test);

  print_statistics(test);

  printf("\nsorted array:\n");
  //sort_array(test);
  print_array(test);
}