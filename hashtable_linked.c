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
    char *name;
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
    if (tmp2 == NULL) // the same checking if it is empty or no
        printf("Person not found for deletion.\n");
    else
        printf("Deleted successfully\nName: %s\nAge: %d\n", tmp2->name, tmp2->age);
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
        if(hashtable == NULL)
            printf("\t %i \t-------\n", i);
        else
        {
            printf("\t %i \t");
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

