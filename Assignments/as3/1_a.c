#include<stdio.h>

void addSparseMatrix(int A[][3],int B[][3], int k){
    int result[k][3];
    int r = 0, i =0, j = 0;
    while(i<k && j<k){
        if(A[i][0] < B[j][0]){
            result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2];
            i++;
        }
          else if(A[i][0] > B[j][0]){
            result[r][0] = B[i][0];
            result[r][1] = B[i][1];
            result[r][2] = B[i][2];
            j++;
          }  else{
            result[r][0] = A[i][0];
            result[r][1] = A[i][1] + B[i][1];
            result[r][2] = A[i][2] + B[i][2];
            i++;
            j++;
          }
          r++;
    }
    while(i<k){
        result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2];
            i++;
            r++;
    }
    while(j<k){
        result[r][0] = B[i][0];
            result[r][1] = B[i][1];
            result[r][2] = B[i][2];
            j++;
            r++;
    }

    //print the result
    printf("Resultant matrix: \n");
    for(int x =0; x<r; x++){
        printf("%d %d %d \n", result[x][0], result[x][1], result[x][2]);
    }
}

int main(){
    int k;
    printf("Enter the value of K: ");
    scanf("%d", &k);
    int A[k][3], B[k][3];
    printf("Enter the elements of matrix A: \n");
    for(int i =0 ; i<k; i++){
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }
    printf("Enter the elements of matrix B: \n");
    for(int i =0 ; i<k; i++){
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }
    addSparseMatrix(A,B,k);
    return 0;

}