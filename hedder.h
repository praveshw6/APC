#ifndef HEDDER_H
#define HEDDER_H

#define SUCCESS 1
#define FAILURE 0

typedef struct LIST
{
    struct LIST *prev;
    int data;
    struct LIST *next;
} Dlist;

int func(char **argv);

void print_final(Dlist *head3, int);
void print_list(Dlist *head, int);
void print_list2(Dlist *head2, int);

Dlist *add(Dlist *t1, Dlist *t2, char s1, char s2);
Dlist *sub(Dlist *tail1, Dlist *tail2, char sign1, char sign2);
Dlist * mul(Dlist *tail1, Dlist *tail2);

int division(Dlist *tail1, Dlist *tail2);

#endif