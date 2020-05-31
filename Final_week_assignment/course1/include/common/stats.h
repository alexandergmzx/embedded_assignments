/***************************************
 * Copyright (C) 2017 by Alex Fosdick University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 ***************************************/
/**
 * @file	stats.h 
 *
 * @brief	Definition for stats.c
 *
 * Statistical tools for dataset analysis
 *
 * @author	alexandergmzx
 *
 * @date	2020-Jan-3
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @fn 		print_statistics
 *
 * @brief	Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param arr[] The array to analyze
 *
 * @note	This function needs the functions "sort_array", "find_minimum", "find_maximum", 
 				"find_mean", and "find_median" to work properly. 
 */
void print_statistics(unsigned char arr[], unsigned int length);


/**
 * @fn 		print_array
 *
 * @brief	Given an array of data and a length, prints the array to the screen
 *
 * @param arr[]	The array to print
 */
void print_array(unsigned char arr[], unsigned int length);


/** 
 * @fn 		find_median 
 *
 * @brief 	Given an array of data and a length, returns the median value
 *
 * @param arr[] The array to analyze
 *
 * @return median The median of the array
 */
unsigned char find_median(unsigned char arr[], unsigned int length);

/** 
 * @fn 		find_mean 
 *
 * @brief	Given an array , returns the mean value
 *
 * @param arr[] The array to analyze
 *
 * @return mean The mean value of the array
 */
unsigned char find_mean(unsigned char arr[], unsigned int length);

/** 
 * @fn 		find_maximum
 *
 * @brief	Given an array of data, returns the maximum value inside it.
 *
 * @param arr[] The array to analyze
 *
 * @return max The maximum value in the array
 */
unsigned char find_maximum(unsigned char arr[], unsigned int length);

/** 
 * @fn 		find_minimum
 *
 * @brief	Given an array of data, returns the minimum value inside it.
 *
 * @param arr[] The array to analyze
 *
 * @return min The minimum value in the array
 */
unsigned char find_minimum(unsigned char arr[], unsigned int length);

/** 
 * @fn 		sort_array
 *
 * @brief	Given an array of data and a length, sorts the array from largest to smallest. 
 				(Descending order, meaning that the 0th Element should be the largest value,
 				and the last element (n-1) should be the smallest value. )
 *
 * @param arr[]	The array to sort
 */
void sort_array(unsigned char arr[], unsigned int length);


#endif /* __STATS_H__ */
