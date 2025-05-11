#include <stdio.h>

#define ARR_MAX_SZ 512

int LinearSearch(const int* arr, unsigned short n, int key)
{
    if(arr == NULL || n == 0) return -1;

    for(unsigned int i = 0; i < n; ++i)
        if(arr[i] == key) return i;
    
    return -1;
}

void ReadIntArr(int* arr, unsigned short n)
{
    for(unsigned int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int main(void)
{
    int arr[ARR_MAX_SZ] = {0};
    unsigned int n;
    printf("n: ");
    scanf("%u", &n);

    if(n == 0 || n > ARR_MAX_SZ) 
    {
        printf("Invalid n\n");
        return 1;
    }
    
    printf("Enter %hu elements:\n", n);
    ReadIntArr(arr, n);

    int key;
    printf("key: ");
    scanf("%d", &key);

    int index = LinearSearch(arr, n, key);
    if(index == -1)
        printf("Key %d not found\n", key);
    else
        printf("Key %d found at index %d\n", key, index);
}