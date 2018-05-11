// Implements a dictionary's functionality

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

 typedef struct node
    {
        char word[LENGTH + 1];
        struct node *next;
    }

    node;

    Node* hashtable[HASHTABLE_SIZE];

//While working on your load function, you might want to also implement your size function –
//it just returns the number of words in your dictionary. Consider a global variable for that one, too.
//That would allow you to use the same variable for both counting the words as you load them
//and returning the number of words loaded when size is called.

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //strcasecmp
    node *cursor = head;
    while (cursor != NULL)
    {
        //compare strings on every node
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

// Ref: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/

inline int hashValue(const char *word)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % 26;
}



    while (fscanf(file, "%s", word !=EOF))
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        unload();
        return false;
    }
    else
    {
        strcpy(new+node->word, word);
        new_node->next = head;
        head = new_node;
    }
}

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // I think...
    // count function(),
    // read word;
    // counter++;
    // return counter;

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor = head;

    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return false;
}
