#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

Dlist *sub(Dlist *tail1, Dlist *tail2, char sign1, char sign2)
{
    Dlist *t1 = tail1;
    Dlist *t2 = tail2;
    Dlist *head = NULL;
    Dlist *tail = NULL;

    int borrow = 0;
    int n1 = 0;
    int n2 = 0;
    int cmp = 0;

    while (t1->prev)
        t1 = t1->prev;

    while (t2->prev)
        t2 = t2->prev;

    while (t1->data == 0 && t1->next)
        t1 = t1->next;

    while (t2->data == 0 && t2->next)
        t2 = t2->next;

    Dlist *p = t1;

    while (p)
    {
        n1++;
        p = p->next;
    }

    p = t2;

    while (p)
    {
        n2++;
        p = p->next;
    }

    if (n1 > n2)
        cmp = 1;
    else if (n1 < n2)
        cmp = -1;
    else
    {
        while (t1)
        {
            if (t1->data > t2->data)
            {
                cmp = 1;
                break;
            }

            if (t1->data < t2->data)
            {
                cmp = -1;
                break;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    if (cmp == 0)
    {
        Dlist *new = malloc(sizeof(Dlist));

        if (!new)
            return NULL;

        new->data = 0;
        new->prev = NULL;
        new->next = NULL;

        return new;
    }

    if (cmp < 0)
    {
        Dlist *temp = tail1;
        tail1 = tail2;
        tail2 = temp;

        if (sign1 == '+' && sign2 == '+')
            printf("-");
    }

    t1 = tail1;
    t2 = tail2;

    while (t1)
    {
        int a = t1->data - borrow;
        int b = 0;

        if (t2)
            b = t2->data;

        if (a < b)
        {
            a = a + 10;
            borrow = 1;
        }
        else
            borrow = 0;

        Dlist *new = malloc(sizeof(Dlist));

        if (!new)
            return NULL;

        new->data = a - b;
        new->prev = NULL;
        new->next = head;

        if (head)
            head->prev = new;
        else
            tail = new;

        head = new;

        t1 = t1->prev;

        if (t2)
            t2 = t2->prev;
    }

    while (head->data == 0 && head->next)
    {
        Dlist *temp = head;
        head = head->next;
        free(temp);
        head->prev = NULL;
    }

    return tail;
}