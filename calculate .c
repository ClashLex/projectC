#include <stdio.h>  
  
int main(void)  
{  
    int num1, num2, choice;  
    int result;  

    printf("enter two numbers");  
    scanf("%d%d", &num1, &num2);  

    printf("1 for addition \n2 for subtration \n3 for multiplication \n4 for division \nenter your choice");  
    scanf("%d", &choice);  

    if(choice == 1)  
    {  
        result = num1 + num2;  
        printf("result=%d", result);  
    }  
    else if(choice == 2)  
    {  
        result = num1 - num2;  
        printf("result=%d", result);  
    }  
    else if(choice == 3)  
    {  
        result = num1 * num2;  
        printf("result=%d", result);  
    }  
    else if(choice == 4)  
    {  
        if(num2 == 0)  
        {  
            printf("Division by zero is not allowed");  
        }  
        else  
        {  
            float div_result = (float)num1 / num2;  
            printf("result=%.2f", div_result);  
        }  
    }  
    else  
    {  
        printf("You are a fool");  
    }  

    return 0;  
}