#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

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

/** 
 * @brief A function testing the solveQuadraticEquation function
 */
void testing_func();

/**
 * @brief A function checking a single test
 * @param[in] A structure that stores the necessary variables for checking a single test
 * @return 1 if the test is passed otherwise 0
 */
int check_test(Answers *answer);

#endif  // UNIT_TESTS_H
