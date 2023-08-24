#include "file_parser.h"

Tests* fileParser(FILE *test_file, size_t *test_count)
{
    assert(test_file != NULL && "File doesn`t exist");
   
    struct TestArgs test = {};

    test.test_arr_size = 10;
    test.test_count = 0;
    test.test_arr = (Tests*)calloc(sizeof(Tests), test.test_arr_size);
    
    if (!test.test_arr)
        return NULL;
    
    char line[MAXSIZE] = {};

    while ((fgets(line, sizeof(line), test_file) != NULL))
    {
        if (test.test_count == test.test_arr_size)
        {
            test.test_arr_size *= 2;
            Tests* test_arr_tmp = (Tests*)realloc(test.test_arr, sizeof(Tests) * test.test_arr_size);

            if (test_arr_tmp)
                test.test_arr = test_arr_tmp;
            else
                return NULL;
        }

        int is_input_correct = getParam(line, &test);
        if (!is_input_correct)
            return NULL;

        test.test_count++;
    }

    *test_count = test.test_count;
    
    return test.test_arr;
}

int getParam(char line[], struct TestArgs *test)
{
    char sep[10] = " \n";
    char *param = strtok(line, sep);
    
    if (param)
        test->test_arr[test->test_count].a = atof(param);
    else 
        return 0;

    param = strtok(NULL, sep);
    if (param)
        test->test_arr[test->test_count].b = atof(param);
    else 
        return 0;

    param = strtok(NULL, sep);
    if (param)
        test->test_arr[test->test_count].c = atof(param);
    else
        return 0;

    param = strtok(NULL, sep);
    if (param)
        test->test_arr[test->test_count].x1_test = atof(param);
    else 
        return 0;

    param = strtok(NULL, sep);
    if (param)
        test->test_arr[test->test_count].x2_test = atof(param);
    else 
        return 0;

    param = strtok(NULL, sep);
    if (param)
        test->test_arr[test->test_count].root_count_test = atoi(param);
    else 
        return 0;

    return 1;
}

