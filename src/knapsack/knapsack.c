#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
 
#define ARG_LEN 10

typedef struct struct1 {
    int name;
    int cost;
    int value;
    int copies;
} arr1[50];

typedef struct struct2 {
    int knapSackCap;
    arr1 objects;
} example;
 
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
example generator(int input[]){ 
    int i; 
    // for(i=0; i <= ARG_LEN-1; i++){ 
    //     printf("Generator input: %d\n",input[i]);
    // }
    
    example generated;

    int objNum;
    
    if(input[0]<input[1]){
        generated.knapSackCap = randomizer(input[0],input[1]);
        printf("Randomized knapsack cpacity: %d\n",generated.knapSackCap);
    } else{ printf("Max is bigger than min! -- Knapsack capacity");}
    if(input[2]<input[3]){
        objNum = randomizer(input[2],input[3]);
        printf("Randomized number of objects: %d\n",objNum);
    } else{ printf("Max is bigger than min! -- Amount of objects");}
    for (i = 0; i < objNum; ++i){
        generated.objects[i].name = i;
        generated.objects[i].cost = randomizer(input[4],input[5]);
        generated.objects[i].value = randomizer(input[6],input[7]);
        generated.objects[i].copies = randomizer(input[8],input[9]);
    }
    for (i = 0; i < objNum; ++i){
        printf("%d. object name = x%d\n", i, generated.objects[i].name);
        printf("%d. object cost =%d\n", i, generated.objects[i].cost);
        printf("%d. object value =%d\n", i, generated.objects[i].value);
        printf("%d. object copies =%d\n", i, generated.objects[i].copies);
    }
    return generated;
} 
 
 
 int main(int argc, char *argv[]){ 
    int restr[ARG_LEN]; 
    int i; 
    for(i=0; i <= ARG_LEN-1; i++){
        restr[i] = atoi(argv[i+1]); 
        printf("Arguments: %d\n",restr[i]); 
    } 
    generator(restr); 
    return 0; 
}