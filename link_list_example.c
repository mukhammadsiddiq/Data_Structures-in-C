#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a node structure for the linked list
typedef struct node {
    char *phrase;          // Pointer to a string (phrase)
    struct node *next;     // Pointer to the next node in the list
} node;

// Function prototypes
bool isValid(node *list);
void visualize(node *list);

int main(int argc, char **argv) {
    node *list = NULL;  // Initialize the list to be empty

    // Iterate over the command-line arguments (excluding the program name)
    for (int i = 1; i < argc; i++) {
        node *node = malloc(sizeof(node));  // Allocate memory for a new node
        if (node == NULL) return -1;        // Check if memory allocation failed

        node->phrase = argv[i];             // Assign the phrase from command-line arguments to the node
        node->next = NULL;                  // Initialize the next pointer to NULL

        // Insert the new node at the beginning of the list
        node->next = list;  // Point the new node's next to the current list
        list = node;        // Update the list to point to the new node

        visualize(list);    // Visualize the list after each insertion
    }

    // Check if the list is valid and print the result
    if (!isValid(list)) 
        printf("Not successfully created\n");
    else 
        printf("Successfully created\n");

    return 0;  // Return 0 to indicate successful execution
}

// Function to check if the list is valid (dummy function, always returns false)
bool isValid(node *list) {
    node *ptr = list; //assigning list to ptr;
    while (ptr != NULL) {
        ptr = list->next;
        free(list);
        list = ptr;
    }
    return true;
}

// Function to visualize the linked list
void visualize(node *list) {
    printf("--------------------------------\n");
    while (list != NULL) {  // Traverse the list
        printf("Location: %p\nPhrase: %s\nNext Location: %p\n", list, list->phrase, list->next);
        list = list->next;  // Move to the next node
    }
    printf("--------------------------------\n");
}
