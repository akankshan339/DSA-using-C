//check whether a string is valid or not using stack 
//str=000111 is valid  str=00011 is invalid 
# include<stdio.h>
# include<string.h>
# define max 6
int isEmpty(int top)
{
    if(top==-1)
   return 1;
   else
   return -1;
}
int isFull(int top)
{
    if(top==max-1)
   return 1;
   else
   return -1;
}
void push(int stk[],int *top,int val)
{
    if(isFull((*top))==1)
    printf("stack is full\n");
    else
    {
         (*top)++;
        stk[*top]=val;
    }

}
void pop(int stk[],int *top)
{
    if(isEmpty((*top))==1)
    printf("stack is empty \n");
    else
    {
    int t=stk[*top];
   // printf("%d ",t);
    (*top)--;
    }
}
void display(int stk[],int top)
{
    int i=top;
    while(i!=-1)
    {
        printf("%d\n ",stk[top]);
        i--;
    }
}
int main()
{
   int stk[max],i=0,top=-1;
   char str[6];
   printf("Enter the string of 0's and 1's :\n");
  
   gets(str);
 //char str[]="00011";
    while(str[i]!='\0')
    {
       if(str[i]=='0')
       {
        push(stk,&top,0);
     
       }
       
       else
       {
        if(isEmpty(top)==1)
        {
        printf("Invalid \n");
        break;
       }
        else
        {
        pop(stk,&top);
        }
       }
       i++;
      
    }
   // display(stk,top);
    if(str[i]=='\0')
  {
    if(isEmpty(top)==1)
    printf("Valid string \n");
    else
    printf("Invalid string \n");
  }
    return 0;
}



   