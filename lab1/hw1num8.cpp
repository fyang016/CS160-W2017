#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
using namespace std;

void foo(int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        fork();
    }
    printf("hello\n");
    exit(0);
}

int main()
{
    foo(1);
    return 0;
}