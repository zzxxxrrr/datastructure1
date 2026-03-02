#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
   struct LNode *next;
}*LinkList,LNode;

bool InitList(LinkList &L){//初始化链表
    L=(LNode*)malloc(sizeof(LNode));
    if(L==NULL) return false;
    L->next=NULL;
    L->data=0;
    return true;
}

void CreateList(LinkList &L,int arr[],int n){//利用数组创建一个链表
    if (L == NULL) InitList(L);
     LNode * rear=L;//尾指针,指向链表最后一个节点
     for(int i =0;i<n;i++){
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=arr[i];
        rear->next=s;
        rear=s;
     }
     rear->next=NULL;
}

int main(){
    LinkList L=NULL;
    int data[] = {10, 20, 30, 40};
    
    // 直接调用创建函数（内部会处理初始化）
    CreateList(L, data, 4);
    printf("链表快速创建成功！\n");
    if (L && L->next) {
        printf("第一个数据是：%d\n", L->next->data);
    }
    LNode *p;
while (L != NULL) {
    p = L;       // 记住当前节点
    L = L->next; // 指向下一个，防止断开
    free(p);     // 释放当前
}
L = NULL;
    L=NULL; //防止产生野指针,如果不指NULL,l中还会存有这块已经被释放的空间的地址值
    return 0;
}