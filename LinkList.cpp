#include <iostream>
using namespace std;

#define ElemType int

typedef struct{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


//带头节点链表的初始化
bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));
    if(L==NULL){
        return false;
    }
    L->next = NULL;
    return true;
}

//头插法创建单链表
LinkList List_HeadInsert(LinkList &L,int length){
    int data;
    LNode *node = NULL;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(int i = 0;i<length;i++){
        cin >> data;
        node = (LNode*)malloc(sizeof(LNode));
        node->data=data;
        node->next=L->next;
        L->next=node;
    }
    return L;
}