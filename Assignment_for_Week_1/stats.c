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
#include <string.h>
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
void print_statistics(unsigned char arr[]){

	sort_array(arr);

	printf("\nmedian: \t%d\n", find_median(arr));
	
	printf("mean:	\t%d\n", find_mean(arr));
	
	printf("maximum:\t%d\n", find_maximum(arr));
	
	printf("minimum:\t%d\n", find_minimum(arr));	
	
}

/*
 * @fn 		print_array
 *
 * @brief	Given an array of data and a length, prints the array to the screen
 *
 * @param arr[]	The array to print
 */
void print_array(unsigned char arr[]){
	for(int i = 0; i < strlen(arr)/8; i++){
		for(int j = 0; j < strlen(arr)/5; j++){
		       printf("%3d  ", arr[8*i+j]);
		}
 		printf("\n");
	}
	printf("\n");
}

/* 
 * @fn 		find_median 
 *
 * @brief 	Given an array of data and a length, returns the median value
 *
 * @param arr[] The array to analyze
 *
 * @return median The median of the array
 *
 * @note This fuction needs the function sort_array to be executed before, in order to work properly
 */
unsigned char find_median(unsigned char arr[]){
	return arr[(strlen(arr)-1)/2];
}

/* 
 * @fn 		find_mean 
 *
 * @brief	Given an array , returns the mean value
 *
 * @param arr[] The array to analyze
 *
 * @return mean The mean value of the array
 */
unsigned char find_mean(unsigned char arr[]){
	unsigned int sum = 0;
	for(int i = 0; i < strlen(arr); i++){
		sum += arr[i];	
	}
	return (unsigned char)( sum / (float)strlen(arr) );
}

/* 
 * @fn 		find_maximum
 *
 * @brief	Given an array of data, returns the maximum value inside it.
 *
 * @param arr[] The array to analyze
 *
 * @return max The maximum value in the array
 *
 * @note This fuction needs the function sort_array to be executed before, in order to work properly
 */
unsigned char find_maximum(unsigned char arr[]){
	return arr[strlen(arr)-1];
}

/* 
 * @fn 		find_minimum
 *
 * @brief	Given an array of data, returns the minimum value inside it.
 *
 * @param arr[] The array to analyze
 *
 * @return min The minimum value in the array
 *
 * @note This fuction needs the function sort_array to be executed before, in order to work properly
 */
unsigned char find_minimum(unsigned char arr[]){
	return arr[0];
}

/* 
 * @fn 		sort_array
 *
 * @brief	Given an array of data and a length, sorts the array from largest to smallest. 
 				(Descending order, meaning that the 0th Element should be the largest value,
 				and the last element (n-1) should be the smallest value. )
 *
 * @param arr[]	The array to sort
 */
void sort_array(unsigned char arr[]){
	unsigned char tmp;
	for(int i = 0; i < strlen(arr); i++){
		for(int j = i; j < strlen(arr); j++){
			if(arr[j] < arr[i]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}
