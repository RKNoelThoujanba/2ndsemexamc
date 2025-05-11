#include <stdio.h>

#define STR_MAX_SZ 512

unsigned int StringLen(const char* str)
{
    if(str == NULL) return 0;
    unsigned int len;
    for(len = 0; str[len] != '\0'; ++len);
    return len;
}

void StringRev(char* str)
{
    if(str == NULL) return;
    for(unsigned int i = 0, j = StringLen(str) - 1; i < j; ++i, --j)
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
void GetString(char* str, unsigned int maxSz)
{ 
    if(str == NULL || maxSz == 0) return;
    fgets(str, maxSz - 2, stdin);

    if(ferror(stdin)) return;

    unsigned int len = StringLen(str);
    str[len - 1] = '\0';
}

int main()
{
    char str[STR_MAX_SZ] = {0};
    printf("str: ");
    GetString(str, STR_MAX_SZ);
    StringRev(str);
    printf("Reversed String: %s\n", str);
}