#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 必须包含这个来使用 bool

typedef struct LNode {
    int data; 
    struct LNode *next; 
} LNode, *LinkList;

// 修正：使用二级指针以修改 main 中的 L 指向
bool InitList(LinkList *L) {
    *L = (LNode*)malloc(sizeof(LNode));
    if (*L == NULL) return false;
    (*L)->next = NULL;
    return true;
}

// 修正：插入操作，i 是位置，e 是值
// 因为有头结点，L 指向头结点的地址不需要改变，传一级指针即可
bool ListInsert(LinkList L, int i, int e) {
    if (i < 1) return false;

    LNode* p = L; // p 指向头结点
    int j = 0; 

    // 寻找第 i-1 个节点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    // 如果 p 为空，说明插入位置超出了链表长度+1
    if (p == NULL) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) return false;
    
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

void PrintList(LinkList L) {
    LNode *p = L->next; 
    printf("当前链表内容: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    LinkList L = NULL;
    // 传入 L 的地址
    if (!InitList(&L)) {
        printf("初始化失败\n");
        return 1;
    }

    printf("[测试1] 在位置 1 插入 100\n");
    ListInsert(L, 1, 100);
    PrintList(L);

    printf("\n[测试2] 在位置 2 插入 200\n");
    ListInsert(L, 2, 200);
    PrintList(L);

    printf("\n[测试3] 在位置 1 插入 50\n");
    ListInsert(L, 1, 50);
    PrintList(L);

    // 释放内存
    LNode *temp;
    while (L != NULL) {
        temp = L;
        L = L->next;
        free(temp);
    }
    printf("\n内存已释放，测试结束。\n");

    return 0;
}