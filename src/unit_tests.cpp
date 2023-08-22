#include "quadratic_equation.h"
#include "common.h"

typedef struct 
{
    double a;
    double b;
    double c;

    double x1_test;
    double x2_test;

    int root_count_test;
} Tests;

typedef struct 
{
        double x1;
        double x2;
        int root_count;

        double x1_test;
        double x2_test;
        int root_count_test;
} Answers;
 
int is_equal_to_the_first_or_the_second_num(double num, double num1, double num2);
int testing_func(Answers *answer);

int main() 
{
    Tests test[] = 
    {
        {0   , 0   , 0   , NAN      , NAN     , INF_ROOTS },
        {0   , 5   , 0   , 0        , NAN     , ONE_ROOT  },
        {0   , 0   , 5   , NAN      , NAN     , ZERO_ROOTS},
        {4   , 12  , 9   , -1.5     , -1.5    , ONE_ROOT  },
        {-3.5, 15.6, 8.75, -0.503924, 4.961067, TWO_ROOTS },
    };
    
    for (int test_num = 0; test_num < sizeof(test) / sizeof(test[0]); test_num++) 
    {
        double a = test[test_num].a;
        double b = test[test_num].b;
        double c = test[test_num].c;

        double x1_test = test[test_num].x1_test;
        double x2_test = test[test_num].x2_test;

        int root_count_test = test[test_num].root_count_test;

        double x1 = NAN, x2 = NAN;
        int root_count = solveQuadraticEquation(a, b, c, &x1, &x2);

        Answers answer = {x1, x2, root_count, x1_test, x2_test, root_count_test};

        if (testing_func(&answer)) 
        {
            printf("Test №%d passed\n\n", test_num + 1);
        }
        else 
        {
            printf("Test №%d failed:\n", test_num + 1);

            if (root_count != root_count_test)
                printf("Expected number of roots: %d\n"
                        "The resulting number of roots: %d\n", root_count, root_count_test);
            else 
                printf("Expected roots: x1 = %lf, x2 = %lf\n"
                       "The resulting roots: x1 = %lf, x2 = %lf\n\n", x1_test, x2_test, x1, x2);
        }
    }

    return 0;
}

int testing_func(Answers* answer)
{
    if (answer->root_count != answer->root_count_test) 
    {
        return 0;
    } 
    else
    {
        if (answer->root_count == ZERO_ROOTS)
        {
            return isnan(answer->x1) && isnan(answer->x2);
        }
        else if (answer->root_count == ONE_ROOT)   
        { //TODO: creater auxilarry func
            return (is_equal_to_the_first_or_the_second_num(answer->x1, answer->x1_test, answer->x2_test) && 
                    isnan(answer->x2))                                                                
                    || 
                    (isEqual(answer->x1, answer->x2)                                               && 
                    (is_equal_to_the_first_or_the_second_num(answer->x1, answer->x1_test, answer->x2_test)));
        }
        else if (answer->root_count == TWO_ROOTS)
        {
            return (isEqual(answer->x1, answer->x1_test) && isEqual(answer->x2, answer->x2_test)) || 
                   (isEqual(answer->x1, answer->x2_test) && isEqual(answer->x2, answer->x1_test));
        }
        else // if (root_count == INF_ROOTS)
        {
            return isnan(answer->x1) && isnan(answer->x2);
        }
    }
}

int is_equal_to_the_first_or_the_second_num(double num, double num1, double num2)
{
    return isEqual(num, num1) || isEqual(num, num2);
}
