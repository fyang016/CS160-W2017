#include <stdio.h>
#include "omp.h"

int main()
{
    
    omp_set_num_threads(4);
    
    #pragma omp parallel
    {
        printf("Hello!\n");
    }
    
    printf("all done\n");
    
    return 0;
}