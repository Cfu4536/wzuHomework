#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array; //存放数据的指针
	int length;	 		//已有数据个数
	int capacity;  		//容量
} SeqList;
/*----------------------------------------------------------------------------------------*/
SeqList* L;
SeqList* createList(int x) {
	L = (SeqList*)malloc(sizeof(SeqList));
	L->array = (ElementType*)malloc(x * sizeof(ElementType));
	L->length = 0;
	L->capacity = x;
	return L;
}//创建

void printList(SeqList *L) {
	if (L->length != 0) {
		for (int i = 0; i <= L->length - 1; i++) {
			printf("%d ", L->array[i]);
		}
		printf("\n");
	}
}//输出
int getLength(SeqList *L) {
	return L->length;
}//长度
int find(SeqList *L, ElementType x) {
	for (int i = 0; i <= L->length - 1; i++) {
		if (L->array[i] == x) return i + 1;
	}
	return -1;
}//查找
int getElement(SeqList *L, int i, ElementType *p) {
	if (i < 1 || i > L->length) {
		return 0;
	}
	*p = L->array[i - 1];
	return 1;
}//获取

int insertList(SeqList *L, int i, ElementType x) {
	if (i < 1 || i > L->length + 1 || L->length == L->capacity) {
		return 0;
	}
	for (int j = L->length - 1; j >= i - 1; j--) {
		L->array[j + 1] = L->array[j];
	}
	L->array[i - 1] = x;
	L->length++;
	return 1;
}//插入

int isEmpty(SeqList *L) {
	if (L->length == 0) {
		return 1;
	}
	return 0;
}//判空

int delElement(SeqList *L, int i, ElementType *p) {
	if (i < 1 || i > L->length) {
		return 0;
	}
	for (int j = i - 1; j <= L->length - 1; j++) {
		L->array[j] = L->array[j + 1];
	}
	L->length--;
	return 1;
}//删除
void delRepeatElement(SeqList *L) {
	int flag = 1;
	int cnt = 0;
	for (int i = 0; i <= L->length - 1; i++) {
		flag = 1;
		for (int j = 0; j < i; j++) {
			if (L->array[i] == L->array[j]) {
				flag = 0;
			}
		}
		if (flag == 1) {
			L->array[cnt++] = L->array[i];
		}
	}
	L->length = cnt;
}//删重
void clearList(SeqList *L) {
	L->length = 0;
}// 清除数据
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
	int i = 0, j = 0, cnt = 0;
	while (i < LA->length && j < LB->length) {
		if (LA->array[i] < LB->array[j]) {
			LC->array[cnt++] = LA->array[i++];
		} else {
			LC->array[cnt++] = LB->array[j++];
		}
	}
	while (i < LA->length) {
		LC->array[cnt++] = LA->array[i++];
	}
	while (j < LB->length) {
		LC->array[cnt++] = LB->array[j++];
	}
	LC->length = LA->length + LB->length;
}//有序合并
void destroyList(SeqList *L) {
	free(L->array);
	free(L);
}//销毁

/*----------------------------------------------------------------------------------------*/
int main() {
	
	return 0;
}




