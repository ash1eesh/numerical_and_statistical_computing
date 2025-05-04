#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  
#define MAX_ITER 100     


double f(double x) {
    return x * x - 4;
}

int main() {
    double x0, x1, x2;
    int iter = 0;

    printf("Enter initial guesses x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    do {
   
        double f0 = f(x0);
        double f1 = f(x1);

    
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        printf("Iteration %d: x = %.6lf\n", iter + 1, x2);

      
        if (fabs(x2 - x1) < EPSILON) {
            break;
        }

       
        x0 = x1;
        x1 = x2;
        iter++;

    } while (iter < MAX_ITER);

    printf("Root = %.6lf\n", x2);

    return 0;
}
