#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

/**
 * @brief A function that accepts the input of coefficients
 * @param[in] a A pointer to the first coefficient 
 * @param[in] b A pointer to the second coefficient
 * @param[in] c A pointer to the the constant term 
 * @return The number of initialized variables 
 *
 *
 * The symbol following the third coefficient (there must be a character '\\n' or ' ')
 * @code
 * char enter_symbol = 0;
 * @endcode
 */
int getInput(double *a, double *b, double *c);

/** 
 * @brief A function that outputs an error in case of incorrect data entry
 */
void printErrorInput();

/**
 * @brief A functon that checks the input data
 * @param[in] variables_count The number of initialized variables
 * @param[in] symbol_entry The symbol immediately following the constant term
 * @return true if the input is correct otherwise false
 */
int checkInput(int variables_count, char symbol_entry);

/**
 * @brief A function that outputs the roots of the equation
 * @param[in] x1 The first root
 * @param[in] x2 The second root
 * @param[in] root_count The number of roots
 */
void printAns(const int root_count, const double x1, const double x2);

#endif // INPUT_OUTPUT_H
