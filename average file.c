#include <stdio.h>
#include <stdlib.h>

int main(void)
{   float num1,num2,num3,average;
    printf("enter three numbers");
    scanf("%f%f%f",&num1,&num2,&num3);
    average=(num1+num2+num3)/3;
    printf("Average is :%f",average);
    return EXIT_SUCCESS;
}