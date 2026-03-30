#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    printf("Enter a string: ");
    gets(str);  // Note: gets is unsafe, but commonly used in exams

    ptr = str;  // Pointer points to the string

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    printf("Length of the string = %d", length);

    return 0;
}