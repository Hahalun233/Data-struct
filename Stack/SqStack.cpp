#include<iostream>
#define ElemType int
#define Maxsize 10
using namespace std;
 
//顺序栈
typedef struct SqStack{
    ElemType data[Maxsize];
    int top;
}SqStack;

//新元素进栈
bool Push(SqStack &S,ElemType x){
    if(S.top==Maxsize-1){
        return false;//Stack is full
    }
    S.top++;//pointer+1
    S.data[S.top]=x;//push the x which the S.top point at
    return true;
}

//出栈操作
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1){
        return false;//Stack is empty
    }
    x=S.data[S.top];//pop the x which the S.top point at
    S.top--;
    return true;
}

 