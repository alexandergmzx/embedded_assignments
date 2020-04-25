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
/*
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
#include "stats.h"

/*
 * @fn 		print_statistics
 *
 * @brief	Prints the statistics of an array including minimum, maximum, mean, and median.
 * In addition, data set is ordered from large to small. 
 * All statistics are rounded down to the nearest integer. 
 * After analysis and sorting is done, data is printed to the screen in 
 * a nicely formatted presentation
 *
 * @param arr[] The array to analyze
 *
 * @note	This function needs the functions "sort_array", "find_minimum", "find_maximum", 
 				"find_mean", and "find_median" to work properly. 
 */
#include "stats.h"

void print_statistics(unsigned char arr[]){

	sort_array(arr);
	printf("\nmedian: \t%d\n", find_median(arr));
	
	printf("mean: \t%d\n", find_mean(arr));
	
	printf("maximum: %d\n", find_maximum(arr));
	
	printf("minumum: %d\n", find_minimum(arr));	
	
}

void print_array(unsigned char arr[]){
	for(int i = 0; i < sizeof(arr)/8; i++){
		for(int j = 0; j < sizeof(arr)/5; j++){
		       printf("%3d  ", arr[8*i+j]);
		}
 		printf("\n");
	}
	printf("\n");
}

unsigned char find_median(unsigned char arr[]){
	return arr[(sizeof(arr)-1)/2];
}

unsigned char find_mean(unsigned char arr[]){
	unsigned int sum = 0;
	for(int i = 0; i < sizeof(arr); i++){
		sum += arr[i];	
	}
	return (unsigned char)( sum / sizeof(arr) );
}

unsigned char find_maximum(unsigned char arr[]){
	return arr[sizeof(arr)-1];
}

unsigned char find_minimum(unsigned char arr[]){
	return arr[0];
}

void sort_array(unsigned char arr[]){
	unsigned char tmp;
	for(int i = 0; i < sizeof(arr); i++){
		for(int j = i; j < sizeof(arr); j++){
			if(arr[j] < arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
