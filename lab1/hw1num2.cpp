#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
using namespace std;

int main()
{
    int i;
    
    for (i = 0; i < 2; i++)
    {
        printf("about to fork\n");
        fork();
    }
    printf("hello\n");
    exit(0);
}