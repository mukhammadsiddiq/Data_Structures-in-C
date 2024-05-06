#include <stdio.h> // Include standard input/output library for functions like printf
#include <stdbool.h> // Include boolean library for true/false values
#include <stdlib.h> // Include standard library for memory allocation (malloc)

// Define a structure named "node" to represent a node in a binary search tree
typedef struct node {
    int number; // Data value stored in the node
    struct node *left_tree;  // Pointer to the left child node
    struct node *right_tree; // Pointer to the right child node
} node;

// Function to search for a number in the binary search tree
bool search_tree(node *tree, int number) {
    if (tree == NULL) {  // Base case: If the tree is empty (root is NULL)
        return false;  // Return false, indicating number not found
    } else if (number < tree->number) {  // If the number is less than the current node's value
        return search_tree(tree->left_tree, number);  // Recursively search the left subtree
    } else if (number > tree->number) {  // If the number is greater than the current node's value
        return search_tree(tree->right_tree, number);  // Recursively search the right subtree
    } else {  // If the number is equal to the current node's value
        return true;  // Return true, indicating number found
    }
}

// Function to create a new node in the binary search tree
node *createNode(int value) {
    node *result = malloc(sizeof(node));  // Allocate memory for a new node
    if (result == NULL) {  // Check for allocation failure
        printf("Memory allocation error!\n");  // Handle error (optional)
        return NULL;  // Return NULL if allocation fails
    }

    result->left_tree = NULL;  // Initialize left child pointer to NULL
    result->right_tree = NULL; // Initialize right child pointer to NULL
    result->number = value;    // Set the node's data value

    return result;  // Return the newly created node
}

// Function to print the binary search tree in a hierarchical format (in-order traversal)
void printTree(node *root) {
    if (root == NULL) {  // Base case: If the tree is empty (root is NULL)
        printf("tree is empty\n");  // Print message indicating empty tree
        return;  // Exit the function
    }

    printf("value: %d\n", root->number); // Print the current node's value

    if (root->left_tree != NULL) {  // Check for left child before recursion
        printf("left ");  // Indentation for left subtree
        printTree(root->left_tree);  // Recursively print the left subtree
    } else {
        printf("left: empty\n");  // Print "empty" if there's no left child
    }

    if (root->right_tree != NULL) {  // Check for right child before recursion
        printf("right ");  // Indentation for right subtree
        printTree(root->right_tree); // Recursively print the right subtree
    } else {
        printf("right: empty\n");  // Print "empty" if there's no right child
    }
}

int main(int argc, char **argv) {
    // Create nodes for the binary search tree
    node *n1 = createNode(13);
    node *n2 = createNode(14);
    node *n3 = createNode(15);
    node *n4 = createNode(16);
    node *n5 = createNode(17);

    // Build the binary search tree structure (example)
    n1->left_tree = n2;
    n1->right_tree = n5;
    n2->left_tree = n3;
    n2->right_tree = n4;

    // Print the binary search tree
    printTree(n1);

    // Free the allocated memory for the nodes (important to prevent memory leaks)
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;  // Indicate successful program termination
}
