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
person *find_person(char *name);
person *delete_person(char *name);

int main(int argc, char **argv)
{
    init_hash_table();
    

    person max = {.name = "max", .age = 45};
    person min = {.name = "min", .age = 34};
    person ali = {.name = "ali", .age =24};
    person ahror = {.name = "ahrorrrrrrrrr", .age =64};
    person azam = {.name = "azam", .age =34};
    person abror = {.name = "abroreww", .age =22};

    insert_table(&max);
    insert_table(&min);
    insert_table(&ali);
    insert_table(&ahror);
    insert_table(&azam);
    insert_table(&abror);
    print_table();

    person *tmp = find_person("azam");
    if (tmp == NULL)
        return 0;
    else
        printf("found\nname =>  %s\nage=>%d\n", tmp->name, tmp->age);

    person *tmp2 = delete_person("min");
    if (tmp2 == NULL)
        return 0;
    else
        printf("deleted successfully\nname => %s\nage=>%d\n",tmp2->name, tmp2->age);
    print_table();
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
    printf("Table begin\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashtable[i] == NULL)
            printf("\t %i \t-------\n", i);
        else
            printf("\t %i \t%s\n", i, hashtable[i]->name);
    }
    printf("table finished\n");
}

bool insert_table(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hashtable[try] == NULL)
        {
            hashtable[try] = p;
            return true;
        }
    }
    return false;
}

person *find_person(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int tmp = (i + index) % TABLE_SIZE;
        if ((hashtable[tmp] != NULL) && strcmp(hashtable[tmp]->name, name) == 0)
        return hashtable[tmp], hashtable[tmp]->name, hashtable[tmp]->age;
        else
            return NULL;
    }
    
}

person *delete_person(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int tmp = (1 + index) % TABLE_SIZE;
        if ((hashtable[index] != NULL) && strcmp(hashtable[index]->name, name) == 0)
        {
        person *tmp = hashtable[index];
        hashtable[index] = NULL;
        return tmp;
        }
    }
    else
        return NULL;
}
