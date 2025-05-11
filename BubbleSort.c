#include <stdio.h>

#define ARR_MAX_SZ 512

void BubbleSort(int* arr, unsigned int n)
{
    if(arr == NULL || n == 0) return;

    for(unsigned int i = 0; i < n - 1; ++i)
    {
        int hasSwapped = 0;
        for(unsigned int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                hasSwapped = 1;
            }
        }
        if(!hasSwapped) return;
    }
}

void ReadIntArr(int* arr, unsigned int n)
{
    if(arr == NULL || n == 0) return;

    for(unsigned int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

void PrintIntArr(const int* arr, unsigned int n)
{
    for(unsigned int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    putchar('\n');
}

int main(void)
{
    int arr[ARR_MAX_SZ] = {0};
    unsigned int n;
    printf("n: ");
    scanf("%u", &n);

    if(n == 0 || n > ARR_MAX_SZ)
    {
        printf("Invalid n \n");
        return 1;
    }

    printf("Enter %u elements: \n", n);
    ReadIntArr(arr, n);

    BubbleSort(arr, n);
    printf("Sorted Array:\n");
    PrintIntArr(arr, n);
}