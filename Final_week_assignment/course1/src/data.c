/**
 * @file	data.c 
 *
 * @brief	Functions to convert data to specific formats
 *
 * This file should do some very basic data manipulation.
 *
 * @author	alexandergmzx
 *
 * @date	2020-Apr-29
 * 
 * MIT License
 *
 * Copyright (c) 2020 J. Alexander Gómez G.
 * 
 */
#include <stdint.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

		uint8_t tmp[16];
		uint8_t * tptr = tmp;
		uint8_t reminder;
		int32_t value;
		uint8_t length;

		uint8_t sign = (data < 0);

		if(sign){
				value = -data;
		}
		else{
				value = data;
		}

		while (value || tptr == tmp){
				reminder = value % base;
				value = value/base;

				if (reminder < 10){
						*tptr++ = reminder + '0';
				}
				else{
						*tptr++ = reminder + 'a' - 10;
				}
		}

		length = tptr - tmp;

		if(sign){
				*ptr++ = '-';
				length++;
		}

		while(tptr > tmp){
				*ptr++ = *--tptr;
		}

		return length;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

		int32_t result = 0;
		int8_t sign = 1;
		uint8_t index = 0;

		if (ptr[0] == '-'){
				sign = -1;
				index++;
		}
		while(index < digits){
				result = result*base + ptr[index] - '0';
				/* +'0' to make a conversion to char */
				index++;
		}
		return sign*result;
}

