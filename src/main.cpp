#include "input_output.h"
#include "quadratic_equation.h"
#include "common.h"
#include "unit_tests.h"

int main(int argc, char *argv[]) 
{
    Flags flags = 
    {
        .is_test = IS_DISABLED,
        .is_help = IS_DISABLED,
    };

    int flag_err = flagParser(argc, argv, &flags);
    
    if (flag_err)
        return 1;

    if (flags.is_test)
        testingFunc();
    else if (flags.is_help)
        helpingFunc();
    else 
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
    }

    return 0;
}

