#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

/**
 * @brief A function that accepts the input of coefficients
 * @param[in] a A pointer to the first coefficient 
 * @param[in] b A pointer to the second coefficient
 * @param[in] c A pointer to the the constant term 
 * @return The number of initialized variables 
 */
int getInput(double *a, double *b, double *c);

/** 
 * @brief A function that outputs an error in case of incorrect data entry
 */
void printErrorInput();

/**
 * @brief A function that outputs the roots of the equation
 * @param[in] x1 The first root
 * @param[in] x2 The second root
 * @param[in] root_count The number of roots
 */
void printAns(const int root_count, const double x1, const double x2);

#endif // INPUT_OUTPUT_H
