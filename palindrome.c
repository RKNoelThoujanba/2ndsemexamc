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

    if(n == Reverse(n))
        printf("%d is palindrome\n", n);
    else
        printf("%d is not palindorme", n);
}