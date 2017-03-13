/*
Create a parallel version of the pi program using a parallel construct. Please use the OpenMP
runtime library routine omp_get_wtime() to measure the execution time of the computational section in the program.
*/

#include <stdio.h>
#include "omp.h"

static long num_steps[100000];
double step;
void main()
{
    omp_set_num_thread(4)
    
    int i;
    double x, pi, sum = 0.0;
    
    step = 1.0/(double) num_steps;
    
    
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;
    
    // Use %f for double kind of variable.
    printf("%f\n", pi);
}