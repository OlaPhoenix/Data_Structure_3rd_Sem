/*Write a program to divide x by y upto nth decimal point. Also, analyze the time and space complexity.
For instance, x=22, y=7, and n=1000*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 10000

// Function to perform division up to n decimal points
void longDivisionWithPrecision(int x, int y, int n)
{
    int quotient = x / y;
    int remainder = x % y;
    printf("%d.", quotient); // Print the integer part

    for (int i = 0; i < n; i++)
    {
        remainder *= 10;
        int digit = remainder / y;
        remainder %= y;
        printf("%d", digit);
    }
    printf("\n");
}

int main()
{
    int x = 22;
    int y = 7;
    int n = 1000;

    longDivisionWithPrecision(x, y, n);

    return 0;
}

// Time Complexity : O(n), where n is the number of decimal places to calculate
// Space Complexity : O(1), as the program uses a constant amount of memory to store variables regardless of the input