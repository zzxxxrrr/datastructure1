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

bool ListInsert(LinkList &L,int i,int e){//插入元素
    if(i<1) return false;
    LNode *p;//表示当前节点
    int j=0;//表示当前是第几个节点
    p = L;//指向头节点
    if(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->next=p->next;
    s->data=e;
    p->next=s;
    return true;
}

bool InsertNextNode(LNode *p,int e){//后插操作,在节点p后插入元素
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    if(s==NULL) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;

}

bool InsertPriorNode(LNode *p,int e){//直接交换,时间复杂度为1
    if(p==NULL) return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

bool Delete(LinkList &L,int i,int &e){//删除第i个位置的元素
    if(i<1) return false;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    if(p->next==NULL) return false;
    LNode *q=p->next;
    p->next=q->next;
    int e=q->data;
    free(q);
    return false;
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