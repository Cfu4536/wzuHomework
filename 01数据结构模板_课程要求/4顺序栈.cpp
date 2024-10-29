#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array; //���ջ����
	int top;	 		//ջ��
	int capacity;  		//����
} SeqStack;

int full(SeqStack *S);
SeqStack* createStack(int capacity);
int empty(SeqStack *S);
/*--------------------------------------------------------------------------------------*/
SeqStack* S;
void destroyStack(SeqStack *S) {
	free(S->array);
	free(S);
}//����
void clearStack(SeqStack *S) {
	S->top = -1;
}//�������
ElementType top(SeqStack *S) {
	return S->array[S->top];
}//ջ������
int pop(SeqStack *S) {
	if (empty(S)) {
		return 0;
	}
	S->top--;
	return 1;
}//��ջ
int empty(SeqStack *S) {
	if (S->top == -1) return 1;
	else return 0;
}//�п�
int push(SeqStack *S, ElementType x) {
	if (full(S)) {
		return 0;
	}
	S->top++;
	S -> array[S->top] = x;
	return 1;
}//��ջ
int full(SeqStack *S) {
	if (S->top >= S->capacity - 1) return 1;
	else return 0;
}//����
SeqStack* createStack(int capacity) {
	S = (SeqStack*)malloc(sizeof(SeqStack));
	S->top = -1;
	S->capacity = capacity;
	S->array = (ElementType*)malloc(sizeof(ElementType) * capacity);
	return S;
}//����
/*--------------------------------------------------------------------------------------*/
int main() {
	int n;
	scanf("%d", &n);
	S = createStack(n);
//
	if (full(S)) printf("1\n");
	else printf("0\n");
	push(S, 1);
	push(S, 2);
	push(S, 3);
	push(S, 4);
	pop(S);
	return 0;
}


