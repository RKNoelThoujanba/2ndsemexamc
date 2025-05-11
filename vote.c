#include <stdio.h>

int main(void)
{
    int age;
    printf("age: ");
    scanf("%d", &age);
    if(age < 18)
        printf("Can't vote\n");
    else
        printf("Can vote\n");
}