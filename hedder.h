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
void print_final(Dlist *head3,int );
void print_list(Dlist *head,int );
void print_list2(Dlist *head2,int );

//void print_list(Dlist *head);
int add(Dlist *tail1,Dlist *tail2);


#endif