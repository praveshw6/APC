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
void print_final(Dlist *head3,int );
void print_list(Dlist *head,int );
void print_list2(Dlist *head2,int );


int add(Dlist *t1, Dlist *t2, char s1, char s2);
int sub(Dlist *t1, Dlist *t2, char s1, char s2);
int mul(Dlist *tail1, Dlist *tail2);
int division(Dlist *tail1, Dlist *tail2);


#endif