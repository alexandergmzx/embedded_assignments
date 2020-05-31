/**
 * @file 	main.c
 *
 * @brief 	Main entry point to the C1M4 Assessment 
 *
 * @author	Alexander Gomez
 *
 * @date	2020-May-1
 */

#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "platform.h"
#include "memory.h"
#include "data.h"
#include "course1.h"

#define MAX_LENGTH (10)

int main(void) {
	#ifdef COURSE1
	course1();
	#endif /* COURSE1 */

	return 0;
}
