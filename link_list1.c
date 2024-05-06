#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the queue
typedef struct Node
{
    int number;         // Data stored in the node
    struct Node *next;  // Pointer to the next node
} Node;

// Define a structure for the queue
typedef struct
{
    Node *head;     // Pointer to the first node in the queue
    Node *tail;     // Pointer to the last node in the queue
    int size;       // Number of elements in the queue
} Queue;

// Function prototypes
Queue *createQueue();
int size(Queue *queue);
bool isEmpty(Queue *queue);
int peek(Queue *queue,bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroyQueue(Queue *queue);

int main(int argc, char **argv)
{
    // Create a new queue
    Queue * queue = createQueue();

    // Add some elements to the queue
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 7);

    // Check if the queue is empty and print its size if not
    if(!(isEmpty(queue)))
    {
        printf("queue size is : %d\n", size(queue));
    }
    else
    {
        printf("is empty");
    }
    
    // Peek at the front element of the queue
    bool status = false;
    int value = 0;
    value = peek(queue, &status);
    if (status) printf("peek is succesfull : %d\n", value);

    // Dequeue an element from the queue
    value = dequeue(queue, &status);
    if (status) printf("dequeue is succesfull %d\n", value);

    // Dequeue another element from the queue
    dequeue(queue, &status);

    // Destroy the queue to free memory
    destroyQueue(queue);

    return 0;
}

// Create a new empty queue
Queue *createQueue()
{
    // Allocate memory for the queue structure
    Queue *queue = malloc(sizeof(Queue));

    // Initialize queue properties
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

// Get the size of the queue
int size(Queue *queue)
{
    return queue->size;
}

// Check if the queue is empty
bool isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// Peek at the front element of the queue without removing it
int peek(Queue *queue, bool *status)
{
    // Check if the queue is empty
    if(isEmpty(queue))
    {
        *status = false;    // Set status to indicate failure
        return -1;          // Return a default value (-1) to indicate failure
    }
    *status = true;         // Set status to indicate success
    return queue->head->number; // Return the number stored in the first node
}

// Add an element to the end of the queue
void enqueue(Queue *queue, int value)
{
    // Allocate memory for a new node
    Node *newNode = malloc(sizeof(Node));

    // Initialize the new node
    newNode->number = value;
    newNode->next = NULL;

    // Check if the queue is empty
    if (isEmpty(queue))
    {
        // If empty, set both head and tail to the new node
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        // If not empty, append the new node to the end of the queue
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;  // Increment the size of the queue
}

// Remove and return the front element of the queue
int dequeue(Queue *queue, bool *status)
{
    // Check if the queue is empty
    if (isEmpty(queue))
    {
        *status = false;    // Set status to indicate failure
        return -1;          // Return a default value (-1) to indicate failure
    }
    *status = true;         // Set status to indicate success

    int value = queue->head->number;   // Store the value of the front element

    Node *oldHead = queue->head;    // Store a reference to the old head node

    // Update the head pointer to the next node
    if (queue->size == 1)
    {
        // If only one element, set both head and tail to NULL
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        // If more than one element, move head to the next node
        queue->head = queue->head->next;
    }
    free(oldHead);  // Free memory allocated for the old head node
    queue->size--;  // Decrement the size of the queue
    return value;   // Return the value of the dequeued element
}

// Free memory allocated for the queue and its nodes
void destroyQueue(Queue *queue)
{
    Node *currentNode = queue->head;
    while (currentNode != NULL)
    {
        Node *tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }
    free(queue);
}
