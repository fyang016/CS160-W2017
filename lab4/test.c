// slide 24: parallel construct
// example in this slide is the "OpenMP parallel region"

/* The goal of the following OpenMP program is to calculate π in parallel. Which
variables are shared and which variables are private in the parallel region of 
the program? Identify and fix all bugs in the program.
*/

#include <stdio.h>
#include "omp.h"
#define MAX_THREADS 4
static long num_steps = 100000;
double step;
int main ()
{
    
    int finalNum = 0;
    
    omp_set_num_threads(MAX_THREADS);
    
    
    // int i, j = 0;
    
    // j = 1;
    
    int i;
    
    #pragma omp parallel for
    
        
        for(i = 0; i < MAX_THREADS; i++)
        {
            // printf("i = %d, j = %d\n", i, j);
            // j = j + 2;
            int j = 1 + 2 * i;
            
            printf("i = %d, j = %d\n", i, j);
            
            
        }
    
    
    printf("j = %d\n", j);
}