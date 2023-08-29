#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#define YELLOW_STRING(string) "\e[0;33m" string "\e[0;33m"
#define BLUE_STRING(string)   "\e[1;36m" string "\e[1;36m"
#define RED_STRING(string)    "\e[1;31m" string "\e[1;31m"

/// A structure that stores necessary variables for testingFunc
typedef struct 
{
    double a; ///< The first coefficient 
    double b; ///< The second coefficient
    double c; ///< Free term

    double x1_test; ///< The first reference root
    double x2_test; ///< The second reference root

    int root_count_test; ///< Reference number of roots
} Tests;

/// A structure that stores necessary variables for checkTest
typedef struct 
{
        double x1; ///< The resulting first root
        double x2; ///< The resulting second root
        int root_count; ///< The resulting number of roots

        double x1_test; ///< The first reference root
        double x2_test; ///< The second reference root
        int root_count_test; ///< Reference number of roots
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
