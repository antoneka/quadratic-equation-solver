#include "quadratic_equation.h"
#include "common.h"

int solveQuadraticEquation(const double a, const double b, const double c, double *x1, double *x2) 
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);

    int num_of_roots = 0;

    if (isEqual(a, 0)) 
    {
        num_of_roots = solveLinearEquation(b, c, x1);
    } 
    else 
    {
        double D = b * b - 4 * a * c;

        if (isEqual(D, 0)) 
        {
            if (isEqual(b, 0)) 
            {
                *x1 = *x2 = 0;
            } 
            else 
            {
                *x1 = *x2 = -b / (2 * a);
            }
            
            num_of_roots = ONE_ROOT;
        } 
        else if (D < 0) 
        {
            num_of_roots = ZERO_ROOTS;
        } 
        else 
        {
            if (isEqual(c, 0)) 
            {
                *x1 = 0;
                solveLinearEquation(a, b, x2);
            } 
            else 
            {
                double sqrt_of_discriminant = sqrt(D);
                *x1 = (-b + sqrt_of_discriminant) / (2 * a);
                *x2 = (-b - sqrt_of_discriminant) / (2 * a);
            }

            num_of_roots = TWO_ROOTS;
        }
    }

    return num_of_roots;
}

int solveLinearEquation(const double b, const double c, double *x) 
{
    int num_of_roots = 0;

    if (isEqual(b, 0)) 
    {
        num_of_roots = isEqual(c, 0) ? INF_ROOTS : ZERO_ROOTS;
    } 
    else 
    {
        if (isEqual(c, 0)) 
        {
            *x = 0;
        } 
        else 
        {
            *x = -c / b;
        }

        num_of_roots = ONE_ROOT;
    }

    return num_of_roots;
}
