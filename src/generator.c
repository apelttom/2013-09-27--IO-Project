#include<stdio.h>
#include "header.h"

/*
 * Expects values in this order: Knapsack minimal capacity, Knapsack maximal capacity,
 * Minimal amount of objects, Maximal amount of objects, Minimal cost of each object, 
 * Maximal cost of each object, Minimal value of each object, Maximal value of each object
 * Minimal copies of each object, Maximal copies of each object and Number of examples.
 */

void generator(int spec[]){
	int i;
	for(i=0; i< ARG_LEN; i++){
		printf("Arguments: %d\n",spec[i]);
	}
	int knapSack = randomizer(spec[0],spec[1]);
	printf("Randomized knapsnack cpacity: %d\n",knapSack);
	
}

int randomizer(int min, int max){
	int x; 
	srand ( time(NULL) );
	do {
		x = rand();
	} while (x < min || x > max);
	return x;
}
