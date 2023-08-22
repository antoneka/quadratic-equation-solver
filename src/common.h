#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

/// The set of possible numbers of roots
enum Roots 
{ 
    ZERO_ROOTS = 0, ///< The equation has zero roots
    ONE_ROOT   = 1, ///< The equation has one root
    TWO_ROOTS  = 2, ///< The equation has two roots
    INF_ROOTS  = -1 ///< The equation has an infinite number of roots
};

/**
 * @brief A function that clears the input buffer
 */
void clearBuffer();

/**
 * @brief A function that compares two numberes
 * @param[in] num1 The first number
 * @param[in] num2 The second number
 * @return true if num1 == num2 otherwise false
 */
int isEqual(const double num1, const double num2);

#endif // COMMON_H
