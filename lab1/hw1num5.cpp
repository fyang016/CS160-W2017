#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
using namespace std;

void doit()
{
    if (fork() == 0)
    {
        fork();
        printf("hello\n");
        return;
    }
    return;
}

int main()
{
    doit();
    printf("hello\n");
    exit(0);
}