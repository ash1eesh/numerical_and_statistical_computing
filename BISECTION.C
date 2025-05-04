#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  
#define MAX_ITER 100     


double f(double x) {
    return x * x - 4;
}

int main() {
    double a, b, c;
    int iter = 0;


    printf("Enter the interval [a, b] where f(a) and f(b) have opposite signs: ");
    scanf("%lf %lf", &a, &b);


    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return -1;
    }


    do {

        c = (a + b) / 2;

    
        if (f(c) == 0.0 || fabs(b - a) < EPSILON) {
            break;
        }

    
        if (f(a) * f(c) < 0) {
            b = c;  
        } else {
            a = c;  
        }

        printf("Iteration %d: c = %.6lf\n", iter + 1, c);
        iter++;

    } while (iter < MAX_ITER);

    printf("Root = %.6lf\n", c);
    return 0;
}
