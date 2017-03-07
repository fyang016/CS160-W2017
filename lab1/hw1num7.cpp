#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
using namespace std;

void end(void)
{
    printf("2");
}

int main()
{
    if (fork() == 0)
    {
        atexit(end);
    }
    
    if (fork() == 0)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }
    
    exit(0);
}