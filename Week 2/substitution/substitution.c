#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string substitute(string key);

int main(int argc, string argv[])
{
    if (argv[1] == NULL || argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int len = strlen(argv[1]);
    if (len == 26)
    {
        // add check for alphabetical chars
        string cipher = substitute(argv[1]);
        printf("ciphertext: %s\n", cipher);
        return 0;
    }
    else
        printf("Key must contain 26 characters.\n");
    return 1;
}

string substitute(string key)
{
    bool isKeyUpper = isupper(key[0]);
    string input = get_string("plaintext: ");
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if(isalpha(input[i]))
        {
            if (isKeyUpper)
            {
                if (isupper(input[i]))
                    {
                        int diff = input[i] - 'A';
                        input[i] = key[diff];
                    }
                else
                    {
                        int diff = input[i] - 'a';
                        char upper = key[diff];
                        input[i] = upper + 32;
                    }
            }
            else
            {
                if (isupper(input[i]))
                {
                    int diff = input[i] - 'A';
                    char lower = key[diff];
                    input[i] = lower - 32;
                }
                else
                {
                    int diff = input[i] - 'a';
                    input[i] = key[diff];
                }
            }
        }

    }
    return input;
}
