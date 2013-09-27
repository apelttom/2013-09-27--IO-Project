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
    // printf("Generation with seed: %d\n", seed);
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
    
    if(input[0]<=input[1]){
        generated.capacity = randomizer(input[0],input[1], time(NULL));
        printf("Randomized knapsack capacity: %d\n",generated.capacity);
    } else{ printf("Max is bigger than min! -- Knapsack capacity\n");}
    if(input[2]<=input[3]){
        generated.objectsNum = randomizer(input[2], input[3], time(NULL));
        printf("Randomized number of objects: %d\n", generated.objectsNum);
    } else{ printf("Max is bigger than min! -- Amount of objects\n");}
    for (i = 0; i < generated.objectsNum; ++i){
        generated.objects[i].name = i;
        generated.objects[i].cost = randomizer(input[4],input[5], i);
        generated.objects[i].value = randomizer(input[6],input[7], i/2);
        generated.objects[i].copies = randomizer(input[8],input[9], i*3);
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
    int i, j, k, m, n;
    int table[(sack -> capacity)+1][sack -> objectsNum];
    // printf("Table rows: %d\n",sack -> capacity);
    // printf("Table columns: %d\n",sack -> objectsNum);
    printf("\nTable inicialization:\n");
    for(i = 0 ; i <= sack -> capacity; ++i){
        printf("%d.row\t", i);
        for(j = 0 ; j < sack -> objectsNum; ++j){
            table[i][j] = 0;
            //  Print table
            printf("%d\t",table[i][j]);
            if(j==sack -> objectsNum-1)
                printf("\n");
        }
    }
    printf("\n");

    //  Algorithm has to go from begining of the COLUMN to the end of COLUMN
    //  That is why i and j are inverted
    //  WORKING RIGHT BUT DOESN REMEMBER HOW MANY COPIES WE HAVE USED SO FAR
    for (j = 0; j < sack -> objectsNum; ++j){
        // int usedCopies = 0;
        int previousMax = 0;
        // How many items from which we will be choosing max?
        int Q = sack -> objects[j].copies;
        for (i = 0; i <= sack -> capacity; ++i){
            // Used for storing values from which we will pick max
            int values[Q];
            int optimizedCol = (j-1) >= 0 ? (table[i][j-1]) : 0;
            for (k = 1; k <= Q; ++k){
                values[k-1] = 0;
                int cost = (k*(sack -> objects[j].cost));
                if(i-cost >= 0){
                    int optimizedAfterCost = (j-1) >= 0 ? (table[i-cost][j-1]) : 0;
                    values[k-1] = (k*(sack -> objects[j].value))+optimizedAfterCost;
                    // printf("In %d row %d copies of object x%d costs %d, gives us value: %d and with previous optimized column earn us %d dollars\n", i, k, sack -> objects[j].name, cost, k*(sack -> objects[j].value), values[k-1]);
                }
            }
            // FOR DEBUGGING-------------------
            // printf("Value from optimized column\tValues counted using x%d:\n", sack -> objects[j].name);
            // printf("%d\t\t\t\t", optimizedCol);
            // print_array(values, Q);
            // printf("\n");
            // ---------------------------------
            int max = max_array(values, Q);
            if(max > optimizedCol && max > previousMax){
                table[i][j] = max;
                // FOR DEBUGGING----------------
                // printf("Previous max: %d\n", previousMax);
                // printf("Maximum: %d\n", max);
                // -----------------------------
                previousMax = max;
            } else{
                if(optimizedCol >= previousMax){table[i][j] = optimizedCol;}
                else{table[i][j] = previousMax;}
            }
        }
        for(m = 0 ; m <= sack -> capacity; ++m){
            printf("%d.row\t", m);
            for(n = 0 ; n < sack -> objectsNum; ++n){
                //  Print table
                printf("%d\t",table[m][n]);
                if(n==sack -> objectsNum-1)
                    printf("\n");
            }
        }
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