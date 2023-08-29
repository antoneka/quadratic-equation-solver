#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string.h>
#include "unit_tests.h"
#include "common.h"

const int MAXSIZE = 512; ///< Maximum size of one line in the test file

/// A structure that stores an array of tests and information about it
struct TestArgs
{
    Tests * test_arr; ///< An array of tests
    size_t test_arr_size; ///< A capacity of the array
    size_t test_count; ///< A length of the array
};

/**
 * @brief A functon that parsers the test file
 * @param[in] streaming A stream reading the test file
 * @param[out] test_count A number of tests in the test file
 * @return An array of test structures
 */
Tests* fileParser(FILE *streamin, size_t *test_count);

/**
 * @brief A functon that receives arguments from the current test
 * @param[in] line An array storing the current test
 * @param[out] test A pointer to the structure that stores information about tests
 * @return true if the input of the tests in the file was correct otherwise false
 */
int getParam(char line[], struct TestArgs *test);

#endif // FILE_PARSER_H
