#include <stdio.h>
#include <stdint.h>

#define FACT_ARG_MAX_VAL_IN_UINT64 ((uint8_t)20)

uint64_t Factorial(uint8_t n)
{
    if(n > FACT_ARG_MAX_VAL_IN_UINT64) return UINT64_MAX;

    uint64_t fact = 1;
    for(uint8_t i = 2; i <= n; ++i)
        fact *= i;

    return fact;
}

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n < 0)
    {
        printf("n cannot be negative\n");
        return 1;
    }
    else if(n > FACT_ARG_MAX_VAL_IN_UINT64)
    {
        printf("Buffer Overflow, n must be less than or equal to 20\n");
        return 2;
    }
    printf("%d! = %llu", n, Factorial(n));
}