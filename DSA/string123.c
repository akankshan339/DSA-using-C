//WACP to test whether a entered string over the symbol 1,2,3 is of the form 1^n2^n3^n  using array such that n>=1 . 
#include<stdio.h>
int main()
{
   int i=0 ,countzero=0, countone=0, counttwo=0;
   char str[10];
   printf("NAME : Akanksha Negi \nSec: A1 \nRoll No :04\n");
   printf("Enter the string of 0's 1's and 2's :\n");
   gets(str);
 //char str[]="00011";
    while(str[i]!='\0')
    {
       if(str[i]=='0') 
       countzero++;
       else if(str[i]=='1')
       countone++;
       else if (str[i]=='2' )
       counttwo++;
      
      i++;
      
    }
  
    if(str[i]=='\0')
  {
    if(countzero>=1 && countzero==countone && countone==counttwo)
    {
    printf("Valid string \n");
    printf("String is 0^%d 1^%d 2^%d",countzero,countone,counttwo);
  }
    else
    {
    printf("Invalid string \n");
   printf("String is 0^%d 1^%d 2^%d",countzero,countone,counttwo);
  }
  }
    return 0;
}
