// Program to implement Queue using Stack in C.  
#include<stdio.h>  
#define N 5  
int stack1[5], stack2[5]; // declaration of two stacks  
// declaration of top variables.  
int top1=-1, top2=-1;   
int count=0;  
// inserting the elements in stack1.  
void push1(int data)  
{  
// Condition to check whether the stack1 is full or not.    
 if(top1==N-1)  
{  
   printf("\n Stack is overflow...");  
}  
else  
{  
   top1++;   // Incrementing the value of top1  
   stack1[top1]=data;  // pushing the data into stack1  
}  
}  
// Removing the elements from the stack1.  
int pop1()  
{  
// Condition to check whether the stack1 is empty or not.    
if(top1==-1)  
{  
   printf("\nStack is empty..");  
}  
else  
{  
   int a=stack1[top1];  // Assigning the topmost value of stack1 to 'a' variable.   
   top1--;  // decrementing the value of top1.  
   return a;   
}  
}   
// pushing the data into the stack2.  
void push2(int x)  
{  
//  Condition to check whether the stack2 is full or not  
if(top2==N-1)  
{  
   printf("\nStack is full..");  
}  
else  
{  
    top2++;   // incrementing the value of top2.  
    stack2[top2]=x;  // assigning the 'x' value to the Stack2  
  
}  
}   
// Removing the elements from the Stack2  
int pop2()  
{  
   int element = stack2[top2];  // assigning the topmost value to element  
   top2--;  // decrement the value of top2  
   return element;  
}   
void enqueue(int x)  
{  
    push1(x);  
    count++;  
}  
void dequeue()  
{  
   if((top1==-1) && (top2==-1))  
{  
   printf("\nQueue is empty");  
}  
else  
{  
  for(int i=0;i<count;i++)  
  {  
     int element = pop1();  
     push2(element);  
  }  
int b= pop2();  
printf("\nThe dequeued element are %d ", b);  
//printf("\n");  
count--;  
for(int i=0;i<count;i++)  
{  
   int a = pop2();  
   push1(a);   
}  
}}   
void display()  
{  
   for(int i=0;i<=top1;i++)  
  {  
     printf("%d , ", stack1[i]);  
  }  
}  
void main()  
{  
   enqueue(10);  
   enqueue(20);  
   enqueue(30);  
   enqueue(40);
   printf("elements of queue are:\n");
   display();  
   dequeue();  
   dequeue();  
   dequeue(); 
   dequeue();  
}  
// Program to implement Queue using Stack in C.  
#include<stdio.h>  
#define N 5  
int stack1[5], stack2[5]; // declaration of two stacks  
// declaration of top variables.  
//int top1=-1, top2=-1;   
//int count=0;  
// inserting the elements in stack1.  
void push1(int data,int *top1)  
{  
// Condition to check whether the stack1 is full or not.    
 if(*top1==N-1)  
{  
   printf("\n Stack is overflow...");  
}  
else  
{  
   (*top1)++;   // Incrementing the value of top1  
   stack1[*top1]=data;  // pushing the data into stack1  
}  
}  
// Removing the elements from the stack1.  
int pop1(int *top1)  
{  
// Condition to check whether the stack1 is empty or not.    
if(*top1==-1)  
{  
   printf("\nStack is empty..");  
}  
else  
{  
   int a=stack1[*top1];  // Assigning the topmost value of stack1 to 'a' variable.   
   (*top1)--;  // decrementing the value of top1.  
   return a;   
}  
}   
// pushing the data into the stack2.  
void push2(int x,int *top2)  
{  
//  Condition to check whether the stack2 is full or not  
if(*top2==N-1)  
{  
   printf("\nStack is full..");  
}  
else  
{  
    (*top2)++;   // incrementing the value of top2.  
    stack2[*top2]=x;  // assigning the 'x' value to the Stack2  
  
}  
}   
// Removing the elements from the Stack2  
int pop2()  
{  
   int element = stack2[top2];  // assigning the topmost value to element  
   top2--;  // decrement the value of top2  
   return element;  
}   
void enqueue(int x,int *count,int *top1)  
{  
    push1(x,&top1);  
    (*count)++;  
}  
void dequeue(int *top1,int *top2,int *count)  
{  
   if((*top1==-1) && (*top2==-1))  
{  
   printf("\nQueue is empty");  
}  
else  
{  
  for(int i=0;i<(*count);i++)  
  {  
     int no = pop1(&top1);  
     push2(no,top2);  
  }  
int n= pop2();  
printf("\nThe dequeued element are %d ", n);  
//printf("\n");  
(*count)--;  
for(int i=0;i<(*count);i++)  
{  
   int a = pop2();  
   push1(a,top1);   
}  
}}   
void display(int top1,int stack1[])  
{  
   for(int i=0;i<=top1;i++)  
  {  
     printf("%d , ", stack1[i]);  
  }  
}  

void main()  
{  
    int count =0 ,top1=-1, top2=-1;
   enqueue(10,&count,&top1);  
   enqueue(20,&count,&top1);  
   enqueue(30,&count,&top1);  
   enqueue(40,&count,&top1);
   printf("elements of queue are:\n");
   display(top1,stack1);  
   dequeue(&top1,&top2,&count);  
   dequeue(&top1,&top2,&count);  
   dequeue(&top1,&top2,&count); 
   dequeue(&top1,&top2,&count);  
}  