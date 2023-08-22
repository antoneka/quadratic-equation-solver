#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H
/**
 * @brief A function that solves a quadratic equation
 * @param[in] a The first coefficient
 * @param[in] b The second coefficient
 * @param[in] c The third coefficient
 * @param[out] x1 A pointer to the first root
 * @param[out] x2 A pointer to the second root
 * @return The number of roots
 */
int solveQuadraticEquation(const double a, const double b, const double c, double *x1, double *x2);

/**
 * @brief A function that solves a quadratic equation for a = 0
 * @param[in] b The second coefficient 
 * @param[in] c The third coefficient
 * @param[out] x A pointer to the second root
 * @return The number of roots 
 */
int solveLinearEquation(const double b, const double c, double *x);

#endif // QUADRATIC_EQUATION_H
