#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        long long credit;

        printf("Enter your credit card number: ");
        scanf("%lld", &credit);

        char string[30];
        sprintf(string, "%lld", credit);
        int length = 0;

        while (string[length] != '\0')
        {
            length++;
        }

        if (length == 16) // MASTERCARD or VISA
        {
            int multiplied[8];

            for (int i = length - 2, j = 0; i >= 0; i -= 2, j++)
            {
                int converted = string[i] - '0';
                multiplied[j] = converted * 2;
            }

            int sum = 0;

            for (int k = 0; k < sizeof(multiplied) / sizeof(multiplied[0]); k++)
            {
                if (multiplied[k] > 9)
                {
                    sum += (multiplied[k] % 10) + (multiplied[k] / 10);
                }
                else
                {
                    sum += (multiplied[k]);
                }
            }

            int addend = 0;

            for (int i = length - 1; i >= 1; i -= 2)
            {
                int converted = string[i] - '0';
                addend += converted;
            }

            sum += addend;

            if (sum % 10 == 0)
            {
                if (string[0] == '4')
                {
                    printf("VISA\n");
                }
                else if (string[0] == '5')
                {
                    if (string[1] == '1' || string[1] == '2' || string[1] == '3' || string[1] == '4' || string[1] == '5')
                    {
                        printf("MASTERCARD\n");
                        break;
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }

                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 15) // AMEX
        {
            int multiplied[7];

            for (int i = length - 2, j = 0; i >= 1; i -= 2, j++)
            {
                int converted = string[i] - '0';
                multiplied[j] = converted * 2;
            }      

            int sum = 0;

            for (int k = 0; k < sizeof(multiplied) / sizeof(multiplied[0]); k++)
            {
                if (multiplied[k] > 9)
                {
                    sum += (multiplied[k] % 10) + (multiplied[k] / 10);
                }
                else
                {
                    sum += (multiplied[k]);
                }
            }

            int addend = 0;

            for (int i = length - 1; i >= 0; i -= 2)
            {
                int converted = string[i] - '0';
                addend += converted;
            }

            sum += addend;

            if (sum % 10 == 0)
            {
                if (string[0] == '3' && length == 15)
                {
                    if (string[1] == '4' || string[1] == '7')
                    {
                        printf("AMEX\n");
                        break;
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

// SAMPLE CASES

// 4003600000000014 (9 0's) VISA

// 378282246310005 AMEX

// 5555555555554444 (12 5's) MASTERCARD
