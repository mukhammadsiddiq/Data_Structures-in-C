#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct person {
    struct person *parents[2];
    char alleles[2];  // Changed to char array instead of char pointers
} person;

const int GENERATIONS = 3;  // Example number of generations to create
const int INDENT_LENGTH = 4;  // Indentation length for printing family tree

person *create_family(int generations);
char random_allele();
void free_family(person *p);
void print_family(person *p, int generation);
void print_indent(int generation);

int main(int argc, char **argv) {
    srand(time(0));  // Seed the random number generator

    person *family = create_family(GENERATIONS);
    print_family(family, 0);
    free_family(family); // free allocated memory   for family

    return 0;
}

person *create_family(int generations) {
    // Allocate memory for a new person
    person *new_p = malloc(sizeof(person));
    if (new_p == NULL) {
        return NULL;
    }

    if (generations > 1) {
        // Recursively create parents
        new_p->parents[0] = create_family(generations - 1);
        new_p->parents[1] = create_family(generations - 1);

        // Assign alleles based on parents' alleles
        new_p->alleles[0] = new_p->parents[0]->alleles[rand() % 2];
        new_p->alleles[1] = new_p->parents[1]->alleles[rand() % 2];
    } else {
        // Base case: no parents, generate random alleles
        new_p->parents[0] = NULL;
        new_p->parents[1] = NULL;
        new_p->alleles[0] = random_allele();
        new_p->alleles[1] = random_allele();
    }

    return new_p;
}

char random_allele() {
    int r = rand() % 3;
    if (r == 0) {
        return 'A';
    } else if (r == 1) {
        return 'B';
    } else {
        return 'O';
    }
}

void free_family(person *p) {
    if (p == NULL) {
        return;
    }
    // Recursively free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    // Free the person itself
    free(p);
}

void print_family(person *p, int generation) {
    if (p == NULL) {
        return;
    }

    // Print current person's alleles with indentation
    print_indent(generation);
    printf("Generation %d: %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Recursively print parents
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

void print_indent(int generation) {
    for (int i = 0; i < generation * INDENT_LENGTH; i++) {
        printf(" ");
    }
}
