#include<stdio.h>
#include<ctype.h>
#include"hedder.h"


//printing argv[1]
void print_list(Dlist *head1)
{
    Dlist *temp = head1;

    printf("HEAD1 -> ");

    while(temp != NULL)
    {
        printf("%d", temp->data);

        if(temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" <- TAIL1\n");
}

// printing argv[3]

void print_list2(Dlist *head2)
{
    Dlist *temp = head2;

    printf("HEAD2 -> ");

    while(temp != NULL)
    {
        printf("%d", temp->data);

        if(temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf(" <- TAIL2\n");

}