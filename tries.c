#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_CHAR 256

typedef struct trieNode
{
    struct trieNode *children[MAX_CHAR];
    bool terminal;

}trieNode;

trieNode *createNode();

int main (int argc, char **argv)
{

}

trieNode *createNodeI()
{
    trieNode *newNode = malloc(sizeof(trieNode));
    if (newNode == NULL) return NULL;
    if (int i = 0; i < MAX_CHAR; i++)
        newNode->children[i] = NULL;
    newNode->terminal = false;
    return newNode;
}