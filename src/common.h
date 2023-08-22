#pragma once

#include <stdio.h>
#include <math.h>
#include <assert.h>

enum Roots 
{ 
    ZERO_ROOTS = 0, 
    ONE_ROOT = 1, 
    TWO_ROOTS = 2, 
    INF_ROOTS = -1
};

void clearBuffer();
int isEqual(double num1, double num2);
