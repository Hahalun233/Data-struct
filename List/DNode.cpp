#include <iostream>
using namespace std;

#define ElemType int

//双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *perior, *next;
} DNode, *DLinklist;

//初始化双链表
bool InitDLink(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode)); //分配一个头节点
    if (L == NULL)
    {
        return false; //内存不足，分配失败
    }
    L->perior = NULL;
    L->next = NULL;
    return true;
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next; //令s节点的next指向将p节点后的节点
    if (p->next != NULL)
    {                        //如果p有后继节点
        p->next->perior = s; //令s节点后节点的perior指向s节点
    }
    s->perior = p;
    p->next = s;
    return true;
}

//删除p节点的后继节点
bool DeleteNextNode(DNode *p){
    if(p==NULL){
        return false;
    }
    DNode *q = p->next;
    if(q==NULL){//如果没有后继节点
        return false;
    }
    p->next=q->next;//将p节点的后继指向后继节点的后继节点（以实现删除p的后继节点）
    if(q->next!=NULL){
        q->next->perior=p;
    }
    free(q);
    return true;

}

//双链表：最后节点的next指向头节点 