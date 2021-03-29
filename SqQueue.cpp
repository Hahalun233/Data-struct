#include<iostream>
#define ElemType int
#define Maxsize 10
using namespace std;
typedef struct{
    ElemType data[Maxsize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%Maxsize==Q.front){//判空
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    return true;
}

//出队
bool DeQueue(SqQueue &Q){
     if(Q.rear==Q.front){
         return false;
     }
     ElemType x = Q.data[Q.front];
     Q.front=(Q.front+1)%Maxsize;
     cout<<"the"<<x<<"was out!";
     return true;
}