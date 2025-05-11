#include <stdio.h>
#include <stdint.h>

#define ARR_MAX_SZ 512

typedef uint8_t err_t;

#define ERR_NONE ((err_t) 0)
#define ERR_INVALID_INDEX ((err_t)1)
#define ERR_BUFFER_OVERFLOW ((err_t)2)
#define ERR_BUFFER_UNDERFLOW ((err_t)3)
#define ERR_INVALID_PARAM ((err_t) 4)

const char* GetErrorInfo(err_t err)
{
    switch (err)
    {
    case ERR_NONE:
        return "No Error";
    case ERR_INVALID_INDEX:
        return "Invalid Index";
    case ERR_BUFFER_OVERFLOW:
        return "Buffer Overflow";
    case ERR_BUFFER_UNDERFLOW:
        return "Buffer Underflow";
    case ERR_INVALID_PARAM:
        return "Invalid Parameter";
    
    default:
        return "Unknown Error";
    }
}


err_t Delete(int* arr, uint32_t n, uint32_t maxSz, uint32_t index)
{
    if(arr == NULL) return ERR_INVALID_PARAM;
    if(n == 0) return ERR_BUFFER_UNDERFLOW;
    if(n > maxSz) return ERR_BUFFER_OVERFLOW;
    if(index >= n) return ERR_INVALID_INDEX;

    for(uint32_t i = index + 1; i < n; ++i)
        arr[i - 1] = arr[i];

    return ERR_NONE;
}


err_t ReadIntArr(int* arr, uint32_t n, uint32_t maxSz)
{
    if(n > maxSz) return ERR_BUFFER_OVERFLOW;
    if(n == 0) return ERR_BUFFER_UNDERFLOW;
    if(arr == NULL) return ERR_INVALID_PARAM;

    for(uint32_t i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    return ERR_NONE;
}

err_t PrintIntArr(const int* arr, uint32_t n, uint32_t maxSz)
{
    if(n > maxSz) return ERR_BUFFER_OVERFLOW;
    if(n == 0) return ERR_BUFFER_UNDERFLOW;
    if(arr == NULL) return ERR_INVALID_PARAM;

    for(uint32_t i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    
    putchar('\n');

    return ERR_NONE;
}

int main(void)
{

    int arr[ARR_MAX_SZ] = {0};
    uint32_t n;
    printf("n: ");
    scanf("%u", &n);
    printf("Enter %u elements: \n");

    err_t err;

    err = ReadIntArr(arr, n, ARR_MAX_SZ);
    if(err != ERR_NONE) goto errHandle;

    uint32_t index;
    printf("Enter Index to be deleted: ");
    scanf("%u", &index);

    err = Delete(arr, n, ARR_MAX_SZ, index);
    if(err != ERR_NONE) goto errHandle;
    --n;

    err = PrintIntArr(arr, n, ARR_MAX_SZ);
    if(err != ERR_NONE) goto errHandle;

    return 0;

errHandle:
    const char* info = GetErrorInfo(err);
    printf("Error: %s\n", info);
}