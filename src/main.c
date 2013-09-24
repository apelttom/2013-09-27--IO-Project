#include<stdio.h>
#include "header.h"

int main(int argc, char *argv[]){
	int restr[ARG_LEN];
	int i;
	for(i=0; i<ARG_LEN; i++){
		restr[i] = atoi(argv[i+1]);
		printf("Arguments: %d\n",restr[i]);
	}
	generator(restr);
	return 0;
}
