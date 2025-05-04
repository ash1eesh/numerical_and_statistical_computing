#include <stdio.h>
#include <math.h>

#define N 3             
#define EPSILON 0.001  
#define MAX_ITER 100    

int main() {
    float A[N][N] = {
        {10, -1, 2},
        {-1, 11, -1},
        {2, -1, 10}
    };

    float b[N] = {6, 25, -11};
    float x[N] = {0};        
    float x_new[N];
    int i, j, iter;
    float sum, error;

    for (iter = 0; iter < MAX_ITER; iter++) {
        for (i = 0; i < N; i++) {
            sum = b[i];
            for (j = 0; j < N; j++) {
                if (j != i)
                    sum -= A[i][j] * x[j];
            }
            x_new[i] = sum / A[i][i];
        }


        error = 0;
        for (i = 0; i < N; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        if (error < EPSILON) {
            break;
        }
    }

    printf("Solution after %d iterations:\n", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x[%d] = %.5f\n", i, x[i]);
    }

    return 0;
}
