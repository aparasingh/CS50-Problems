#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define LAST_DIGITS 10

int checkSum(long cardNum, int length);

int main(void)
{
    long cardNum = get_long("Number: ");
    int length = log10(cardNum) + 1;
    int firstDigits = cardNum / (pow(LAST_DIGITS, length - 2));
    if (length == 15 && (firstDigits == 34 || firstDigits == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (firstDigits == 51 || firstDigits == 52 || firstDigits == 53 ||
                              firstDigits == 54 || firstDigits == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && firstDigits / 10 == 4)
    {
        if (checkSum(cardNum, length))
        {
            printf("VISA\n");
        }
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

int checkSum(long cardNum, int length)
{
    int sum = 0;
    int last;
    for (int i = 0; i < length; i++)
    {
        last = cardNum % LAST_DIGITS;
        cardNum = cardNum / 10;
        if (i % 2 != 0)
        {
            last = last * 2;
            if (last >= LAST_DIGITS)
            {
                int lastDigit = last % LAST_DIGITS;
                int firstDigit = last / LAST_DIGITS;
                last = lastDigit + firstDigit;
            }
            sum += last;
        }
        else
            sum += last;
    }
    return sum % LAST_DIGITS == 0;
}
