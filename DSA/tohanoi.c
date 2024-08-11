#include<stdio.h>
void move(int n,char src,char aux,char dest)
{
    if(n==0)
    return;
    move((n-1),src,dest,aux);
    printf("shift disk %d from %c to %c\n",n,src,dest);
    move((n-1),aux,src,dest);
}
int main()
{
    int n;
    printf("Enter how many disc you want to move:\n");
    scanf("%d",&n);
    move(n,'A','B','C');
    return 0;
}