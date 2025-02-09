#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char value, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]))
    {
        string input = get_string("plaintext: ");
        int len = strlen(input);
        int key = atoi(argv[1]);
        for (int i = 0; i < len; i++)
        {
            input[i] = rotate(input[i], key);
        }
        printf("ciphertext: %s\n", input);
        return 0;
    }
    else
        printf("Usage: ./caesar key\n");
    return 1;
}

bool only_digits(string key)
{
    int len = strlen(key);
    int i = 0;
    while (i < len)
    {
        if (isdigit(key[i]))
        {
            i++;
        }
        else
            return false;
    }
    return true;
}

char rotate(char value, int key)
{
    int asciiValue = (int) value;
    if (isalpha(value))
    {
        if (isupper(value))
        {
            asciiValue = (((value - 'A') + key) % 26) + 65;
        }
        else
        {
            asciiValue = (((value - 'a') + key) % 26) + 97;
        }
    }
    char newValue = (char) asciiValue;
    return newValue;
}