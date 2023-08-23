#include "common.h"

void clearBuffer() 
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int isEqual(const double num1, const double num2) 
{ 
    static const double eps = 1e-6;
    return fabs(num1 - num2) < eps; 
}

void help_func()
{
    printf("Quadratic equation solver version 1.0.0\n\n"
           "You can use the program in a number of ways:\n\n"
           "1) Use the flag -t or --test to test the function solveQuadraticEquation\n\n"
           "2) Use the flag -h or --help to see the instructions for the program\n");
}
