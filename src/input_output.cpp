#include "input_output.h"
#include "common.h"

int getInput(double *a, double *b, double *c) 
{
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    printf("Enter the coefficients a, b, c\n"
           "The coefficients must be real: ");

    int number_of_initialized_variables = 0;
    const int expected_initialized_variables = 4;

    while (true) 
    {
        char enter_symbol = 0;
        number_of_initialized_variables = scanf("%lf%lf%lf%c", a, b, c, &enter_symbol);

        if (checkInput(number_of_initialized_variables, expected_initialized_variables, enter_symbol))
        {
            break;
        }

        printErrorInput();
        clearBuffer();
    }

    return number_of_initialized_variables;
}

int checkInput(const int variables_count, const int expected_amount_of_vars, const char symbol_entry)
{
    if (variables_count == EOF || (variables_count == expected_amount_of_vars && symbol_entry == '\n'))
        return 1;
    else if (variables_count != expected_amount_of_vars || !isspace(symbol_entry))
        return 0;
    else
    {
        int c = 0;
        while ((c = getchar()) != '\n') 
        {
            if (!isspace(c))
                return 0;
        }
        return 1;
    }
}

void printErrorInput() 
{
    printf("\nIncorrect data entry: a, b and c must be real numbers!\n"
            "Try again: ");
}

void printAns(const int root_count, const double x1, const double x2) 
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
            assert(0 && "Invalid root count");
    }
}
