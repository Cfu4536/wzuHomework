#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array; //������ݵ�ָ��
	int length;	 		//�������ݸ���
	int capacity;  		//����
} SeqList;
/*----------------------------------------------------------------------------------------*/
SeqList* L;
SeqList* createList(int x) {
	L = (SeqList*)malloc(sizeof(SeqList));
	L->array = (ElementType*)malloc(x * sizeof(ElementType));
	L->length = 0;
	L->capacity = x;
	return L;
}//����

void printList(SeqList *L) {
	if (L->length != 0) {
		for (int i = 0; i <= L->length - 1; i++) {
			printf("%d ", L->array[i]);
		}
		printf("\n");
	}
}//���
int getLength(SeqList *L) {
	return L->length;
}//����
int find(SeqList *L, ElementType x) {
	for (int i = 0; i <= L->length - 1; i++) {
		if (L->array[i] == x) return i + 1;
	}
	return -1;
}//����
int getElement(SeqList *L, int i, ElementType *p) {
	if (i < 1 || i > L->length) {
		return 0;
	}
	*p = L->array[i - 1];
	return 1;
}//��ȡ

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
}//����

int isEmpty(SeqList *L) {
	if (L->length == 0) {
		return 1;
	}
	return 0;
}//�п�

int delElement(SeqList *L, int i, ElementType *p) {
	if (i < 1 || i > L->length) {
		return 0;
	}
	for (int j = i - 1; j <= L->length - 1; j++) {
		L->array[j] = L->array[j + 1];
	}
	L->length--;
	return 1;
}//ɾ��
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
}//ɾ��
void clearList(SeqList *L) {
	L->length = 0;
}// �������
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
}//����ϲ�
void destroyList(SeqList *L) {
	free(L->array);
	free(L);
}//����

/*----------------------------------------------------------------------------------------*/
int main() {
	
	return 0;
}




