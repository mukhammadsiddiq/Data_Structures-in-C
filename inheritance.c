// simulate genetic inheritance
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct person{
    struct person *parents[2];
    char *alleles[2];
}

const int generations = 2;
const int INTEND_LENGTH = 2;

person *create_family(int generations);
char random_allele();

int main(int argc, char **argv){

}

person *create_family(int generations){
    person *new_p = malloc(sizeof(person));
    if(new_p == NULL) return NULL;
    if(generations > 1){
        parent0 = create_family(generations - 1);
        parent1 = create_family(generations - 1);
    }
    else{
        new_p->parents[0] = NULL;
        new_p->parents[1] = NULL;
        new_p->alleles[0] = random_allele();
        new_p->alleles[1] = random_allele();
    }
    return NULL;
}

char random_allele() {
    int t = rand() % 3;
    if (t == 0) return 'A';
    else if (t == 1) return 'B';
    else return 0;
}
