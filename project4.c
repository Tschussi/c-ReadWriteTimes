/*
 ============================================================================
 Name        : project4.c
 Author      : Kevin Hames
 Copyright   : Copyright 2016
 Description : Calculates CPU and total time it takes to read and write a
 large file with varying buffer sizes
 ============================================================================
 */

#include "project4.h"

int main(void) {
	int i = 64; // starting buffer size

	// formating for time analysis
	printf("Buffer Size \t CPU Write Time \t CPU Read Time \t Total Write Time \t Total Read Time \n");

	// performs read and write analysis for a buffers up to 64kB
	while(i<=65536)
	{
		fileAnalysis(i);
		i = i*2; // increments buffer
	}
	return EXIT_SUCCESS;
}
