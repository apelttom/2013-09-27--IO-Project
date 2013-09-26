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


void print_array(int a[], int num_elements){
   int i;
   for(i=0; i<num_elements; i++)
   {
     printf("%d ", a[i]);
   }
   printf("\n");
}
 
int randomizer(int min, int max, int seed){ 
    int x;
    printf("Generation with seed: %d\n", seed);
    srand (time(NULL)+seed); 
    do {
        x = rand(); 
    } while (x < min || x > max); 
    return x; 
}

int max_array(int a[], int num_elements){
   int i, max=-32000;
   for (i=0; i<num_elements; i++){
     if (a[i]>max){
        max=a[i];
     }
   }
   return(max);
}
 
 /*
 * Expects values in this order: Knapsack min capacity, Knapsack max capacity,
 * Min amount of objects, Max amount of objects, Min cost of each object, 
 * Max cost of each object, Min value of each object, Max value of each object
 * Min copies of each object and Max copies of each object.
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
        generated.capacity = randomizer(input[0],input[1], input[1]-input[0]);
        printf("Randomized knapsack capacity: %d\n",generated.capacity);
    } else{ printf("Max is bigger than min! -- Knapsack capacity\n");}
    if(input[2]<input[3]){
        generated.objectsNum = randomizer(input[2], input[3], input[2]-input[3]);
        printf("Randomized number of objects: %d\n", generated.objectsNum);
    } else{ printf("Max is bigger than min! -- Amount of objects\n");}
    for (i = 0; i < generated.objectsNum; ++i){
        generated.objects[i].name = i;
        generated.objects[i].cost = randomizer(input[4],input[5], i+5);
        generated.objects[i].value = randomizer(input[6],input[7], i+8);
        generated.objects[i].copies = randomizer(input[8],input[9], i+13);
    }
    for (i = 0; i < generated.objectsNum; ++i){
        printf("%d. object name: x%d\n", i, generated.objects[i].name);
        printf("%d. object cost: %d\n", i, generated.objects[i].cost);
        printf("%d. object value: %d\n", i, generated.objects[i].value);
        printf("%d. object copies: %d\n", i, generated.objects[i].copies);
    }
    return generated;
}

void optimalAlgorithm(knapsack *sack){
    int i, j, k;
    int table[sack -> capacity][sack -> objectsNum];
    // printf("Table rows: %d\n",sack -> capacity);
    // printf("Table columns: %d\n",sack -> objectsNum);
    printf("\nTable inicialization:\n");
    for(i = 0 ; i < sack -> capacity; ++i)
        for(j = 0 ; j < sack -> objectsNum; ++j){
            table[i][j] = 0;
            //  Print table
            printf("%d\t",table[i][j]);
            if(j==sack -> objectsNum-1)
                printf("\n");
        }

    // for (j = 0; j < sack -> objectsNum; ++j)
    //     for (i = 0; i < sack -> capacity; ++i){
    //         int values[sack -> objects[i].copies+1];
    //         int prevColumn = (j-1) >= 0 ? (j-1) : 0;
    //         values[0] = table[i][prevColumn];
    //         for (k = 1; k < sack -> objects[i].copies; ++k){
    //             values[k] = k*sack -> objects[i].value+table[i-k*sack->objects[i].cost][j-1];
    //         }
    //         // table[i][j] = max
    //     }
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