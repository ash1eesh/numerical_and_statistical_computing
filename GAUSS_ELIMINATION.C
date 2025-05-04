#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

int main() {
    float a[N][N+1], x[N];
    int i, j, k;
    float ratio;


    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j <= N; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }


    for (i = 0; i < N - 1; i++) {
        if (fabs(a[i][i]) < 1e-6) {
            printf("Zero pivot encountered. Cannot proceed.\n");
            exit(1);
        }

        for (j = i + 1; j < N; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = i; k <= N; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }


    for (i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }


    printf("\nSolution:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %.5f\n", i, x[i]);
    }

    return 0;
}
