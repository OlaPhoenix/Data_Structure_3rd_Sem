#include <stdio.h>
#include <math.h>

void powerSparseMatrix(int A[][3], int k, int n) {
    int result[k][3];
    
    for(int i = 0; i < k; i++) {
        result[i][0] = A[i][0];
        result[i][1] = A[i][1];
        result[i][2] = pow(A[i][2], n);
    }

    printf("Result Matrix:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int k, n;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[k][3];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter the exponent n: ");
    scanf("%d", &n);

    powerSparseMatrix(A, k, n);

    return 0;
}