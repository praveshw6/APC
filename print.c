#include<stdio.h>
#include<ctype.h>
#include"hedder.h"


//printing argv[1]
void print_list(Dlist *head1,int list_no1)
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

void print_list2(Dlist *head2,int llist_no2)
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
// to printing final value of the addition
    void print_final(Dlist *head3,int list_no3)
    {
          Dlist *temp1 = head3;

    printf("HEAD3 -> ");

    while(temp1 != NULL)
    {
        printf("%d", temp1->data);

        //if(temp1->next != NULL)
           // printf(" <-> ");

        temp1 = temp1->next;
    }

    printf(" <-TAIL3\n");
    }

