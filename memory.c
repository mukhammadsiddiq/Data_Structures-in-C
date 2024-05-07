#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate memory for an integer array of size 3
    int *list = malloc(sizeof(int) * 3);
    if (list == NULL)
        return -1; // If memory allocation fails, return -1

    // Assign values to the elements of the array.
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Allocate memory for a new integer array of size 4
    int *tmp = malloc(sizeof(int) * 4);
    if (tmp == NULL)
    {
        // If memory allocation fails, free the previously allocated memory and return -1
        free(list);
        return -1;
    }

    // Copy elements from the original array to the new array
    for (int i = 0; i < 3; i++)
        tmp[i] = list[i];
    
    // Add a new element to the end of the new array
    tmp[3] = 4;

    // Update the pointer 'list' to point to the new array
    list = tmp;

    // Print the elements of the new array
    for (int i = 0; i < 4; i++)
        printf("%d ", list[i]);

    // Free the dynamically allocated memory
    free(list);
    
    return 0; // Return 0 to indicate successful execution
}
