#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string substitute(string key);
bool is_alpha(string key);
bool no_repeat(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if (len == 26)
    {
        if (is_alpha(argv[1]) && no_repeat(argv[1]))
        {
            string cipher = substitute(argv[1]);
            printf("ciphertext: %s\n", cipher);
            return 0;
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    else
        printf("Key must contain 26 characters.\n");
    return 1;
}

string substitute(string key)
{
    string input = get_string("plaintext: ");
    int len = strlen(input);
    int diff;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                diff = input[i] - 'A';
                if (isupper(key[diff]))
                    input[i] = key[diff];
                else
                    input[i] = key[diff] - 32;
            }
            else
            {
                diff = input[i] - 'a';
                if (isupper(key[diff]))
                    input[i] = key[diff] + 32;
                else
                    input[i] = key[diff];
            }
        }
    }
    return input;
}

bool is_alpha(string key)
{
    int i = 0;
    while (i < 26)
    {
        if (isalpha(key[i]))
        {
            i++;
        }
        else
            return false;
    }
    return true;
}

bool no_repeat(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int k = i + 1; k < 26; k++)
        {
            if (tolower(key[i]) == tolower(key[k]))
            {
                return false;
            }
        }
    }
    return true;
}