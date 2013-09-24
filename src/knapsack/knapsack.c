#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
 
#define ARG_LEN 4

typedef struct objects1 {
    int name;
    int cost;
    int value;
    int copies;
} array1[50];

struct example {
    int knapSackCap;
    array1 objets;
};
 
int randomizer(int min, int max){ 
    int x;  
    srand ( time(NULL) ); 
    do { 
        x = rand(); 
    } while (x < min || x > max); 
    return x; 
} 
 
 /*
 * Expects values in this order: Knapsack minimal capacity, Knapsack maximal capacity,
 * Minimal amount of objects, Maximal amount of objects, Minimal cost of each object, 
 * Maximal cost of each object, Minimal value of each object, Maximal value of each object
 * Minimal copies of each object, Maximal copies of each object and Number of examples.
 */
void generator(int input[]){ 
    int i; 
    // for(i=0; i< ARG_LEN; i++){ 
    //     printf("Generator input: %d\n",input[i]); 
    // }
    int capacity;
    int objNum;
    if(input[0]<input[1]){
        capacity = randomizer(input[0],input[1]);
        printf("Randomized knapsack cpacity: %d\n",capacity);
    } else{ printf("Max is bigger than min! -- Knapsack capacity");}
    if(input[2]<input[3]){
        objNum = randomizer(input[2],input[3]);
        printf("Randomized number of objects: %d\n",objNum);
    } else{ printf("Max is bigger than min! -- Amount of objects");}

} 
 
 
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