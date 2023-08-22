#include "common.h"

int checkInput(int variables_count, char symbol_entry)
{
    if (variables_count == EOF)
        return 1;
    else if (variables_count == 4)
    {
        if (symbol_entry != '\n' && symbol_entry != ' ')
            return 0;
        else if (symbol_entry == '\n')
            return 1;
        else 
        {
            char c = 0;
            while ((c = getchar()) != '\n') {
                if (c != ' ')
                    return 0;
            }
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void clearBuffer() 
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int isEqual(const double num1, const double num2) 
{ 
    static const double eps = 1e-6;
    return fabs(num1 - num2) < eps; 
}

