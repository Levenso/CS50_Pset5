// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//max hashtable size 2^16
#define HASHTABLE_SIZE 65536

//struct for linked list
 typedef struct wordnode
    {
        char word[LENGTH + 1];
        struct wordnode *next;
        // struct wordnode *next;
    }

    node;
    // node* new_node = malloc(sizeof(node));

node* hashtable[HASHTABLE_SIZE] = {NULL};

node *head = NULL;
// node *cursor;
//declare word counter var
int counter = 0;

//hash function
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
int hashValue(const char* word)
{
unsigned int hash = 0;
for (int i=0, n=strlen(word); i<n; i++) {
    hash = (hash << 2) ^ tolower(word[i]);
}
return hash % HASHTABLE_SIZE;
}

bool check(const char* word)
//passes in word from text to check for in dictionary

{
    unsigned int hash =  hashValue(word);
    node *cursor = hashtable[hash];
    // if(hashtable[hash] == NULL)
    // {
    // return false;
    // }

    // else if(hashtable[hash] != NULL)
    // {

    //find bucket word is in
    //compare strings on every node

     while (cursor != NULL)
     {
        if ((strcasecmp(cursor->word, word)) == 0)

        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
     }

return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)

{
    // TODO
//open dictionary file
    FILE *inptr = fopen(dictionary, "r");

//declare temp array for word
    char word[LENGTH + 1];

    // for(int i = 0; i < HASHTABLE_SIZE; i++)
    // {
    //     hashtable[i] = NULL;
    // }
    // node* head = NULL;
    //read each word in dictionary till end of file
    while (fscanf(inptr, "%s ", word) !=EOF)
    {
        //create a node and allocate memory for each word
        node *new_node = malloc(sizeof(node));

        // memset(new_node, 0, sizeof(node));

        //copy each word into node
        if (new_node == NULL)
        {
            unload();
            //speller quits
            return false;
        }
        else
        {
            strcpy(new_node->word, word);
            new_node->next = NULL;
            //new_node->word has word to hash

            //declare hashed index of word
            unsigned int hash =  hashValue(word);

            //new_node should point to whatever was previous in list
            // new_node->next = head;
            // head = new_node;
            new_node->next = hashtable[hash];
            hashtable[hash] = new_node;

            //increment counter for each word to return in SIZE
            counter++;
        }
    }
fclose(inptr);
return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO for loop
    for(int i = 0; i < HASHTABLE_SIZE; i++)
    {
    node *cursor = hashtable[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

    }
    return true;
}

//while (cursor != NULL)
    // {
        // char temp[strlen(word)];
        // strcpy(temp, word);
        // int j = 0;
        // while (temp[j] != '\0')
        // {
        //     if (isupper(temp[j]))
        //     {
        //         temp[j] = tolower(temp[j]);
        //     }
        //     j++;
        // }
        // for (int j = 0; j < strlen(temp); j++)
        // {
        // tolower(temp[j]);
        // }