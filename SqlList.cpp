#include <iostream>
using namespace std;

#define ElemType int

#define InitSize 10

typedef struct
{
    ElemType *data;
    int MaxSize;
    int lengh;
} SqList;

void InintSqList(SqList &L)
{
    L.data = (int *)malloc(sizeof(int) * InitSize);
    L.lengh = 0;
    L.MaxSize = InitSize;
}

int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.lengh; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
        return 0;
    }
}

void IncreaseSize(SqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.lengh; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

int main()
{
    SqList L;
    InintSqList(L);
}