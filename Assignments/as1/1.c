/*Write a program to add two very large numbers. Also, analyze the time and space complexity.
Each number is represented as a string, and its upper limit is 1024 digits*/

#include <stdio.h>
#include <string.h>

char *add_strings(char *num1, char *num2, char *result)
{
    int len1 = strlen(num1);                                   // Get the length of the first number
    int len2 = strlen(num2);                                   // Get the length of the second number
    int carry = 0;                                             // Initialize the carry to 0
    int k = 0;                                                 // Initialize the result index to 0
    int i = len1 - 1;                                          // Start from the last digit of the first number
    int j = len2 - 1;                                          // Start from the last digit of the second number

    while (i >= 0 || j >= 0)
    {                                                          // While there are digits left in either number
        int sum = carry;                                       // Add the carry to the sum

        if (i >= 0)
        {                                                      // If there are digits left in the first number
            sum += num1[i] - '0';                              // Add the current digit of the first number to the sum
            i--;                                               // Move to the next digit of the first number
        }

        if (j >= 0)
        {                                                      // If there are digits left in the second number
            sum += num2[j] - '0';                              // Add the current digit of the second number to the sum
            j--;                                               // Move to the next digit of the second number
        }

        carry = sum / 10;                                      // Compute the new carry

        result[k++] = (sum % 10) + '0';                        // Store the current digit of the result
    }

    if (carry)
    {                                                          // If there is a final carry
        result[k++] = carry + '0';                             // Store it as the last digit of the result
    }

    result[k] = '\0';                                          // Terminate the result string
    strrev(result);                                            // Reverse the result string to get the final result
    return result;
}

int main()
{
    char num1[1025], num2[1025], result[1025];

    printf("Enter first number: ");
    scanf("%s", num1);

    printf("Enter second number: ");
    scanf("%s", num2);

    printf("Sum: %s\n", add_strings(num1, num2, result));      // Call add_strings to compute and print the sum of the two numbers

    return 0;
}


// Time Complexity : O(n), where n is the length of the longer input number
// Space Complexity : O(n), where n is the length of the longer input number