# include<stdio.h>
# include<string.h>

# define max 10
int isEmpty(int stk[],int top)
{
    if(top==-1)
    {
    printf("stack is empty \n");
    return 1;
    }
    else
    return -1;
}

int isFull(int stk[],int top)
{
    if(top==max-1)
    {
    printf("stack is full \n");
    return 1;
    }
    else
    return -1;
}

void push(int stk[],int *top,int val)
{
if(isFull(stk,top)==1)
printf("stack is full \n");
else
{
(*top)++;
stk[*top]=val;
}
}

int pop(int stk[],int *top)
{
if(isEmpty(stk,top)==1)
printf("stack is empty \n");
else
    {
        int temp=stk[*top];
        (*top)--;
        return  temp;
    }
}

void display(int stk[],int top)
{
    int i=top;
    while ((i>=0))
    {
        printf("%d \n",i);
        i--;
    }
}

int getParam(char a)
{
    switch(a)
    {
        case '(':return 1;
        case '{':return 2;
        case '[':return 3;
        case '<':return 4;
        case ')':return -1;
        case '}':return -2;
        case ']':return -3;
        case '>':return -4;
        default: return 0;
    }
}

int atTop(int stk[],int *top)
{
    return stk[*top];
}

int main()
{
    int top=-1,flag=0;
    int stk[max];
   char s[20]="([]}<>)";
   int len=strlen(s);
    int i=0;
    while(s[i]!='\0')
{
    int b=getParam(s[i]);
    if(b>0)
    push(stk,&top,b);
    else{
        if(isEmpty(stk,top)==1)
        {
            printf("unbalanced \n");
            flag=1;
            break;
        }
        else
        {
            int cb=atTop(stk,&top);
            if(abs(b)==cb)
            {
                pop(stk,&top);
            }
            else
            printf("balanced \n");
        } //else close
    } //else close
    i++;
    } // while close
return 0;
} 