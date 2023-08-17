#include <math.h>
#include <stdio.h>

int getInput(long double *a, long double *b, long double *c);
void printErrorInput();
int solveLinearEquation(long double *x1, long double *x2, long double b, long double c);
void printErrorLinearEquation(long double b, long double c);
int solveQuadraticEquation(long double *x1, long double *x2, long double a, long double b, long double c);
void printErrorQuadraticEquation(long double a, long double b, long double c);
void printAns(int root_count, long double x1, long double x2);
int checkInput(int number_of_initialized_variables);
int isZero(long double number);
void solve();

int main() {
    solve();

    return 0;
}

void solve() {
    long double a, b, c;
    int number_of_initialized_variables = getInput(&a, &b, &c);

    if (!checkInput(number_of_initialized_variables)) {
        printErrorInput();
        exit(1);
    }

    long double x1 = 0, x2 = 0;
    int root_count;
    if (isZero(a)) {
        root_count = solveLinearEquation(&x1, &x2, b, c);
        if (root_count == 0) {
            printErrorLinearEquation(b, c);
            exit(1);
        }
    } else {
        root_count = solveQuadraticEquation(&x1, &x2, a, b, c);
        if (root_count == 0) {
            printErrorQuadraticEquation(a, b, c);
            exit(1);
        }
    }

    printAns(root_count, x1, x2);
}

int getInput(long double *a, long double *b, long double *c) {
    printf("Enter the coefficients a, b, c\n");
    printf("The coefficients must be real:\n");
    int number_of_initialized_variables = scanf("%Lf%Lf%Lf", a, b, c);
    return number_of_initialized_variables;
}

void printErrorInput() { printf("\nIncorrect data entry: a, b and c must be real numbers!\n"); }

void printAns(int root_count, long double x1, long double x2) {
    if (isZero(x1)) x1 = 0;
    if (isZero(x2)) x2 = 0;

    switch (root_count) {
        case 1:
            printf("\nThe answer: x1 = x2 = %.6Lf\n", x1);
            break;
        case 2:
            printf("\nThe answer: x1 = %.6Lf, x2 = %.6Lf\n", x1, x2);
            break;
        default:
            printf("\nThe answer: x is any real number\n");
    }
}

int checkInput(int number_of_initialized_variables) {
    if (number_of_initialized_variables == 3)
        return 1;
    else
        return 0;
}

int isZero(long double number) {
    long double eps = 1e-9;
    if (fabsl(number) < eps)
        return 1;
    else
        return 0;
}

int solveLinearEquation(long double *x1, long double *x2, long double b, long double c) {
    if (isZero(b) && !isZero(c)) {
        return 0;
    } else if (isZero(b) && isZero(c)) {
        return -1;
    } else {
        *x1 = *x2 = -c / b;
        return 1;
    }
}

int solveQuadraticEquation(long double *x1, long double *x2, long double a, long double b, long double c) {
    long double D = b * b - 4 * a * c;
    if (D < 0) {
        return 0;
    } else if (isZero(D)) {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    } else {
        *x1 = (-b + sqrtl(D)) / (2 * a);
        *x2 = (-b - sqrtl(D)) / (2 * a);
        return 2;
    }
}

void printErrorLinearEquation(long double b, long double c) {
    printf("\nThe equation can`t be solved, division by zero isn`t possible:\n");
    printf("x = -c / b = %Lf / %Lf\n", -c, b);
}

void printErrorQuadraticEquation(long double a, long double b, long double c) {
    long double D = b * b - 4 * a * c;
    printf("\nThe equation can`t be solved, the discriminant is less than zero:\n");
    printf("D = b^2 - 4*a*c = %Lf\n", D);
}
