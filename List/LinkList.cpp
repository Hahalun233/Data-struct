#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode
{ //带头节点的单链表
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//带头节点链表的初始化
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

//头插法创建单链表
LinkList List_HeadInsert(LinkList &L, int length)
{
    int data;
    LNode *node = NULL;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        node = (LNode *)malloc(sizeof(LNode));
        node->data = data;
        node->next = L->next;
        L->next = node;
    }
    return L;
}

//在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, ElemType e)
{
    LNode *p;
    int j = 0; //记录当前p指向的节点位置
    p = L;     //p指向头节点
    if (i < 1 || p == NULL)
    {
        return false;
    }
    while (p != NULL && j < i - 1)
    { //循环到底i-1个节点
        p = p->next;
        j++;
    }
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = e;
    node->next = p->next;
    p->next = node; //将节点node链接到p之后
    return true;
}

//删除第i个节点
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    LNode *p;
    int j = 0; //记录当前p指向的节点位置
    p = L;     //p指向头节点
    if (i < 1 || p == NULL)
    {
        return false;
    }
    while (p != NULL && j < i - 1)
    { //循环到底i-1个节点
        p = p->next;
        j++;
    }
    LNode *q = p->next; //用q保存将要删除的节点
    e = q->data;        //用e返回被删除的值
    p->next = q->next;  //连接将要删除节点的前后节点
    free(q);            //释放q
    return true;
}

//按序号查找
LNode *GetElem(LinkList L /*不改动L，无需&L*/, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j = 0;
    LNode *p;
    int j = 0; //记录p指向位置
    p = L;     //将p指向头节点，以开始循环
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateELem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}