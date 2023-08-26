/*Write a program to multiply two very large numbers. Also, analyze the time and space complexity.
Each number is represented as a string, and its upper limit is 1024 digits*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform multiplication of large numbers
char* longMultiplication(char* num1, char* num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int resultSize = len1 + len2;
    int* result = (int*)calloc(resultSize, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            int product = n1 * n2 + result[i + j + 1];
            result[i + j + 1] = product % 10;
            result[i + j] += product / 10;
        }
    }

    char* res = (char*)malloc((resultSize + 1) * sizeof(char));
    int resIdx = 0;
    int startIdx = 0;
    while (startIdx < resultSize && result[startIdx] == 0)
        startIdx++;
    
    while (startIdx < resultSize)
        res[resIdx++] = result[startIdx++] + '0';

    res[resIdx] = '\0';
    free(result);
    return res;
}

int main()
{
    char num1[1025];
    char num2[1025];
    
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    char* result = longMultiplication(num1, num2);
    printf("Product: %s\n", result);

    free(result);
    return 0;
}

// Time Complexity : O(n*m), where n and m are the lengths of the two input strings
// Space Complexity : O(n+m), where n and m are the lengths of the two input strings