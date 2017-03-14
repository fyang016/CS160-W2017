// slide 24: loop construct
// example in this slide is the "OpenMP parallel region and a worksharing 
// for construct"

#include <stdio.h>
#include "omp.h"
static long num_steps = 100000;
double step;
int main ()
{
    int i; double pi, sum = 0.0;
    double start_time, run_time;
    
    start_time = omp_get_wtime();
    step = 1.0/(double) num_steps;
    #pragma omp parallel for
    for (i = 0; i < num_steps; i++)
    {
        double x = (i + 0.5) * step;
        #pragma omp atomic
            sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;
    
    // Use %f for double kind of variable.
    run_time = omp_get_wtime() - start_time;
    printf("pi is %f in %f seconds\n", pi, run_time);
}