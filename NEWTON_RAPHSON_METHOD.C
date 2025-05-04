#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100


double f(double x) {
    return x*x*x - x - 2;
}


double f_derivative(double x) {
    return 3*x*x - 1;
}

int main() {
    double x0, x1;
    int iter = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    do {
        if (f_derivative(x0) == 0) {
            printf("Derivative is zero. Method fails.\n");
            return -1;
        }

        x1 = x0 - f(x0) / f_derivative(x0);

        printf("Iteration %d: x = %.6lf\n", iter + 1, x1);

        if (fabs(x1 - x0) < EPSILON)
            break;

        x0 = x1;
        iter++;

    } while (iter < MAX_ITER);

    printf("Root = %.6lf\n", x1);

    return 0;
}
