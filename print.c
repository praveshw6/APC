#include<stdio.h>
#include<ctype.h>
#include"hedder.h"


//printing argv[1]
void print_list(Dlist *head1,int list_no1)
{
    Dlist *temp = head1;

    //printf("RESULT= ");

    while(temp != NULL)
    {
        printf("%d", temp->data);

        // if(temp->next != NULL)
        //     printf(" <-> ");

        temp = temp->next;
    }

   // printf(" <- TAIL1\n");
}

// printing argv[3]




// to printing final value of the addition
    void print_final(Dlist *head3,int list_no3)
    {
          Dlist *temp1 = head3;

     //printf("RESULT = ");

    while(temp1 != NULL)
    {
        printf("%d", temp1->data);

        //if(temp1->next != NULL)
           // printf(" <-> ");

        temp1 = temp1->next;
    }

    //printf(" <-TAIL3\n");
    }

