#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_CHAR 256

typedef struct trienode
{
    struct trienode *children[MAX_CHAR];
    bool terminal;

}trienode;

int main (int argc, char **argv)
{

}