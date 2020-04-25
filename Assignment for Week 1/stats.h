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
 * @file stats.h 
 * @brief Definition for stats.c
 *
 * Statistical tools for dataset analysis
 *
 * @author alexandergmzx
 * @date 2020-Jan-6
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array The array of unsigned chars
 *
 */
void print_statistics(unsigned char arr[]);


/** 
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param array The array of unsigned chars
 *
 */
void print_array(unsigned char arr[]);


/** 
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array An array of unsigned chars
 *
 * @return median The median of the array
 */
unsigned char find_median(unsigned char arr[]);

/** 
 * @brief Given an array of data and a length, returns the mean
 *
 * @param array An array of unsigned chars
 *
 * @return mean The mean of the array
 */
unsigned char find_mean(unsigned char arr[]);

/** 
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param array An array of unsigned chars
 *
 * @return max The max of the array
 */
unsigned char find_maximum(unsigned char arr[]);

/** 
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param array An array of unsigned chars
 *
 * @return min The min of the array
 */
unsigned char find_minimum(unsigned char arr[]);

/** 
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param array An array of unsigned chars
 *
 */
void sort_array(unsigned char arr[]);


#endif /* __STATS_H__ */
