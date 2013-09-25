#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
 
#define ARG_LEN 4

typedef struct objArray {
    int name;
    int cost;
    int value;
    int copies;
} arr[50];

struct probExmpl {
    int knapSackCap;
    arr objects;
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
    struct probExmpl example;
    example.knapSackCap = 0;
    int objNum;
    
    if(input[0]<input[1]){
        example.knapSackCap = randomizer(input[0],input[1]);
        printf("Randomized knapsack cpacity: %d\n",example.knapSackCap);
    } else{ printf("Max is bigger than min! -- Knapsack capacity");}
    if(input[2]<input[3]){
        objNum = randomizer(input[2],input[3]);
        printf("Randomized number of objects: %d\n",objNum);
    } else{ printf("Max is bigger than min! -- Amount of objects");}
    
    struct objArray genObjts[objNum];
    for (i = 0; i < objNum; ++i){
        genObjts[i].name = i;
        genObjts[i].cost = randomizer(input[4],input[5]);
        genObjts[i].value = randomizer(input[6],input[7]);
        genObjts[i].copies = randomizer(input[8],input[9]);
    }
    for (i = 0; i < objNum; ++i){
        printf("%d. object name = x%d\n", i, genObjts[i].name);
        printf("%d. object cost = x%d\n", i, genObjts[i].cost);
        printf("%d. object value = x%d\n", i, genObjts[i].value);
        printf("%d. object copies = x%d\n", i, genObjts[i].copies);
    }
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