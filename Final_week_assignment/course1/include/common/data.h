/**
 * @file	data.h 
 *
 * @brief	Declarations of functions that convert data to specific formats
 *
 * This file should do some very basic data manipulation.
 *
 * @author	alexandergmzx
 *
 * @date	2020-Apr-29
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
* @brief 			Integer to ASCII converter
*
* This function converts a standard integer type into an ASCII string.
*
* @param data		The number you wish to convert
* @param ptr		Pointer to data array where converted character string will be placed
* @param base		Support bases 2 to 16 by specifying the integer value
*
* @return			Length of the converted data (including a negative sign)
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief 			ASCII to Integer converter
 *
 * This function converts an ASCII represented string into an integer type.
 *
 * @param ptr		Pointer to the string you wish to convert
 * @param digits	Number of digits
 * @param base		Support bases 2 to 16 by specifying the integer value
 *
 * @return			Converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */