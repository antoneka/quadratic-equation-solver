#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#define YELLOW_STRING(string) "\e[0;33m" string "\e[0;33m"
#define BLUE_STRING(string)   "\e[1;36m" string "\e[1;36m"
#define RED_STRING(string)    "\e[1;31m" string "\e[1;31m"

/// A structure that stores necessary variables for testing_func
typedef struct 
{
    double a;
    double b;
    double c;

    double x1_test;
    double x2_test;

    int root_count_test;
} Tests;

/// A structure that stores necessary variables for check_test
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
void testingFunc();

/**
 * @brief A function checking a single test
 * @param[in] A structure that stores the necessary variables for checking a single test
 * @return 1 if the test is passed otherwise 0
 */
int checkTest(Answers *answer);

#endif  // UNIT_TESTS_H
