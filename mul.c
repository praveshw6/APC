#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"      
int mul(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *head5 = NULL;
    Dlist *tail5 = NULL;

    int carry, digit, product;
    int shift = 0;

    /* Result array for easier multiplication */
    int result[1000] = {0};
    int i = 0, j = 0;

    /* Count digits in first number */
    temp1 = tail1;
    while (temp1 != NULL)
    {
        i++;
        temp1 = temp1->prev;
    }

    /* Count digits in second number */
    temp2 = tail2;
    while (temp2 != NULL)
    {
        j++;
        temp2 = temp2->prev;
    }

    /* Store first number in array */
    int num1[i];
    int num2[j];

    temp1 = tail1;
    for (int k = i - 1; k >= 0; k--)
    {
        num1[k] = temp1->data;
        temp1 = temp1->prev;
    }

    /* Store second number in array */
    temp2 = tail2;
    for (int k = j - 1; k >= 0; k--)
    {
        num2[k] = temp2->data;
        temp2 = temp2->prev;
    }

    /* Multiplication */
    for (int a = i - 1; a >= 0; a--)
    {
        carry = 0;

        for (int b = j - 1; b >= 0; b--)
        {
            int pos = (i - 1 - a) + (j - 1 - b);

            product = num1[a] * num2[b] + result[pos] + carry;

            result[pos] = product % 10;
            carry = product / 10;
        }

        if (carry)
            result[(i - 1 - a) + j] += carry;
    }

    /* Find actual result size */
    int size = i + j;

    while (size > 1 && result[size - 1] == 0)
        size--;

    /* Create result linked list */
    for (int k = size - 1; k >= 0; k--)
    {
        Dlist *new = malloc(sizeof(Dlist));

        new->data = result[k];
        new->next = NULL;
        new->prev = NULL;

        if (head5 == NULL)
        {
            head5 = new;
            tail5 = new;
        }
        else
        {
            new->next = head5;
            head5->prev = new;
            head5 = new;
        }
    }
    print_final(head5, 5);

    return SUCCESS;

}