/**
 * This file contains a broken program to be debugged with GDB.
 * This program reads a line from stdin, generates random numbers
 *			  that is then used to pull characters from random
 *			  parts of the read string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "message.h"
#include <time.h>


int main(int arg, char** argv){
	char* string = NULL;
	int rand_array[10]; // 10 random numbers
	int i, n;
	int length;
	size_t j=0;
        
        srand(time(NULL));

	printf("Enter a line: ");
	n = getline(&string, &j, stdin)-1;
	printf("You entered the %d character line: %s", n, string);
	length = n;
	// generate an array of random indexes
	for(i=0; i<length; i++)	{
		rand_array[i] = rand() % (n-1);
	}
	
	printf("The randomized string is \n");
	for(i=0; i<length; i++){
		putchar(string[rand_array[i]]);
	}
	printf("\n");

	return 0;
}
