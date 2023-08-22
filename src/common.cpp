#include "common.h"

void clearBuffer() 
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int isEqual(const double num1, const double num2) 
{ 
    static const double eps = 1e-9;
    return fabs(num1 - num2) < eps; 
}

