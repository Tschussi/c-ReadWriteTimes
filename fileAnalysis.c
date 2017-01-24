/*
 * fileAnalysis.c
 *
 *  Created on: Nov 21, 2016
 *      Author: Kevin Hames
 *      Description: Given a buffer size, prints the CPU and total time to write and read a 2GB file
 */

#include "project4.h"

void fileAnalysis(int bufferSize) {

	// Variable Declarations
	clock_t startTime, endTime;
	time_t sTime, eTime;
	double CPUreadTime, CPUwriteTime;
	int TOTreadTime, TOTwriteTime;
	char buffer[bufferSize];
	int loops = FILESIZE / bufferSize;
	FILE* fl = fopen("testFile.txt","w");

	// Writes a 2GB file, recording total & CPU start and end times
	sTime = time(NULL);
	startTime = clock();
	for(int i = 0; i < loops; i++)
		fwrite(buffer,bufferSize,1,fl);
	endTime = clock();
	eTime = time(NULL);

	// calculate CPU time and total time for write
	CPUwriteTime = (double) (endTime - startTime) / CLOCKS_PER_SEC;
	TOTwriteTime = (int) (eTime - sTime);

	// Reads previosly written file, recording total & CPU start and end times
	sTime = time(NULL);
	startTime = clock();
	for(int i = 0; i < loops; i++)
		fread(buffer,bufferSize,1,fl);
	endTime = clock();
	eTime = time(NULL);

	// calculate CPU time and total time for read
	CPUreadTime = (double) (endTime - startTime) / CLOCKS_PER_SEC;
	TOTreadTime = (int) (eTime - sTime);

	fclose(fl);
	// prints the CPU and total times for write and read as well as buffer size
	printf("%i\t\t %fs\t\t %fs\t\t %is\t\t\t %is\t\t \n", bufferSize, CPUwriteTime, CPUreadTime, TOTwriteTime, TOTreadTime);
}
