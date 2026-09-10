#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int division(Dlist *tail1, Dlist *tail2)
{
    int quotient = 0;
    int count1, count2;
    Dlist *temp;

    count1 = 0;
    temp = tail1;

    while (temp)
    {
        count1++;
        temp = temp->prev;
    }

    count2 = 0;
    temp = tail2;

    while (temp)
    {
        count2++;
        temp = temp->prev;
    }

    /* Division by zero */
    temp = tail2;

    while (temp->prev)
        temp = temp->prev;

    if (temp->data == 0)
    {
        printf("ERROR: Division by zero\n");
        return FAILURE;
    }

    /* If dividend has fewer digits, swap */
    if (count1 < count2)
    {
        temp = tail1;
        tail1 = tail2;
        tail2 = temp;

        count1 = count1 + count2;
        count2 = count1 - count2;
        count1 = count1 - count2;
    }

    /* Repeated subtraction */
    while (1)
    {
        count1 = 0;
        temp = tail1;

        while (temp)
        {
            count1++;
            temp = temp->prev;
        }

        if (count1 < count2)
            break;

        tail1 = sub(tail1, tail2, '+', '+');

        if (tail1 == NULL)
            return FAILURE;

        quotient++;
    }

    printf("Quotient = %d\n", quotient);

    //return SUCCESS;
}