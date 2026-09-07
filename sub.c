#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int sub(Dlist *tail1, Dlist *tail2)
{
    Dlist *head4 = NULL;
    Dlist *tail4 = NULL;

    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int data1 = 0;
    int data2 = 0;
    int borrow = 0;
    int digit;

    while (temp1 != NULL)
    {
        /* Get first number digit */
        data1 = temp1->data;
        temp1 = temp1->prev;

        /* Get second number digit */
        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            data2 = 0;
        }

        /* Apply previous borrow */
        data1 = data1 - borrow;

        /* Borrow required */
        if (data1 < data2)
        {
            data1 = data1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Calculate digit */
        digit = data1 - data2;

        /* Create node */
        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = digit;
        new->prev = NULL;
        new->next = NULL;

        /* Insert at HEAD */
        if (head4 == NULL)
        {
            head4 = new;
            tail4 = new;
        }
        else
        {
            new->next = head4;
            head4->prev = new;
            head4 = new;
        }
    }

    /* Remove leading zeros */
    while (head4 != NULL &&
           head4->data == 0 &&
           head4->next != NULL)
    {
        Dlist *temp = head4;

        head4 = head4->next;
        head4->prev = NULL;

        free(temp);
    }

    print_final(head4, 4);

    return SUCCESS;
}