/*Write a program to implement the power function for double without using the pow library
function. You can use math.h but cannot use the pow function*/

#include <stdio.h>
#include <math.h>

double customPower(double base, int exponent)
{
    double result = 1.0;

    if (exponent >= 0)
    {
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
    } 
    else
    {
        exponent = -exponent;
        for (int i = 0; i < exponent; i++)
        {
            result /= base;
        }
    }

    return result;
}

int main()
{
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double calculatedPower = customPower(base, exponent);

    printf("Custom Power Function: %.2f\n", calculatedPower);

    return 0;
}
