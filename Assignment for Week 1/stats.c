/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Statistics functions
 *
 * Set of functions that can analyze an array of unsigned char data items 
 * and report analytics on the maximum, minimum, mean, and median of the data set. 
 * In addition, data set is ordered from large to small. 
 * All statistics are rounded down to the nearest integer. 
 * After analysis and sorting is done, data is printed to the screen in 
 * a nicely formatted presentation
 *
 * @author Alexander Gomez
 * @date 2020-Jan-6
 *
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

void print_statistics(unsigned char arr[]){

	sort_array(arr);
	printf("\nmedian value: %d\n", find_median(arr));
	
	printf("mean value: %d\n", find_mean(arr));
	
	printf("maximum value: %d\n", find_maximum(arr));
	
	printf("minumum value: %d\n", find_minimum(arr));	
	
}

void print_array(unsigned char arr[]){
	for(int i = 0; i < SIZE/8; i++){
		for(int j = 0; j < SIZE/5; j++){
		       printf("%3d  ", arr[8*i+j]);
		}
 		printf("\n");
	}
	printf("\n");
}

unsigned char find_median(unsigned char arr[]){
	return arr[(SIZE-1)/2];
}

unsigned char find_mean(unsigned char arr[]){
	unsigned int sum = 0;
	for(int i = 0; i < SIZE; i++){
		sum += arr[i];	
	}
	return (unsigned char)( sum / SIZE );
}

unsigned char find_maximum(unsigned char arr[]){
	return arr[SIZE-1];
}

unsigned char find_minimum(unsigned char arr[]){
	return arr[0];
}

void sort_array(unsigned char arr[]){
	unsigned char tmp;
	for(int i = 0; i < SIZE; i++){
		for(int j = i; j < SIZE; j++){
			if(arr[j] < arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
