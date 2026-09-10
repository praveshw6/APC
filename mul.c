#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

Dlist *mul(Dlist *tail1, Dlist *tail2)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    int count1 = 0;
    int count2 = 0;

    /* Count digits in first number */
    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->prev;
    }

    /* Count digits in second number */
    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->prev;
    }

    /* Arrays for storing digits */
    int *arr1 = malloc(count1 * sizeof(int));
    int *arr2 = malloc(count2 * sizeof(int));
    int *result = calloc(count1 + count2, sizeof(int));

    if (arr1 == NULL || arr2 == NULL || result == NULL)
    {
        free(arr1);
        free(arr2);
        free(result);
        return FAILURE;
    }

    /* Copy first number into array */
    temp1 = tail1;

    for (int i = count1 - 1; i >= 0; i--)
    {
        arr1[i] = temp1->data;
        temp1 = temp1->prev;
    }

    /* Copy second number into array */
    temp2 = tail2;

    for (int i = count2 - 1; i >= 0; i--)
    {
        arr2[i] = temp2->data;
        temp2 = temp2->prev;
    }

    /*
     * Multiplication
     *
     * Exaple:
     *       1 2
     *   x 1 2 3
     *   --------
     *       ...
     */
    for (int i = count1 - 1; i >= 0; i--)
    {
        for (int j = count2 - 1; j >= 0; j--)
        {
            result[i + j + 1] =
                result[i + j + 1] + arr1[i] * arr2[j];
        }
    }

    /* Handle carry */
    for (int i = count1 + count2 - 1; i > 0; i--)
    {
        result[i - 1] =
            result[i - 1] + result[i] / 10;

        result[i] = result[i] % 10;
    }

    /* Remove leading zeros */
    int start = 0;

    while (start < count1 + count2 - 1 && result[start] == 0)
    {
        start++;
    }

    /* Create result doubly linked list */
    for (int i = start; i < count1 + count2; i++)
    {
        Dlist *new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            free(arr1);
            free(arr2);
            free(result);
            return FAILURE;
        }

        new->data = result[i];
        new->prev = NULL;
        new->next = NULL;

        if (head3 == NULL)
        {
            head3 = new;
            tail3 = new;
        }
        else
        {
            new->prev = tail3;
            tail3->next = new;
            tail3 = new;
        }
    }

    /* Print multiplication result */
    print_final(head3,5);
    /* Free arrays */
    free(arr1);
    free(arr2);
    free(result);

    /* Free result list */
    temp1 = head3;

    while (temp1 != NULL)
    {
        Dlist *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

   
}