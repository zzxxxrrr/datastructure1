#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data; //数据域
    struct LNode *next; //指针域
}LNode,*LinkList;

bool InitList(LinkList &L)//带头结点的单链表
{
    L=(LNode*)malloc(sizeof(LNode));//分配头指针的地址
    if(L==NULL) return false;//分配失败
    L->next=NULL;//后继指针为空
    return true;
}

int main(){
   LinkList L;//声明,给了一个野指针
   InitList(L);//初始化
   return 0; 
}