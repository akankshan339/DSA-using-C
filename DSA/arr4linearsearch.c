 #include<stdio.h>
void display(int ar[],int n)
{//Traversal in array
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}
int search_element(int ar[],int n,int ele)
{// liner searching in array
    int i;
    for(i=0;i<n;i++)
{
    if(ar[i]==ele)
        return i;
    }
return -1;
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
   
   printf("Array elements are :\n");
   display(ar,n);
    printf("\nEnter the element to be searched :\n");
    scanf("%d",&ele);
   // int N=sizeof(ar)/sizeof(ar[0]);
  int ind=search_element(ar,n,ele);
 if(ind!=-1)
  {
    printf("Search successfull!!! \n");
printf("Element %d to be found at index %d ",ele,ind);
  }
  else
  printf("Search unsuccessfull!!!  \n");

return 0;
    
}