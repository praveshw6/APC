#include <stdio.h>
#include <stdlib.h>
#include "hedder.h"

int division(Dlist *tail1, Dlist *tail2)
{
    Dlist *head1;
    Dlist *head2;

    Dlist *temp1;
    Dlist *temp2;

    int num1 = 0;
    int num2 = 0;
    int quotient = 0;

    /* Move to HEAD */
    head1 = tail1;
    while (head1->prev != NULL)
        head1 = head1->prev;

    head2 = tail2;
    while (head2->prev != NULL)
        head2 = head2->prev;

    /* Ignore leading zeros */
    while (head1->data == 0 && head1->next != NULL)
        head1 = head1->next;

    while (head2->data == 0 && head2->next != NULL)
        head2 = head2->next;

    /*
     * Convert linked-list digits to integer
     * This simple version is suitable for normal-sized values.
     */
    temp1 = head1;

    while (temp1 != NULL)
    {
        num1 = num1 * 10 + temp1->data;
        temp1 = temp1->next;
    }

    temp2 = head2;

    while (temp2 != NULL)
    {
        num2 = num2 * 10 + temp2->data;
        temp2 = temp2->next;
    }

    /* Division by zero */
    if (num2 == 0)
    {
        printf("ERROR: Division by zero\n");
        return FAILURE;
    }

    /* Integer division */
    quotient = num1 / num2;

    printf("%d\n", quotient);

    return SUCCESS;
}