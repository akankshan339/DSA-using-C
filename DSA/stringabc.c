//WACP testt whether a given string is in the form  of a^1 b^j c^k  such thatt i=j+=k; and i>=1,j>=1,k>=1
#include<stdio.h>
# define max 5
#include<stdlib.h>
int isEmpty(int top)
{
    if(top == -1)
    return 1;
    else
    return -1;
}
int isFull(int top)
{
    if(top == max-1)
    return 1;
    else
    return -1;
}
void push(char stk[],char ch, int *top)
{
if(isFull((*top))==1)
printf("Stack is full\n ");
else
{
    (*top++);
    stk[*top]=ch;
}
}

void pop(char stk[], int *top)
{
    char ch;
if(isEmpty((*top))==1)
{
//printf("Stack is Empty\n ");
}
else
{
     ch=stk[*top];
    (*top--);
   }
}


int main()

{
    int top=-1 ,i=0;
    char str[10],stk[10];
    printf("NAME : Akanksha Negi \nSec: A1 \nRoll No :04\n");
    printf("Enter string :\n");
    gets(str);
   /* for(int i=0;i<5;i++)
    {
        scanf("%c",&str[i]);
    }
    i=0; */
    while(str[i]!='\0')
    {
        if(str[i]=='a')
         push(stk,str[i],&top);
      /* else
        {
            if(isEmpty(top)==1)
            {
            printf("Invalid  \n");
            break;
            } */
            else
            pop(stk,&top);
       // }
         i++;

    }

 if(str[i]=='\0')
  {
    if(isEmpty(top)==1) 

        printf("Valid String \n");
        else
         printf("Invalid String \n");
    
  }
    return 0;
}

