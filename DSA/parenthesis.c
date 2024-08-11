//parenthesis matching round brackets
#include<stdio.h>
#include<string.h>
//# define MAX 2 //stack is full only 2 opening brackets will inside

# define MAX 10
int top=-1;

void push(char stk[],int val)
{
    if(top >= MAX-1)
    {
    printf("stack is full \n");
    }
    else
    {
        top++;
        stk[top]=val;
    }
}
char pop(char stk[])
{
 if(top==-1)
 {
     printf("stack is empty \n");
     return 'x';
 }
 else{
    char temp=stk[top];
    top--;
    return temp;
}

}
void display(char stk[])
{
    int i=top;
while(i>=0)
{
    printf("%c\n",stk[i]);
    i--;
}
}
// }
// void replace(int st[],int repvalue)
// {
//     if(top==-1)
//     {
//         printf("stack is empty \n underflow \n");
//     }
//     else
//     st[top]=repvalue;
// }

int main()
{
    char stk[5];
 //   char str[MAX]={'(','(',')',')'};
    char str[MAX]="')',')','(',')',')','(',')'";
    //printf("enter the expression :\n");
    //gets(str);
   // str=((()));
    int len=strlen(str);
    int i=0;
while(i<len)
{
if(str[i]=='(')
push(stk,str[i]);
else if(str[i]==')')
pop(stk);
i++;
}

    
   display(stk);
  char val=pop(stk);
  if(val=='x')
  {
    //  printf("stack is empty \n");
  }
  else
  {
   printf("poped value is %c \n",val);
   printf("stack after poping \n");
  }
   display(stk);
    
    return 0;
}
