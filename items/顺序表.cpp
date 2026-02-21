#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
// #define Max 10 // 线性表的最大长度
// // 静态分配
// // 定义顺序表类型
// typedef struct SqList {
// 	int data[Max];
// 	int length;
// }Sqlist;
// // 初始化顺序表
// void InitList(Sqlist* l) {
// 	for (int i = 0; i < Max; i++) {
// 		l->data[i] = 0;
// 	}
// 	l->length = 0;
// }

//动态分配
//定义动态顺序表
typedef struct SeqList {
	int* data;
	int MaxSize;
	int length;
 }SeqList;

//初始化
void InitList(SeqList* l) {
	l->length = 0;
	l->MaxSize = InitSize;
	l->data = (int*)malloc(sizeof(int) * l->MaxSize);
	for (int i = 0; i < l->MaxSize; i++) {
		l->data[i] = 0;
	}
}
//增加长度
void IncreaseList(SeqList * l, int len) {
	int* p = l->data;
	int*newdata = (int*)malloc(sizeof(int) * (l->MaxSize + len));
	if (newdata == NULL) {
		printf("扩容失败");
		return;
	}
	for (int i = 0; i < l->length; i++) {
		newdata[i] = p[i];
	}
	for (int i = l->length; i < l->MaxSize + len; i++) {
		newdata[i] = 0;
	}
	l->data = newdata;
	l->MaxSize = l->MaxSize + len;
	free(p);
}
//插入元素
bool Insert(SeqList* L, int i, int e) {
	if (i<1 || i>L->length+1){
		return false;
	} 
	for (int j = L->length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
//删除元素
bool Delete(SeqList* L, int i, int* e) {
	if (i<1 || i>L->length) {
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++) {
		L->data[j-1] = L->data[j];
	}
	L->length--;
	return true;
}
//按值查找
int Search(SeqList * L, int e) {
	for (int j = 0; j < L->length; j++) {
		if (L->data[j] == e) {
			return j+1;
		}
	}
	return 0;
}
//按位查找
int Search1(SeqList* l, int i) {
	if (i < 1 || i > l->length) {
		printf("位置错误，无法访问\n");
		return -1; // 或者返回一个特定的错误标识
	}
	return l->data[i-1];
}
int main() {
	SeqList l;
	InitList(&l);
	IncreaseList(&l, 5);
	Insert(&l, 1, 2);
	for(int i = 0; i < l.length; i++) {
		printf("%d", l.data[i]);
	}
	free(l.data);
	return 0;
}