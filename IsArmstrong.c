#include <stdio.h>
#include <stdint.h>

uint32_t PowU32(uint32_t base, uint32_t exp)
{
    uint32_t res = 1;
    for(uint32_t i = 0; i < exp; ++i) res *= base;

    return res;
}

uint32_t DigitCuunt(uint32_t n)
{
    uint32_t digitCount = 0;
    while(n != 0) 
    {
        ++digitCount;
        n /= 10;
    }
    return digitCount;
}

int8_t IsArmstrong(uint32_t n)
{
    uint32_t digitCount = DigitCuunt(n);

    uint32_t sum = 0;
    uint32_t nBuff = n;
    while(nBuff != 0)
    {
        sum += PowU32(nBuff % 10, digitCount);
        nBuff /= 10;
    }
    return sum == n;
}

int main(void)
{
    int64_t n;
    printf("n: ");
    scanf("%lld", &n);

    if(n < 0)
    {
        printf("n cannot be negative\n");
        return 1;
    }

    if(IsArmstrong(n))
        printf("%lld is Armstrong\n", n);
    else
        printf("%lld is not Armstrong\n", n);

}