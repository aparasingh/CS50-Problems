// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table: Prime number nearest to 26*26*26
const unsigned int N = 17573;

// Hash table
node *table[N];

int dict_size = 0;

// Initialize hash table
void init_hashtable()
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Check sum of characters in word
    int len = strlen(word);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(word[i]))
        {
            sum += toupper(word[i]);
        }
    }
    return sum % N;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    init_hashtable();
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char *word = malloc(LENGTH * sizeof(char));
    int index = 0;
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not allocate enough memory");
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            node *ptr = table[index]->next;
            table[index]->next = n;
            if (ptr != NULL)
            {
                n->next = ptr;
            }
        }
        dict_size++;
    }
    fclose(file);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return size of hash table
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
        table[i] = NULL;
    }
    return true;
}
