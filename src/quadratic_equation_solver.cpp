#include <math.h>
#include <stdio.h>

int getInput(double *a, double *b, double *c);
void printErrorInput();
int solveLinearEquation(double *x1, double *x2, double b, double c);
int solveQuadraticEquation(double *x1, double *x2, double a, double b, double c);
void printAns(int root_count, double x1, double x2);
int isEqual(double num1, double num2);
void clearBuffer();

const double eps = 1e-9;

enum Roots { 
    ZERO_ROOTS, 
    ONE_ROOT, 
    TWO_ROOTS, 
    INF_ROOTS = -1
};

int main() {
    double a, b, c;
    int end_of_input = getInput(&a, &b, &c);
    if (end_of_input == EOF) {
        return 1;
    }

    double x1 = 0, x2 = 0;
    int root_count = solveQuadraticEquation(&x1, &x2, a, b, c);

    printAns(root_count, x1, x2);

    return 0;
}

int getInput(double *a, double *b, double *c) {
    printf("Enter the coefficients a, b, c\n"
            "The coefficients must be real: ");

    int number_of_initialized_variables = scanf("%lf%lf%lf", a, b, c);
    while (number_of_initialized_variables != 3 && number_of_initialized_variables != EOF) {
        printErrorInput();
        clearBuffer();
        number_of_initialized_variables = scanf("%lf%lf%lf", a, b, c);
    }

    return number_of_initialized_variables;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printErrorInput() {
    printf("\nIncorrect data entry: a, b and c must be real numbers!\n"
            "Try again: ");
}

void printAns(int root_count, double x1, double x2) {
    switch (root_count) {
        case ZERO_ROOTS:
            printf("\nThe equation has no roots\n");
            break;
        case ONE_ROOT:
            printf("\nThe answer: x1 = x2 = %.6lf\n", x1);
            break;
        case TWO_ROOTS:
            printf("\nThe answer: x1 = %.6lf, x2 = %.6lf\n", x1, x2);
            break;
        default:
            printf("\nThe equation has an infinite number of roots\n");
    }
}

int isEqual(double num1, double num2) { 
    return fabs(num1 - num2) < eps; 
}

int solveLinearEquation(double *x1, double *x2, double b, double c) {
    int num_of_roots;
    if (isEqual(b, 0) && !isEqual(c, 0)) {
        num_of_roots = ZERO_ROOTS;
    } else if (isEqual(b, 0) && isEqual(c, 0)) {
        num_of_roots = INF_ROOTS;
    } else {
        if (isEqual(c, 0)) {
            *x1 = *x2 = 0;
        } else {
            *x1 = *x2 = -c / b;
        }
        num_of_roots = ONE_ROOT;
    }

    return num_of_roots;
}

int solveQuadraticEquation(double *x1, double *x2, double a, double b, double c) {
    int num_of_roots;
    if (isEqual(a, 0)) {
        num_of_roots = solveLinearEquation(x1, x2, b, c);
    } else {
        double D = b * b - 4 * a * c;
        if (isEqual(D, 0)) {
            if (isEqual(b, 0)) {
                *x1 = *x2 = 0;
            } else {
                *x1 = *x2 = -b / (2 * a);
            }
            num_of_roots = ONE_ROOT;
        } else if (D < 0) {
            num_of_roots = ZERO_ROOTS;
        } else {
            if (isEqual(c, 0)) {
                *x1 = 0;
                *x2 = -b / a;
            } else {
                double sqrt_of_discriminant = sqrt(D);
                *x1 = (-b + sqrt_of_discriminant) / (2 * a);
                *x2 = (-b - sqrt_of_discriminant) / (2 * a);
            }
            num_of_roots = TWO_ROOTS;
        }
    }

    return num_of_roots;
}
