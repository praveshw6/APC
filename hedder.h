#ifndef HEDDER_H
#define HEDDER_H

#define SUCCESS 0
#define FAILURE 1

typedef struct LIST
{
    struct LIST *prev;
    int data;
    struct LIST *next;
} Dlist;
 

int func(char **argv);
void print_list(Dlist *head);
void print_list2(Dlist *head2);
void print_list(Dlist *head);

#endif