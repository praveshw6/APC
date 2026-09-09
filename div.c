#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int division(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    int n1 = 0;
    int n2 = 0;

    /* Count digits */
    while (temp1 != NULL)
    {
        n1++;
        temp1 = temp1->prev;
    }

    while (temp2 != NULL)
    {
        n2++;
        temp2 = temp2->prev;
    }

    /* Check division by zero */
    temp2 = tail2;

    int zero = 1;

    while (temp2 != NULL)
    {
        if (temp2->data != 0)
        {
            zero = 0;
            break;
        }

        temp2 = temp2->prev;
    }

    if (zero)
    {
        printf("ERROR: Division by zero\n");
        return FAILURE;
    }

    /*
       If first number is smaller,
       swap the numbers.
       
       Example:
       10 / 123

       becomes:

       123 / 10
    */
    if (n1 < n2)
    {
        Dlist *temp = tail1;
        tail1 = tail2;
        tail2 = temp;

        int n = n1;
        n1 = n2;
        n2 = n;
    }

    /* Allocate arrays */
    int *num1 = malloc(n1 * sizeof(int));
    int *num2 = malloc(n2 * sizeof(int));
    int *quot = calloc(n1, sizeof(int));
    int *rem = calloc(n1 + 1, sizeof(int));

    if (num1 == NULL || num2 == NULL ||
        quot == NULL || rem == NULL)
    {
        free(num1);
        free(num2);
        free(quot);
        free(rem);

        return FAILURE;
    }

    /* Copy first number */
    temp1 = tail1;

    for (int i = n1 - 1; i >= 0; i--)
    {
        num1[i] = temp1->data;
        temp1 = temp1->prev;
    }

    /* Copy second number */
    temp2 = tail2;

    for (int i = n2 - 1; i >= 0; i--)
    {
        num2[i] = temp2->data;
        temp2 = temp2->prev;
    }

    /*
       rem stores the current remainder.
       rsize = number of digits in remainder.
    */
    int rsize = 0;

    /* Long division */
    for (int i = 0; i < n1; i++)
    {
        /* Bring down one digit */
        rem[rsize] = num1[i];
        rsize++;

        /* Remove leading zeros */
        while (rsize > 1 && rem[0] == 0)
        {
            for (int j = 0; j < rsize - 1; j++)
                rem[j] = rem[j + 1];

            rsize--;
        }

        /* Find quotient digit */
        while (rsize >= n2)
        {
            int greater = 0;
            int equal = 1;

            /* Remainder has more digits */
            if (rsize > n2)
            {
                greater = 1;
                equal = 0;
            }
            else
            {
                /* Compare remainder and divisor */
                for (int j = 0; j < n2; j++)
                {
                    if (rem[j] > num2[j])
                    {
                        greater = 1;
                        equal = 0;
                        break;
                    }

                    if (rem[j] < num2[j])
                    {
                        equal = 0;
                        break;
                    }
                }
            }

            /* Remainder is smaller */
            if (greater == 0 && equal == 0)
                break;

            /* Subtract divisor from remainder */
            int borrow = 0;

            int j1 = rsize - 1;
            int j2 = n2 - 1;

            while (j2 >= 0)
            {
                int value = rem[j1] - num2[j2] - borrow;

                if (value < 0)
                {
                    value = value + 10;
                    borrow = 1;
                }
                else
                {
                    borrow = 0;
                }

                rem[j1] = value;

                j1--;
                j2--;
            }

            /* Remove leading zeros */
            while (rsize > 1 && rem[0] == 0)
            {
                for (int j = 0; j < rsize - 1; j++)
                    rem[j] = rem[j + 1];

                rsize--;
            }

            quot[i]++;
        }
    }

    /* Find first non-zero quotient digit */
    int start = 0;

    while (start < n1 - 1 && quot[start] == 0)
        start++;

    /* Create result list */
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    for (int i = start; i < n1; i++)
    {
        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            free(num1);
            free(num2);
            free(quot);
            free(rem);

            return FAILURE;
        }

        new->data = quot[i];
        new->prev = tail3;
        new->next = NULL;

        if (tail3 != NULL)
            tail3->next = new;
        else
            head3 = new;

        tail3 = new;
    }

    /* Print answer */
    print_final(head3, 6);
    printf("\n");

    /* Free result list */
    temp1 = head3;

    while (temp1 != NULL)
    {
        Dlist *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    /* Free arrays */
    free(num1);
    free(num2);
    free(quot);
    free(rem);

    return SUCCESS;
}