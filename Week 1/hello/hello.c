#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts user to enter name
    string answer = get_string("What is your name? ");
    // Says hello to the user
    printf("Hello, %s\n", answer);
}
