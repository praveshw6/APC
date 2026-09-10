#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

Dlist *add(Dlist *tail1, Dlist *tail2, char sign1, char sign2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    int carry = 0;

    /* Different signs */
    if (sign1 != sign2)
    {
        int num1 = 0;
        int num2 = 0;

        temp1 = tail1;
        temp2 = tail2;

        while (temp1 != NULL)
        {
            num1 = num1 * 10 + temp1->data;
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            num2 = num2 * 10 + temp2->data;
            temp2 = temp2->next;
        }

        /* Equal numbers */
        if (num1 == num2)
        {
            Dlist *new_node = malloc(sizeof(Dlist));

            if (new_node == NULL)
                return NULL;

            new_node->data = 0;
            new_node->prev = NULL;
            new_node->next = NULL;

            return new_node;
        }

        /* Bigger number decides subtraction */
        if (num1 > num2)
        {
            return sub(tail1, tail2, sign1, sign2);
        }
        else
        {
            return sub(tail2, tail1, sign1, sign2);
        }
    }

    /* Same signs -> addition */
    while (temp1 != NULL || temp2 != NULL || carry)
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

        Dlist *new_node = malloc(sizeof(Dlist));

        if (new_node == NULL)
            return NULL;

        new_node->data = digit;
        new_node->prev = NULL;
        new_node->next = head3;

        if (head3 != NULL)
        {
            head3->prev = new_node;
        }
        else
        {
            tail3 = new_node;
        }

        head3 = new_node;
    }

    /* Return TAIL */
    print_final(head3,5);
}