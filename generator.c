#include<stdio.h>
#include "header.h"

void generator(int spec[]){
	int i;
	for(i=0; i< ARG_LEN; i++){
		printf("Arguments: %d\n",spec[i]);
	}
}
