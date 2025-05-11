#include <stdio.h>

int IsPrime(int n)
{
    if(n <= 2) return 0; // false
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return 0; //false

    return 1;
}

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(IsPrime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
}