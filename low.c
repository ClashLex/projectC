#include <stdio.h>
#include <stdlib.h>

int main(void)
{   int num1,num2;
     printf("enter two numbers");
     scanf("%d%d",&num1,&num2);
     if(num1>num2)
    { printf("the greatest number is%d",num1);}
   else 
   { printf("greatest number is%d",num2);}
    
    
    
    return EXIT_SUCCESS;
}