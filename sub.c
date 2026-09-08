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

    /* Go to HEAD of both numbers */
    t1 = tail1;
    while (t1->prev != NULL)
        t1 = t1->prev;

    t2 = tail2;
    while (t2->prev != NULL)
        t2 = t2->prev;

    /*
     * Ignore leading zeros
     *
     * 000011 -> 11
     * 0012   -> 12
     */
    while (t1->data == 0 && t1->next != NULL)
        t1 = t1->next;

    while (t2->data == 0 && t2->next != NULL)
        t2 = t2->next;

    /* Count actual digits */
    Dlist *p = t1;

    while (p != NULL)
    {
        count1++;
        p = p->next;
    }

    p = t2;

    while (p != NULL)
    {
        count2++;
        p = p->next;
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
        /* Same number of digits */
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

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    /* Both numbers are equal */
    if (cmp == 0)
    {
        printf("0\n");
        return SUCCESS;
    }

    /*
     * If first number is smaller,
     * calculate second - first
     */
    if (cmp < 0)
    {
        temp1 = tail2;
        temp2 = tail1;

        /* Move to last non-zero-relevant digit */
        while (temp1->next != NULL)
            temp1 = temp1->next;

        while (temp2->next != NULL)
            temp2 = temp2->next;

        printf("-");
    }
    else
    {
        temp1 = tail1;
        temp2 = tail2;
    }

    /* Subtraction from right to left */
    while (temp1 != NULL)
    {
        data1 = temp1->data;

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            data2 = 0;
        }

        temp1 = temp1->prev;

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

    /* Remove leading zeros from result */
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