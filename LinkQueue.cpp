#include<iostream>
#define ElemType int
#define Maxsize 10
using namespace std;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode)); 
    Q.front->next=NULL;
}

//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s =(LinkNode*)malloc(sizeof(LinkNode));
    s->next=NULL;
    s->data=x;
    Q.rear->next=s;//新节点插入rear之后
    Q.rear=s;//修改表尾指针
}

//出队
bool DeQueue(LinkQueue &Q){
    if(Q.front==Q.rear){
        return false;
    }
    LinkNode *p=Q.front->next;
    
    Q.front->next=p->next;
    if(Q.rear==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;
}