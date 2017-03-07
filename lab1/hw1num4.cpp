#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
using namespace std;

int main()
{
    int x = 3;
    
    if (fork() != 0)
    {
        printf("fork != 0\n");
        printf("x=%d\n", ++x);
    }
    else
    {
        printf("fork == 0\n");
    }
    
    printf("x=%d\n", --x);
    exit(0);
}