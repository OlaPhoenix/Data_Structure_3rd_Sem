#include <stdio.h>

void multiplySparseMatrices(int A[][3], int B[][3], int k) {
    // Initialize result matrix
    int result[k][3];

    // Initialize result index
    int r = 0;

    // Iterate through rows of A
    for (int i = 0; i < k; i++) {
        // Iterate through columns of B
        for (int j = 0; j < k; j++) {
            // Initialize sum for this entry
            int sum = 0;

            // Iterate through elements of row i in A and column j in B
            for (int x = 0; x < k; x++) {
                // Find corresponding elements and multiply
                if (A[x][0] == i && B[x][1] == j) {
                    sum += A[x][2] * B[x][2];
                }
            }

            // If sum is not zero, add it to result
            if (sum != 0) {
                result[r][0] = i;
                result[r][1] = j;
                result[r][2] = sum;
                r++;
            }
        }
    }

    // Print the result
    printf("Result Matrix:\n");
    for (int i = 0; i < r; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int k;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[k][3];
    int B[k][3];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    multiplySparseMatrices(A, B, k);

    return 0;
}