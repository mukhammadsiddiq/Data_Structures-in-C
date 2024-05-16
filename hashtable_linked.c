#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
// defining max name and table size
#define MAX_NAME 256
#define TABLE_SIZE 10
// creating new struct
typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;
// creating hashtable
person *hashtable[TABLE_SIZE];
// prototyping functions
unsigned int hash(const char *name);
void init_hash_table();
void print_table();
bool insert_table(person *p);
person *find_person(char *name);
person *delete_person(char *name);

int main(int argc, char **argv)
{
    // initialize the table to NULL
    init_hash_table();
    // assigning person data
    person max = {.name = "max", .age = 45};
    person min = {.name = "min", .age = 34};
    person ali = {.name = "ali", .age =24};
    person ahror = {.name = "ahrorrrrrrrrr", .age =64};
    person azam = {.name = "azam", .age =34};
    person abror = {.name = "abroreww", .age =22};
    // inserting data to the table
    insert_table(&max);
    insert_table(&min);
    insert_table(&ali);
    insert_table(&ahror);
    insert_table(&azam);
    insert_table(&abror);
    print_table(); // printing the table after assign
    //calling function in order to find a person
    person *tmp = find_person("azam");
    if (tmp == NULL) // checking if tmp is not empty , does it find a person or not
        printf("Person not found.\n");
    else
        printf("Found\nName: %s\nAge: %d\n", tmp->name, tmp->age);
    // calling the function delete_data from table
    person *tmp2 = delete_person("min");
    person *tmp3 = delete_person("abroreww");
    if (tmp2 == NULL && tmp3 == NULL) // the same checking if it is empty or no
        printf("Person not found for deletion.\n");
    else
        printf("Deleted successfully\nName: %s\nAge: %d\nName: %s\nAge: %d\n", tmp2->name, tmp2->age, tmp3->name, tmp3->age);
    print_table(); // printing the table after operations
    
    return 0;
}
// initialize the hashtable with NULL values
void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
}
// hashing the value
unsigned int hash(const char *name)
{
    unsigned int index = 0;
    while (*name)
    {
        index = (index << 5) + *name++;
    }
    return index % TABLE_SIZE;
}
// printfing the table
void print_table()
{
    printf("table started\n");
    // iterating through the tables
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // checking if  hashtable is empty
        if(hashtable[i] == NULL)
            printf("\t %i \t-------\n", i);
        else
        {
            printf("\t %i \t", i);
            person *tmp = hashtable[i];
            while (tmp != NULL)
            {
                printf("%s -->", tmp->name); // printing the value in the linked list
                tmp = tmp ->next; //updating tmp value to the next value in linked list
            }
            printf("\n");
        }
    }
    printf("table end\n");
}
// inserting the data into the table
bool insert_table(person *p)
{
    if (p == NULL) return false; //checks for the value inside p
    int index = hash(p->name); // calling hash function
    p->next = hashtable[index];
    hashtable[index] = p;
    return true;
}

person *find_person(char *name)
{
    int index = hash(name);
    person *tmp = hashtable[index];
    while ((tmp != NULL) && strcmp(tmp->name, name) != 0)
    {
        tmp = tmp ->next; //updating tmp value to the next value in the linked list
    }
    return tmp;
}
// function for deleting data from the table
person *delete_person(char *name)
{
    // Step 1: Calculate the hash index for the given name
    int index = hash(name);
    // Step 2: Initialize pointers to traverse the linked list
    person *tmp = hashtable[index]; // Pointer to the current node
    person *prev = NULL;             // Pointer to the previous node
    // Step 3: Traverse the linked list to find the person with the given name
    while ((tmp != NULL) && strcmp(tmp->name, name) != 0)
    {
        prev = tmp;         // Update prev to current node
        tmp = tmp->next;    // Move to the next node
    }
    // Step 4: Check if the person with the given name was found
    if (tmp == NULL) return NULL; // Person not found, return NULL 
    // Step 5: Delete the person
    if (prev == NULL)
    {
        // If the person to delete is the head of the linked list
        hashtable[index] = tmp->next; // Update the head to the next node
    }
    else
    {
        // If the person to delete is not the head
        prev->next = tmp->next; // Skip over the current node
    }
    // Step 6: Return a pointer to the deleted person
    return tmp;
}


