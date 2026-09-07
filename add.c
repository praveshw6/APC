#include<stdio.h>
#include<ctype.h>
#include"hedder.h"
#include <stdlib.h>


int add(Dlist *tail1, Dlist *tail2)//to passing the tail adress
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *head3 = NULL;//create and set head and tail as null
    Dlist *tail3 = NULL;

    int carry = 0;// set carry as zero 

    while (temp1 != NULL || temp2 != NULL || carry)//loop run until both reaching null
    {
        int data1 = 0;
        int data2 = 0;

        if (temp1 != NULL)
        {
            data1 = temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }

        int digit = data1 + data2 + carry;

        carry = digit / 10;
        digit = digit % 10;

        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = digit;
        new->prev = NULL;
        new->next = NULL;

        /* Insert at beginning */
        if (head3 == NULL)
        {
            head3 = tail3 = new;
        }
        else
        {
            new->next = head3;
            head3->prev = new;
            head3 = new;
        }
    }

    
    print_final(head3,3);
    printf("\n");

    return SUCCESS;
}

