#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"
int sub(Dlist *tail1, Dlist *tail2)
{
    Dlist *head4 = NULL;
    Dlist *tail4 = NULL;

    Dlist *temp1;
    Dlist *temp2;
    Dlist *t1;
    Dlist *t2;

    int count1 = 0;
    int count2 = 0;
    int cmp = 0;

    int data1;
    int data2;
    int borrow = 0;
    int digit;

    /* Count digits of first number */
    t1 = tail1;

    while (t1 != NULL)
    {
        count1++;
        t1 = t1->prev;
    }

    /* Count digits of second number */
    t2 = tail2;

    while (t2 != NULL)
    {
        count2++;
        t2 = t2->prev;
    }

    /* Compare number of digits */
    if (count1 > count2)
    {
        cmp = 1;
    }
    else if (count1 < count2)
    {
        cmp = -1;
    }
    else
    {
        /* Same number of digits - compare digit by digit */
        t1 = tail1;
        t2 = tail2;

        while (t1 != NULL && t2 != NULL)
        {
            if (t1->data > t2->data)
            {
                cmp = 1;
                break;
            }
            else if (t1->data < t2->data)
            {
                cmp = -1;
                break;
            }

            t1 = t1->prev;
            t2 = t2->prev;
        }
    }

    /* Both numbers are equal */
    if (cmp == 0)
    {
        printf("0\n");
        return SUCCESS;
    }

    /* If first number is smaller, swap them */
    if (cmp < 0)
    {
        temp1 = tail2;
        temp2 = tail1;

        printf("-");
    }
    else
    {
        temp1 = tail1;
        temp2 = tail2;
    }

    /* Subtraction */
    while (temp1 != NULL)
    {
        data1 = temp1->data;
        temp1 = temp1->prev;

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            data2 = 0;
        }

        /* Apply borrow */
        data1 = data1 - borrow;

        if (data1 < data2)
        {
            data1 = data1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        digit = data1 - data2;

        /* Create new node */
        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = digit;
        new->prev = NULL;
        new->next = NULL;

        /* Insert at beginning */
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



