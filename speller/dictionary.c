// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"


//While working on your load function, you might want to also implement your size function –
//it just returns the number of words in your dictionary. Consider a global variable for that one, too.
//That would allow you to use the same variable for both counting the words as you load them
//and returning the number of words loaded when size is called.

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO http://www.cse.yorku.ca/~oz/hash.html
     unsigned long
    hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // I think...
    count function(),
    read word;
    counter++;
    return counter;

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
