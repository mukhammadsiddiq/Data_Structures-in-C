#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

person *hashtable[TABLE_SIZE];

unsigned int hash(const char *name);
void init_hash_table();
void print_table();
bool insert_table(person *p);

int main(int argc, char **argv)
{
    init_hash_table();
    

    person max = {.name = "max", .age = 45};
    person min = {.name = "min", .age = 34};

    insert_table(&max);
    insert_table(&min);
    print_table();
    

 /*   printf("Name => %s %d\n",argv[1], hash(argv[1]));
    printf("Name => %s %d\n",argv[2], hash(argv[2]));
    printf("Name => %s %d\n",argv[3], hash(argv[3]));
    printf("Name => %s %d\n",argv[4], hash(argv[4]));
    printf("Name => %s %d\n",argv[5], hash(argv[5]));
    printf("Name => %s %d\n",argv[6], hash(argv[6]));
    printf("Name => %s %d\n",argv[7], hash(argv[7]));
    printf("Name => %s %d\n",argv[8], hash(argv[8]));
    printf("Name => %s %d\n",argv[9], hash(argv[9])); */
    return 0;
}

unsigned int hash(const char *name)
{
    unsigned int length = strlen(name);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value % TABLE_SIZE);
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // Table is empty
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashtable[i] == NULL)
            printf("\t %i \t-------\n", i);
        else
            printf("\t %i \t%s\n", i, hashtable[i]->name);
    }
}

bool insert_table(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hashtable[index] != NULL)
        return false;
    hashtable[index] = p;
    return true;
}
