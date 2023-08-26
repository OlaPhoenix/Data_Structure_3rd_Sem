/*Write a program to divide two very large numbers. Also, analyze the time and space complexity.
Each number is represented as a string, and its upper limit is 1024 digits*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform division of large numbers
char* longDivision(char* dividend, int divisor)
{
    int length = strlen(dividend);
    char* ans = (char*)malloc(sizeof(char) * (length + 1));
    int ansIdx = 0;
    int temp = 0;

    // Iterate through the digits of the input dividend
    for (int i = 0; i < length; i++)
    {
        temp = temp * 10 + (dividend[i] - '0');
        if (temp >= divisor || ansIdx > 0)
        {
            ans[ansIdx++] = temp / divisor + '0';
            temp = temp % divisor;
        }
    }
    ans[ansIdx] = '\0';

    // If divisor is greater than dividend
    if (ansIdx == 0)
    {
        ans[0] = '0';
        ans[1] = '\0';
    }

    return ans;
}

int main()
{
    char dividend[1025];
    int divisor;

    printf("Enter the dividend: ");
    scanf("%s", dividend);

    printf("Enter the divisor: ");
    scanf("%d", &divisor);

    char* quotient = longDivision(dividend, divisor);
    printf("%s\n", quotient);

    free(quotient);
    return 0;
}

// Time Complexity : O(n), where n is the length of the dividend
// Space Complexity : O(n), where n is the length of the dividend
