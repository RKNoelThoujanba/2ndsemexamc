#include <stdio.h>
#include <stdint.h>

int8_t IsPrime(uint64_t n)
{
    if(n <= 2) return 0; // false
    for(int i = 3; i * i <= n; ++i)
        if(n % i == 0) return 0; //false

    return 1;
}

void PrintPrimes(uint64_t lowerLimit, uint64_t upperLimit)
{
    for(uint64_t i = lowerLimit; i <= upperLimit; i += 2)
        if(IsPrime(i))
            printf("%llu ", i);
}

int main(void)
{
    uint64_t lowerLimit, upperLimit;
    printf("Enter Lower Limits and Upper Limits: \n");
    scanf("%llu%llu", &lowerLimit, &upperLimit);

    PrintPrimes(lowerLimit, upperLimit);
}