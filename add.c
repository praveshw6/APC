#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int add(Dlist *tail1, Dlist *tail2, char sign1, char sign2)
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
            printf("0\n");
            return SUCCESS;
        }

        /* Bigger number decides subtraction */
        if (num1 > num2)
        {
            if (sign1 == '-')
                printf("-");

             return sub(tail2, tail1,sign1,sign2);
        }
        else
        {
            if (sign2 == '-')
                printf("-");

            return sub(tail2, tail1,sign1,sign2);
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
            return FAILURE;

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

    if (sign1 == '-')
        printf("-");

    print_final(head3, 3);
    printf("\n");

    return SUCCESS;
}