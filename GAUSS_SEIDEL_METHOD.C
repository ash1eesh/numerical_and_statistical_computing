#include <stdio.h>
#include <math.h>

#define N 3              
#define EPSILON 0.001      
#define MAX_ITER 100

int main() {
    float A[N][N] = {
        {4, -1, 0},
        {-1, 4, -1},
        {0, -1, 3}
    };

    float b[N] = {15, 10, 10};
    float x[N] = {0};      
    int i, j, iter;
    float sum, error;

    for (iter = 0; iter < MAX_ITER; iter++) {
        error = 0;

        for (i = 0; i < N; i++) {
            sum = b[i];

            for (j = 0; j < N; j++) {
                if (j != i)
                    sum -= A[i][j] * x[j];
            }

            float x_new = sum / A[i][i];
            error += fabs(x_new - x[i]);
            x[i] = x_new;
        }

        if (error < EPSILON)
            break;
    }

    printf("Solution after %d iterations:\n", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x[%d] = %.5f\n", i, x[i]);
    }

    return 0;
}
