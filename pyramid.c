#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    if(n <= 0) return 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n - i; ++j)
            printf("%3c", ' '); // 3 space characters

        for(int k = 1; k <= i; ++k)
            printf("%3d", k);
        
        for(int l = i - 1; l > 0; --l)
            printf("%3d", l);
        
        putchar('\n');
    }
}