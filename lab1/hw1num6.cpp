#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <iostream>
using namespace std;

int counter = 1;

int main()
{
    if (fork() == 0)
    {
        counter--;
        exit(0);
    }
    else
    {
        wait(0);
        printf("counter = %d\n", ++counter);
    }
    exit(0);
}