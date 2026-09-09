#include<stdio.h>
#include<ctype.h>
#include"hedder.h"



int main(int argc , char **argv)
{

    // to checking the argv count should be equal to 4 or not 
    if (argc!=4)
    {
        printf("ERROR: The arg should be ./a.out operand operator operand\n");
        return 0;
    }

int i = 0;
int flag = 1;

if (argv[1][0] == '+' || argv[1][0] == '-')
    i = 1;

if (argv[1][i] == '\0')
    flag = 0;

while (argv[1][i] != '\0')
{
    if (!isdigit(argv[1][i]))
    {
        flag = 0;
        break;
    }
    i++;
}

if (flag)
{
    printf("Valid operand: %s\n", argv[1]);
}
else
{
    printf("ERROR: Invalid operand: %s\n", argv[1]);
     return FAILURE;
}
   // to checking argv 2 is operator or not 

    if(argv[2][0]=='+'||
       argv[2][0]=='-'||
       argv[2][0]=='x'||
       argv[2][0]=='/')

        {
            printf("The operator is valid %s\n",argv[2]);
        }
        else
        {
            printf("ERROR:Pls check the operator %s\n",argv[2]);
            return FAILURE;
        }


        



    // to checking argv[3] is digit or not 
   i = 0;
flag = 1;

if (argv[3][0] == '+' || argv[3][0] == '-')
    i = 1;

if (argv[3][i] == '\0')
    flag = 0;

while (argv[3][i] != '\0')
{
    if (!isdigit(argv[3][i]))
    {
        flag = 0;
        break;
    }
    i++;
}

if (flag)
{
    printf("Valid operand: %s\n", argv[3]);
}
else
{
    printf("ERROR: Invalid operand: %s\n", argv[3]);
    return FAILURE;
}

    


    //finction calling
     func(argv);


    
      
       return SUCCESS;
    
}