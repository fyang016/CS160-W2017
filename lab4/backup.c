#include <iostream>
#include <stdio.h>
#include "omp.h"

using namespace std;

#define NT 4
static long num_steps = 100000;
double step;

int main () {
    double s[NT];
    step = 1.0/(double) num_steps;
    
    omp_set_num_threads(NT);
    double st = omp_get_wtime();
    #pragma omp parallel
    {
        double x = 0.0;
        int id = omp_get_thread_num();
        s[id] = 0.0;
        for (int i = id; i < num_steps; i += NT) { 
            x = (i+0.5)*step;
            s[id] += 4.0/(1.0+x*x); 
        }
    }
    double rt = omp_get_wtime() - st;
    
    cout << "Time: " << rt << endl;
    double pi = 0.0;
    for (int i = 0; i < NT ; i ++) {
        pi += (s[i] * step);
    }
    printf ("pi is %f \n", pi) ;
}