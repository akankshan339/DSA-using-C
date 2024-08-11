 #include<stdio.h>
void display(int ar[],int n)
{//Traversal in array
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}
int insert_element(int ar[],int n,int ele,int pos,int capacity)
{//insertion in array
    int i;
    if(n>=capacity)
    {
        return -1;
    }
   else{
    for(i=n-1;i>=pos;i--)
{
    ar[i+1]=ar[i];
}
ar[pos]=ele;
   return 1;
   }
}


int main()
{
    int i,n,ar[10],ele,pos,capacity=10;
    printf("Enter the no of elements in array \n");
    scanf("%d",&n); 
printf("Enter the array elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("Enter the element to be inserted :\n");
    scanf("%d",&ele);
    printf("Enter the position where u want element to be inserted :\n");
    scanf("%d",&pos);
    
   
   printf("Array elements before insertion are :\n");
   display(ar,n);
  int val=insert_element(ar,n,ele,pos,capacity);
  if(val==1)
  {
 printf("\nInsertion successfull !!!! \n");
  n=n+1;
    printf("\nArray after insertion of 1 element :\n");
    display(ar,n);
  }
  else
 printf("\nInsertion unsuccessfull !!!! \n");
    return 0;
    
}