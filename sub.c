#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int sub(Dlist *tail1, Dlist *tail2, char sign1, char sign2)
{
    Dlist *head4 = NULL;
    Dlist *tail4 = NULL;
    Dlist *temp1, *temp2, *p;
    int count1 = 0, count2 = 0;
    int cmp = 0;
    int data1, data2, borrow = 0, digit;

    /* -A - B = -(A + B) */
    if (sign1 == '-' && sign2 == '+')
    {
        printf("-");
        add(tail1, tail2, '+', '+');
        return SUCCESS;
    }

    /* A - (-B) = A + B */
    if (sign1 == '+' && sign2 == '-')
    {
        add(tail1, tail2, '+', '+');
        return SUCCESS;
    }

    /* -A - (-B) = B - A */
    if (sign1 == '-' && sign2 == '-')
    {
        return sub(tail2, tail1, '+', '+');
    }

    /* Find HEAD */
    temp1 = tail1;
    temp2 = tail2;

    while (temp1->prev != NULL)
        temp1 = temp1->prev;

    while (temp2->prev != NULL)
        temp2 = temp2->prev;

    /* Remove leading zeros */
    while (temp1->data == 0 && temp1->next != NULL)
        temp1 = temp1->next;

    while (temp2->data == 0 && temp2->next != NULL)
        temp2 = temp2->next;

    /* Count digits */
    p = temp1;
    while (p != NULL)
    {
        count1++;
        p = p->next;
    }

    p = temp2;
    while (p != NULL)
    {
        count2++;
        p = p->next;
    }

    /* Compare */
    if (count1 > count2)
        cmp = 1;
    else if (count1 < count2)
        cmp = -1;
    else
    {
        while (temp1 != NULL)
        {
            if (temp1->data != temp2->data)
            {
                cmp = (temp1->data > temp2->data) ? 1 : -1;
                break;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    /* Equal */
    if (cmp == 0)
    {
        printf("0\n");
        return SUCCESS;
    }

    /* Smaller - bigger */
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
        data1 = temp1->data - borrow;

        if (temp2 != NULL)
        {
            data2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
            data2 = 0;

        if (data1 < data2)
        {
            data1 += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        digit = data1 - data2;

        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = digit;
        new->prev = NULL;
        new->next = head4;

        if (head4 != NULL)
            head4->prev = new;
        else
            tail4 = new;

        head4 = new;

        temp1 = temp1->prev;
    }

    /* Remove leading zeros */
    while (head4->data == 0 && head4->next != NULL)
    {
        Dlist *temp = head4;
        head4 = head4->next;
        head4->prev = NULL;
        free(temp);
    }

    print_final(head4, 4);
    printf("\n");

    return SUCCESS;
}