#include<stdio.h>
#include<ctype.h>
#include"hedder.h"
#include <stdlib.h>



 Dlist *head1=NULL;
 Dlist *tail1=NULL;



int func(char **argv)
{
    char *s = argv[1];
    int i = 0;

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
            tail1->next = opr1;  // old tail points to new node
            opr1->prev = tail1;  // new node points back to old tail
            opr1->next=NULL;
            tail1 = opr1;        // move tail to new node
        }

        i++;
    }



      // to linked list of argv[3]
    Dlist *head2=NULL;
    Dlist *tail2=NULL;

      char *s3 = argv[3];
       int j = 0;

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
            tail2->next = opr2;  // old tail points to new node
            opr2->prev = tail2;  // new node points back to old tail
            opr2->next=NULL;
            tail2 = opr2;        // move tail to new node
        }

        j++;
    }
  


    print_list(head1,1);
     printf("\n");
     print_list2(head2,2);
     printf("\n");
     
// to doing the operations 

    if(argv[2][0]=='+')
    {
        add(tail1,tail2);// calling the addition function
        
    }
     else  if(argv[2][0]=='-')
    {
        sub(tail1,tail2);
        return SUCCESS;
    }
    //  else if(argv[2][0]=='*')
    // {
    //    MUL(tail1,tail2);
    //     return SUCCESS;
    // }
    // else  if(argv[2][0]=='/')
    // {
    //     DIV(tail1,tail2);
    //     return SUCCESS;
    // }



     
     //print_final(head3);






   


    return SUCCESS;

}






