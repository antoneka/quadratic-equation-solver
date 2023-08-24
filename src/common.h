#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <getopt.h>
#include <ctype.h>

/// A set of possible numbers of roots
enum Roots 
{ 
    ZERO_ROOTS = 0, ///< The equation has zero roots
    ONE_ROOT   = 1, ///< The equation has one root
    TWO_ROOTS  = 2, ///< The equation has two roots
    INF_ROOTS  = -1 ///< The equation has an infinite number of roots
};

/// A structure that stores flags
typedef struct {
    unsigned int is_test:1; ///< --test flag mode
    unsigned int is_help:1; ///< --help flag mode
} Flags;

/// Flag mode constants
enum Flag_status
{
    IS_ENABLED  = 1, ///< The flag is enabled
    IS_DISABLED = 0, ///< The flag is disabled
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

/**
 * @brief A function that parses command line flags
 * @param[in] argc A number of command line arguments
 * @param[in] argv An array of command line arguments
 * @param[out] flags A structure of flags
 * @return flag_err: 0 if the input of the flags is correct otherwise 1
 */
int flagParser(int argc, char *argv[], Flags *flags);

/**
 * @brief A function that outputs the flag --help
 */
void helpingFunc();

#endif // COMMON_H
