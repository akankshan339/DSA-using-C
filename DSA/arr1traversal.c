//Traversal in array 
#include<stdio.h>
void insert(int ar[],int n)
{
    int i;
printf("Enter the array elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
}
void display(int ar[],int n)
{
    int i;
    printf("The array elements  are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
    int n,ar[5];
    printf("Enter the no of elements in array \n");
    scanf("%d",&n); 
    //can also enter n value from insert() but we also need n in display ()
    insert(ar,n);
    display(ar,n);
    return 0;
    
}