#include "input_output.h"
#include "common.h"

int getInput(double *a, double *b, double *c) 
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    printf("Enter the coefficients a, b, c\n"
            "The coefficients must be real: ");

    int number_of_initialized_variables = scanf("%lf%lf%lf", a, b, c);

    while (true) 
    {
        if (number_of_initialized_variables == 3 || number_of_initialized_variables == EOF) 
        {
            break;
        }

        printErrorInput();
        clearBuffer();
        number_of_initialized_variables = scanf("%lf%lf%lf", a, b, c);
    }

    return number_of_initialized_variables;
}

void printErrorInput() 
{
    printf("\nIncorrect data entry: a, b and c must be real numbers!\n"
            "Try again: ");
}

void printAns(int root_count, double x1, double x2) 
{
    switch (root_count) 
    {
        case ZERO_ROOTS:
            printf("\nThe equation has no roots\n");
            break;

        case ONE_ROOT:
            printf("\nThe answer: x1 = x2 = %.6lf\n", x1);
            break;

        case TWO_ROOTS:
            printf("\nThe answer: x1 = %.6lf, x2 = %.6lf\n", x1, x2);
            break;

        case INF_ROOTS:
            printf("\nThe equation has an infinite number of roots\n");
            break;

        default:
            assert(0);
    }
}
