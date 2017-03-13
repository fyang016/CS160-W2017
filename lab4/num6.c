/* The goal of the following OpenMP program is to calculate π in parallel. Which
variables are shared and which variables are private in the parallel region of 
the program? Identify and fix all bugs in the program.
*/

#include <stdio.h>
#include "omp.h"
#define MAX_THREADS 4 
static long num_steps = 100000000; 
double step; 
int main () 
{
    int i, j; 
    double pi, full_sum = 0.0; 
    double start_time, run_time, x; 
    step = 1.0 / (double) num_steps; 
    for(j = 1; j <= MAX_THREADS; j++)
    {
        omp_set_num_threads(j); 
        full_sum = 0.0;
        start_time = omp_get_wtime();
        #pragma omp parallel private(x), private(i)
        // #pragma omp parallel
        {
            int id = omp_get_thread_num(); 
            int numthreads = omp_get_num_threads(); 
            double partial_sum = 0; 
            for (i = id; i < num_steps; i += numthreads) 
            {
                x = (i + 0.5) * step; 
                partial_sum = partial_sum + 4.0 / (1.0 + x * x); 
            }
            full_sum += partial_sum; 
        }
        pi = step * full_sum;
        run_time = omp_get_wtime() - start_time; 
        printf("\npi is %f in %f seconds %d threads \n", pi, run_time, j);
    } 
}