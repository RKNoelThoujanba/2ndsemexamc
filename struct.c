#include <stdio.h>
#include <limits.h>

#define NAME_MAX_SZ 128

#define MAX_STUDENT_SZ 100

#define STR_BUFF_MAX_SZ 512

struct Student
{
    char Name[NAME_MAX_SZ];
    unsigned int Roll;
    unsigned int Marks;
};

unsigned int StringLen(const char* str)
{
    if(str == NULL) return 0;
    unsigned int len;
    for(len = 0; str[len] != '\0'; ++len);
    return len;
}

//well pray that there is no buffer overflow
void StringCopy(char* dest, const char* src)
{
    if(src == NULL || dest == NULL) return;
    unsigned int i;
    for(i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
}

void GetString(char* str, unsigned int maxSz)
{ 
    if(str == NULL || maxSz == 0) return;
    fgets(str, maxSz - 2, stdin);

    if(ferror(stdin)) return;

    unsigned int len = StringLen(str);
    str[len - 1] = '\0';
}


unsigned int ParseInt(const char* str)
{
    if(str == NULL) return UINT_MAX;
    unsigned int len = StringLen(str);
    unsigned int digitPlace = 1;
    unsigned int res = 0;
    for(long long int i = len - 1; i >= 0; --i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * digitPlace;
            digitPlace *= 10;
        }
        else
        {
            printf("Returning err at i = %u\n", i);
            return UINT_MAX;
        }

    }

    return res;
}

unsigned int ReadUInt(const char* msg)
{
    static char buff[STR_BUFF_MAX_SZ];

    printf("%s", msg);
    GetString(buff, STR_BUFF_MAX_SZ);

    return ParseInt(buff);
}

void SwapStudents(struct Student* first, struct Student* second)
{
    if(first == NULL || second == NULL) return;

    struct Student tmp;
    StringCopy(tmp.Name, first->Name);
    tmp.Roll = first->Roll;
    tmp.Marks = first->Marks;

    StringCopy(first->Name, second->Name);
    first->Roll = second->Roll;
    first->Marks = second->Marks;

    StringCopy(second->Name, tmp.Name);
    second->Roll = tmp.Roll;
    second->Marks = tmp.Marks;
}


void SortByRank(struct Student* studnetArr, unsigned int n)
{
    if(n == 0 || studnetArr == NULL) return;
    

    for(unsigned int i = 0; i < n - 1; ++i)
    {
        for(unsigned int j = 0; j < n - i - 1; ++j)
        {
            if(studnetArr[j].Marks < studnetArr[j + 1].Marks)
            {
                SwapStudents(&studnetArr[j], &studnetArr[j + 1]);
            }
        }
    }
}


int main(void)
{
    struct Student students[MAX_STUDENT_SZ];
    char buffer[STR_BUFF_MAX_SZ];
    printf("n: ");
    GetString(buffer, STR_BUFF_MAX_SZ);
    unsigned int n = ParseInt(buffer);

    printf("----------------------------------------\n");

    for(unsigned int i = 0; i < n; ++i)
    {
        printf("Entery #%u\n", i);
        printf("Name: ");
        GetString(students[i].Name, NAME_MAX_SZ);
        students[i].Roll = ReadUInt("Roll: ");
        students[i].Marks = ReadUInt("Marks: ");
        printf("----------------------------------------\n");
    }

    printf("Sorted by Rank: \n");
    SortByRank(students, n);

    for(unsigned int i = 0; i < n; ++i)
    {
        printf("----------------------------------------\n");

        printf(
            "Name: %s\n"
            "Roll: %u\n"
            "Marks: %u\n",
            students[i].Name, students[i].Roll, students[i].Marks
        );
    }
    printf("----------------------------------------\n");
}