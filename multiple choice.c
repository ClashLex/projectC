#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1,num2,choice;
    float result;
    printf("enter two numbers");
    scanf("%d%d",&num1,&num2);
    printf("1 for addition \n2 for subtration \n3 for multiplication \n 4 for division \n enter your choice");
    scanf("%d",&choice);
    if(choice==1)
    {
        result=num1+num2; printf("result=%d", result);
    }
    else if(choice==2)
    {
        result=num1-num2; printf("result=%d", result);
    }
    else if(choice==3)
    {
        result=num1*num2; printf("result=%d", result);
    }
    else if(choice==4)
    {
        result=num1/num2; printf("result=%d", result);
    }
    else { printf("you are a fool");
    }
}
