#include <stdio.h>
#include <stdlib.h>

// Define a struct for a linked list node
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char **argv)
{
    // Initialize the linked list to NULL
    node *list = NULL;

    // Iterate through command line arguments, skipping the program name (argv[0])
    for (int i = 1; i < argc; i++)
    {
        // Convert the current command line argument to an integer
        int number = atoi(argv[i]);
        
        // Print the converted number
        printf("%d\n", number);

        // Allocate memory for a new node
        node *n = malloc(sizeof(node));

        // Check if memory allocation failed
        if (n == NULL)
            return 1; // Return 1 to indicate failure

        // Assign the number to the new node's 'number' field
        n->number = number;

        // Make the new node point to the current head of the list
        n->next = list;
        // if list is empty
        if (list == NULL)
        {
            // Update the list head to the new node
            list = n;
        }
        // if number belongs beginnings of the list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        // if there is already number 
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }

    }

    printf("\n\n\n");

    // Iterate through the linked list and print each node's number
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next; //update ptr to next value
    }

    return 0; // Return 0 to indicate successful execution
}
