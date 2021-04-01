#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;

#define MaxSize 20
#define ElemType char

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} * LinkStack, LinkNode;

bool Inintstack(LinkStack &S)
{ //建立空栈
    S = NULL;
    return true;
}



//入栈
bool Push(LinkStack &S, ElemType e)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = S; //将S连接在p之后
    S = p;       //更新头指针(指向最新节点p)
    return true;
}

//出栈
bool Pop(LinkStack &S,char &e)
{
    if (S)
    {
        LinkNode *p = S;
        e=p->data;
        S = S->next;
        
        // cout<<"出栈元素为"<<p->data;
        // if(S){
        //     cout<<"新栈顶元素为"<<S->data;
        // }else{
        //     cout<<"栈已空！";
        // }
        free(p);
        return true;
    }
    else
    {
        // cout<<"栈已空！";
        return true;
    }
    return true;
}

bool Comp(ElemType a, ElemType b)
{
    if ((a == '(' && b != ')') || (a == '[' && b != ']') || (a == '{' && b != '}'))
    {
        return false;
    }
    else
        return true;
}

bool Count(LinkStack &S)
{
    ElemType e[MaxSize * 2];
    ElemType e1;
   

    Inintstack(S);

    gets(e);


    for (int i = 0; e[i] != '\0'; i++)
    {
        switch (e[i])
        { /*输入得左括号*/
        case '(':
        case '[':
        case '{':
        {
            Push(S, e[i]);
            break;
        }
        case ')':
        case ']':
        case '}':
        {
            if (S == NULL)
            {
                // printf("右括号多余\n");
                cout<<"false";
                return false;
            }
            else{
               Pop(S,e1);
               
               if(!Comp(e1,e[i]))
                {
            
                //  printf("左右匹配出错\n");
                cout<<"false";
                 return false;
                }
            }
            

        }
        }
    }
    if (!S==NULL)
        // printf("左括号多余\n");
        cout<<"false";

    else
        // printf("匹配正确\n");
        cout<<"true";

    return true;
}

int main(){
    LinkStack S;
    Count(S);
    free(S);

    system("pause");
    return 0;
}