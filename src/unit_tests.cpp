#include "quadratic_equation.h"
#include "common.h"
#include "unit_tests.h"
#include "file_parser.h"

void testingFunc()
{
    /*
    Tests test[] = 
    {
        {0   , 0   , 0   , NAN      , NAN     , INF_ROOTS },
        {0   , 5   , 0   , 0        , NAN     , ONE_ROOT  },
        {0   , 0   , 5   , NAN      , NAN     , ZERO_ROOTS},
        {4   , 12  , 9   , -1.5     , -1.5    , ONE_ROOT  },
        {-3.5, 15.6, 8.75, -0.503924, 4.961067, TWO_ROOTS },
        {0   , 5   , -15 , 3        , 2       , TWO_ROOTS },
        {15  , 5   , -12 , 9        , 8       , TWO_ROOTS },
    };
    
    size_t test_size = sizeof(test) / sizeof(test[0]);
    */

    FILE *test_file = fopen("test_file.txt", "r");

    if (!test_file) 
    {
        fprintf(stderr, "Test file doesn`t exist\n");
        return;
    }

    size_t test_size = 0;
    Tests *test = fileParser(test_file, &test_size);

    if (!test)
    {
        fprintf(stderr, "Test input error\n");
        return;
    }

    for (size_t test_num = 0; test_num < test_size; test_num++) 
    {
        double x1 = NAN, x2 = NAN;
        int root_count = solveQuadraticEquation(test[test_num].a, test[test_num].b, 
                                                test[test_num].c, &x1, &x2);

        Answers answer = {x1, x2, root_count, test[test_num].x1_test, test[test_num].x2_test, 
                          test[test_num].root_count_test};

        if (checkTest(&answer)) 
        {
            printf(YELLOW_STRING("Test №%zu ") 
                   BLUE_STRING("is passed\n\n"), test_num + 1);
        }
        else 
        {
            printf(YELLOW_STRING("Test №%zu ") 
                   RED_STRING("is failed:\n"), test_num + 1);

            if (root_count != test[test_num].root_count_test)
                printf(YELLOW_STRING("Expected number of roots: ") 
                       BLUE_STRING("%d\n")
                       YELLOW_STRING("The resulting number of roots: ") 
                       RED_STRING("%d\n\n"), test[test_num].root_count_test, root_count);
            else 
                printf(YELLOW_STRING("Expected roots: ") 
                       BLUE_STRING("x1 = %lf, x2 = %lf\n")
                       YELLOW_STRING("The resulting roots: ") 
                       RED_STRING("x1 = %lf, x2 = %lf\n\n"), test[test_num].x1_test, 
                                                             test[test_num].x2_test, x1, x2);
        }
    }

    free(test);
    fclose(test_file);
}

int checkTest(Answers* answer)
{
    if (answer->root_count != answer->root_count_test) 
    {
        return 0;
    } 
    else
    {
        if (answer->root_count == ONE_ROOT)   
        { 
            return (isEqual(answer->x1, answer->x1_test) && isnan(answer->x2) && isnan(answer->x2_test))                                                                
                    || 
                    (isEqual(answer->x1, answer->x2) && 
                    (isEqual(answer->x1, answer->x1_test)) && isEqual(answer->x1, answer->x2_test));
        }
        else if (answer->root_count == TWO_ROOTS)
        {
            return (isEqual(answer->x1, answer->x1_test) && isEqual(answer->x2, answer->x2_test)) || 
                   (isEqual(answer->x1, answer->x2_test) && isEqual(answer->x2, answer->x1_test));
        }
        else // if (answer->root_count == ZERO_ROOTS || answer->root_count == INF_ROOTS)
        {
            return isnan(answer->x1) && isnan(answer->x2);
        }
    }
}
