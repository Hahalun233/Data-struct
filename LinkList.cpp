#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode{
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

//按位序插入
bool ListInsert(LinkList &L,int i,ElemType e){
    LNode *p;
    int j=0;
    p=L;//p指向头节点
    if(i<1||p==NULL){
        return false;
    }
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data=e;
    node->next=p->next;
    p->next=node;
    return true;
    

}

