/*****************************************************************************
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
 * @file	stats.c 
 * 
 * @brief	Statistics functions that analyze an array of data.
 *
 * Set of functions that can analyze an array of unsigned char data items 
 * and report analytics on the maximum, minimum, mean, and median of the data set. 
 * 
 * The fuctions are implemented in main.c
 *
 * @author	Alexander Gomez
 *
 * @date	2020-Jan-3
 */


#include <stdio.h>
#include <string.h>
#include "stats.h"

// int main(void) {
// //#ifdef VERBOSE  
//   /* Data Set array */
//   unsigned char test[40] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                           114, 88,   45,  76, 123,  87,  25,  23,
//                           200, 122, 150, 90,   92,  87, 177, 244,
//                           201,   6,  12,  60,   8,   2,   5,  67,
//                             7,  87, 250, 230,  99,   3, 100,  90};
//   printf("test array:\n");
//   int len = strlen(test);
//   print_array(test, len);

//   print_statistics(test, len);

//   printf("\nsorted array:\n");
//   //sort_array(test, len);
//   print_array(test, len);
// //#endif
//   return 0;
// }

void print_statistics(unsigned char arr[], unsigned int length){
//#ifdef VERBOSE
	sort_array(arr, length);

	printf("\nmedian: \t%d\n", find_median(arr, length));
	
	printf("mean:	\t%d\n", find_mean(arr, length));
	
	printf("maximum:\t%d\n", find_maximum(arr, length));
	
	printf("minimum:\t%d\n", find_minimum(arr, length));	
//#endif
}

void print_array(unsigned char arr[], unsigned int length){
//#ifdef VERBOSE
	printf("\n");
	for(int i = 0; i < length; i++){
    	printf("%d -\t(%x)\n",i,arr[i]);
	}
	printf("\n");
//#endif
}

unsigned char find_median(unsigned char arr[], unsigned int length){
	sort_array(arr, length);
	return arr[(length-1)/2];
}

unsigned char find_mean(unsigned char arr[], unsigned int length){
	unsigned int sum = 0;
	for(int i = 0; i < length; i++){
		sum += arr[i];	
	}
	return (unsigned char)( sum / (float)length );
}

unsigned char find_maximum(unsigned char arr[], unsigned int length){
	sort_array(arr, length);
	return arr[length-1];
}

unsigned char find_minimum(unsigned char arr[], unsigned int length){
	sort_array(arr, length);
	return arr[0];
}

void sort_array(unsigned char arr[], unsigned int length){
	unsigned char tmp;
	for(int i = 0; i < length; i++){
		for(int j = i; j < length; j++){
			if(arr[j] < arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
