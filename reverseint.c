#include <stdio.h>

int Reverse(int n)
{
    typedef char Boolean;
    Boolean iSNegative = n < 0;

    int absN = iSNegative ? -n : +n;

    int absRev = 0;
    
    while(absN != 0)
    {
        absRev = (absRev * 10) + (absN % 10);
        absN /= 10;
    }
    return iSNegative ? -absRev : +absRev;
}

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int reverse = Reverse(n);
    printf("Reverse: %d\n", reverse);
}