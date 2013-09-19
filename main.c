/* Simple Hello World program */

#include<stdio.h>

main(int argc, char *argv[]){
int restr[11];
int i;
for(i=0; i<11; i++){
	restr[i] = atoi(argv[i+1]);
	printf("Arguments: %d\n",restr[i]);
}
return 0;
}
