#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// defining the name max characters
#define MAX_NAME 256
// defining the table size as a 10 rows
#define TABLE_SIZE 10
#define DELETED_NODE (person *) (0xFFFFFFFFFFFFFFFUL)
// creating a person struct
typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

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
    insert_table(&max); // random examples
    insert_table(&min); // random examples
    insert_table(&ali); // random examples
    insert_table(&ahror); // random examples
    insert_table(&azam); // random examples
    insert_table(&abror); // random examples
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
// function for hashing 
unsigned int hash(const char *name)
{
    // Initialize the hash value to 0
    unsigned int hash_value = 0;
    // Iterate through each character in the string until the null terminator is encountered
    while (*name)
    {
        // Bitwise left shift the current hash value by 5 bits (equivalent to multiplying by 32) 
        // and add the ASCII value of the current character
        hash_value = (hash_value << 5) + *name++;
        // Move to the next character in the string
    }
    // Return the hash value modulo the size of the hash table to ensure it falls within the table's bounds
    return hash_value % TABLE_SIZE;
}

// initializes the hash table with the NULL
void init_hash_table()
{
    // looping throw each table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
}

//function for printing the table 
void print_table()
{
    printf("Table begin\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // checks if the row is empty or not
        if (hashtable[i] == NULL)
            printf("\t %i \t-------\n", i);
        else if (hashtable[i] == DELETED_NODE)
            printf("\t %i \t---<DELETED PERSON>----\n", i);
        else
            printf("\t %i \t%s\n", i, hashtable[i]->name);
    }
    printf("Table finished\n");
}

// insert data to the table 
bool insert_table(person *p)
{
    //checks if p is empty or not 
    if (p == NULL) return false;
    int index = hash(p->name); // calling hash functions in order to analyze for which row to insert the given data
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // if row which belongs to that data is not empty, it will checks next and next rows , it means open addresing
        int try = (i + index) % TABLE_SIZE;
        if (hashtable[try] == NULL  || hashtable[try] == DELETED_NODE )
        {
            hashtable[try] = p;
            return true;
        }
    }
    return false; // Table is full
}

person *find_person(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int tmp = (i + index) % TABLE_SIZE;
        if (hashtable[tmp] == NULL)
            return NULL; // Person not found
        if (hashtable[tmp] == DELETED_NODE)
            continue; // Skip deleted nodes
        if (strcmp(hashtable[tmp]->name, name) == 0)
            return hashtable[tmp]; // Person found
    }
    return NULL; // Person not found
}

person *delete_person(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int tmp = (i + index) % TABLE_SIZE;
        if (hashtable[tmp] == NULL)
            return NULL; // Person not found for deletion
        if (hashtable[tmp] == DELETED_NODE)
            continue; // Skip deleted nodes
        if (strcmp(hashtable[tmp]->name, name) == 0)
        {
            person *temp = hashtable[tmp];
            hashtable[tmp] = DELETED_NODE;
            return temp; // Person found and deleted
        }
    }
    return NULL; // Person not found for deletion
}
