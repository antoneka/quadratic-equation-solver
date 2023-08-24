#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "unit_tests.h"
#include "common.h"

const int MAXSIZE = 512;

struct TestArgs
{
    Tests * test_arr;
    size_t test_arr_size;
    size_t test_count;
};

Tests* fileParser(FILE *streamin, size_t *test_count);
int getParam(char line[], struct TestArgs *test);

#endif // FILE_PARSER_H
