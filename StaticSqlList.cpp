#include<iostream>
#define MaxSize 50
#define ElemType int
using namespace std;

//静态链表，无需连续内存空间，data[]内元素随机存放。
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

int main(){
    SqList L;
    InitList(L);
    for(int i=0;i<MaxSize;i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    system("pause");
}