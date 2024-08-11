#include <stdio.h>
void display(int ar[], int n)
{ // Traversal in array
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}
int delete_element(int ar[], int n, int pos)
{ // deletion in array
    int i, j;
    if (pos > n)
    {
        printf("\nIndex not found \n");
        return -1;
    }
    else
    {
        for (i = pos - 1; i < n; i++)
        {
            ar[i] = ar[i + 1];
        }
        return 1;
    }
}
int main()
{
    int i, n, ar[10], ele, pos, capacity = 10;
    printf("Enter the no of elements in array \n");
    scanf("%d", &n);
    printf("Enter the array elements \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    // printf("Enter the element to be deleted :\n");
    // scanf("%d",&ele);
    printf("Enter the position element to be deleted :\n");
    scanf("%d", &pos);

    printf("Array elements before deletion are :\n");
    display(ar, n);

    int val = delete_element(ar, n, pos);

    if (val == 1)
    {
        printf("Deletion successfull!!! \n");
        n = n - 1;
        printf("\nArray after deletion of 1 element :\n");
        display(ar, n);
    }
    else
        printf("Deletion unsuccessfull!!! \n");
    return 0;
}