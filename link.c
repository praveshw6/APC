#include<stdio.h>
#include<ctype.h>
#include"hedder.h"
#include<stdlib.h>

Dlist *head1 = NULL;
Dlist *tail1 = NULL;

int func(char **argv)
{
    char *s = argv[1];
    int i = 0;

    /* Skip + or - sign */
    if (s[0] == '+' || s[0] == '-')
        i = 1;

    while (s[i] != '\0')
    {
        char ch = s[i];

        Dlist *opr1 = malloc(sizeof(Dlist));

        if (opr1 == NULL)
            return FAILURE;

        opr1->data = ch - '0';

        if (head1 == NULL)
        {
            head1 = tail1 = opr1;
            opr1->prev = NULL;
            opr1->next = NULL;
        }
        else
        {
            tail1->next = opr1;
            opr1->prev = tail1;
            opr1->next = NULL;
            tail1 = opr1;
        }

        i++;
    }


    /* Linked list of argv[3] */

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    char *s3 = argv[3];
    int j = 0;

    /* Skip + or - sign */
    if (s3[0] == '+' || s3[0] == '-')
        j = 1;

    while (s3[j] != '\0')
    {
        char chh = s3[j];

        Dlist *opr2 = malloc(sizeof(Dlist));

        if (opr2 == NULL)
            return FAILURE;

        opr2->data = chh - '0';

        if (head2 == NULL)
        {
            head2 = tail2 = opr2;
            opr2->prev = NULL;
            opr2->next = NULL;
        }
        else
        {
            tail2->next = opr2;
            opr2->prev = tail2;
            opr2->next = NULL;
            tail2 = opr2;
        }

        j++;
    }


    print_list(head1, 1);
    printf("\n");

    print_list(head2, 2);
    printf("\n");


    /* Operations */

    if (argv[2][0] == '+')
    {
        add(tail1, tail2, argv[1][0], argv[3][0]);
    }
    else if (argv[2][0] == '-')
    {
        sub(tail1, tail2, argv[1][0], argv[3][0]);
        return SUCCESS;
    }
    else if (argv[2][0] == 'x')
    {
        mul(tail1, tail2);
        return SUCCESS;
    }
    else if (argv[2][0] == '/')
    {
        division(tail1, tail2);
        return SUCCESS;
    }

    return SUCCESS;
}