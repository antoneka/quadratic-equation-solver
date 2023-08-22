#include "input_output.h"
#include "quadratic_equation.h"
#include "common.h"

int main() 
{
    double a = 0, b = 0, c = 0;

    int end_of_input = getInput(&a, &b, &c);
    if (end_of_input == EOF) 
    {
        return 1;
    }

    double x1 = 0, x2 = 0;

    int root_count = solveQuadraticEquation(a, b, c, &x1, &x2);

    printAns(root_count, x1, x2);

    return 0;
}
