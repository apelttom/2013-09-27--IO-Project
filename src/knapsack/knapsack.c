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
    int capacity;
    int objectsNum;
    arr1 objects;
} knapsack;
 
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
 * Minimal copies of each object and Maximal copies of each object.
 *
 * Returns a generated structure knapsack, which represents a knapsack problem
 */
knapsack generator(int input[]){ 
    int i;
    knapsack generated;
    // for(i=0; i <= ARG_LEN-1; i++){ 
    //     printf("Generator input: %d\n",input[i]);
    // }
    
    if(input[0]<input[1]){
        generated.capacity = randomizer(input[0],input[1]);
        printf("Randomized knapsack capacity: %d\n",generated.capacity);
    } else{ printf("Max is bigger than min! -- Knapsack capacity");}
    if(input[2]<input[3]){
        generated.objectsNum = randomizer(input[2], input[3]);
        printf("Randomized number of objects: %d\n", generated.objectsNum);
    } else{ printf("Max is bigger than min! -- Amount of objects");}
    for (i = 0; i < generated.objectsNum; ++i){
        generated.objects[i].name = i;
        generated.objects[i].cost = randomizer(input[4],input[5]);
        generated.objects[i].value = randomizer(input[6],input[7]);
        generated.objects[i].copies = randomizer(input[8],input[9]);
    }
    for (i = 0; i < generated.objectsNum; ++i){
        printf("%d. object name = x%d\n", i, generated.objects[i].name);
        printf("%d. object cost =%d\n", i, generated.objects[i].cost);
        printf("%d. object value =%d\n", i, generated.objects[i].value);
        printf("%d. object copies =%d\n", i, generated.objects[i].copies);
    }
    return generated;
}

void optimalAlgorithm(knapsack *sack){
    printf("Table rows: %d\n",sack->capacity);
    printf("Table columns: %d\n",sack->objectsNum);
    int i, j;
    int table[sack->capacity][sack->objectsNum];
    printf("\nPrinted table:\n");
    for(i=0;i<sack->capacity;++i)
        for(j=0;j<sack->objectsNum;++j){
            table[i][j] = 0;
            //  Print table
            printf("%d\t",table[i][j]);
            if(j==sack->objectsNum-1)
                printf("\n");
        }
}


 int main(int argc, char *argv[]){ 
    int restr[ARG_LEN]; 
    int i; 
    for(i=0; i <= ARG_LEN-1; i++){
        restr[i] = atoi(argv[i+1]); 
        // printf("Arguments: %d\n",restr[i]); 
    } 
    knapsack sack = generator(restr);
    printf("Number of objects in knapsack: %d\n",sack.objectsNum); 
    optimalAlgorithm(&sack);
    return 0; 
}