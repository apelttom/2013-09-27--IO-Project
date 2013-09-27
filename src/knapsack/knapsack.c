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

typedef struct struct3 {
    int name;
    int value;
    int copiesNum;
    // 0 for RED, 1 for GREEN
    short color;
} table;

void print_array(int a[], int num_elements){
   int i;
   for(i=0; i<num_elements; i++)
   {
     printf("%d ", a[i]);
   }
   printf("\n");
}
 
int randomizer(int min, int max){ 
    int x;
    srand (time(NULL)+rand());
    x = (int)(rand() % (min+1) + (max-min));
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
 * Expects values in this order:
 * Knapsack min capacity, Knapsack max capacity,
 * Min amount of objects, Max amount of objects,
 * Min cost of each object, Max cost of each object,
 * Min value of each object, Max value of each object
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
        generated.capacity = randomizer(input[0],input[1]);
        // printf("Randomized knapsack capacity: %d\n",generated.capacity);
    } else{ printf("Max is bigger than min! -- Knapsack capacity\n");}
    if(input[2]<=input[3]){
        generated.objectsNum = randomizer(input[2], input[3]);
        // printf("Randomized number of objects: %d\n", generated.objectsNum);
    } else{ printf("Max is bigger than min! -- Amount of objects\n");}
    for (i = 0; i < generated.objectsNum; ++i){
        generated.objects[i].name = i;
        generated.objects[i].cost = randomizer(input[4],input[5]);
        generated.objects[i].value = randomizer(input[6],input[7]);
        generated.objects[i].copies = randomizer(input[8],input[9]);
    }

    // FOR DEBUGGING-----------
    // for (i = 0; i < generated.objectsNum; ++i){
        // printf("%d. object name: x%d\n", i, generated.objects[i].name);
        // printf("%d. object cost: %d\n", i, generated.objects[i].cost);
        // printf("%d. object value: %d\n", i, generated.objects[i].value);
        // printf("%d. object copies: %d\n", i, generated.objects[i].copies);
    // }
    // ------------------------

    return generated;
}

void optimalAlgorithm(knapsack *sack, table t[50][50]){
    int i, j, k;
    // printf("Table rows: %d\n",sack -> capacity);
    // printf("Table columns: %d\n",sack -> objectsNum);
    for(i = 0 ; i <= sack -> capacity; ++i){
        for(j = 0 ; j < sack -> objectsNum; ++j){
            t[i][j].name = 0;
            t[i][j].value = 0;
            t[i][j].copiesNum = 0;
            t[i][j].color = 0;
        }
    }

    //  Algorithm has to go from begining of the COLUMN to the end of COLUMN
    //  That is why i and j are inverted
    for (j = 0; j < sack -> objectsNum; ++j){
        // int usedCopies = 0;
        int previousMax = 0;
        // Number of possibilities from which we are choosing max
        int Q = sack -> objects[j].copies;
        for (i = 0; i <= sack -> capacity; ++i){
            t[i][j].name = sack -> objects[j].name;
            // Used for storing values from which we will pick max
            int values[Q];
            int optimizedCol = (j-1) >= 0 ? (t[i][j-1].value) : 0;
            for (k = 1; k <= Q; ++k){
                values[k-1] = 0;
                int cost = (k*(sack -> objects[j].cost));
                if(i-cost >= 0){
                    int optimizedAfterCost = (j-1) >= 0 ? (t[i-cost][j-1].value) : 0;
                    values[k-1] = (k*(sack -> objects[j].value))+optimizedAfterCost;
                    if(k>t[i][j].copiesNum){t[i][j].copiesNum=k;}
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
                t[i][j].value = max;
                t[i][j].color = 1;

                // FOR DEBUGGING----------------
                // printf("Previous max: %d\n", previousMax);
                // printf("Maximum: %d\n", max);
                // -----------------------------

                previousMax = max;
            } else{
                if(optimizedCol >= previousMax){t[i][j].value = optimizedCol;}
                else{
                    t[i][j].value = previousMax;
                    t[i][j].color = 1;
                }
            }
        }
        // FOR DEBUGGING-------------
        // int m, n;
        // for(m = 0 ; m <= sack -> capacity; ++m){
        //     printf("%d.row\t", m);
        //     for(n = 0 ; n < sack -> objectsNum; ++n){
        //         printf("%d\t",t[m][n].value);
        //         if(n==sack -> objectsNum-1)
        //             printf("\n");
        //     }
        // }
        // printf("\n");
        // --------------------------
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
    table t[50][50];
    optimalAlgorithm(&sack, t);

    // FOR DEBUGGING-------------
    // int m,n;
    // for(m = 0 ; m <= sack.capacity; ++m){
    //         printf("%d.row\t", m);
    //         for(n = 0 ; n < sack.objectsNum; ++n){
    //             printf("%d\t",t[m][n].value);
    //             if(n==sack.objectsNum-1)
    //                 printf("\n");
    //         }
    //     }
    // printf("\n");
    // -------------------------

    return 0; 
}
