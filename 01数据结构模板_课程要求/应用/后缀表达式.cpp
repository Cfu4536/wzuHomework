#include<bits/stdc++.h>
using namespace std;
//��׺���ʽ��ֵ
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
int isnum(int x) {
	if (x >= '0' && x <= '9') return 1;
	else return 0;
}
int calculate(int a, int b, char c) {
	if (c == '+') {
		return a + b;
	} else if (c == '-') {
		return b - a;
	} else if (c == '*') {
		return a * b;
	} else {
		return b / a;
	}
}
/*--------------------------------------------------------------------------------------*/
int main() {
	S = createStack(110);
	char s[110];
	gets(s);
	int len = strlen(s);
	for (int i = 0; i <= len - 1; i++) {
		if (isnum(s[i])) {
			push(S, s[i] - '0');
			i++;
		} else {
			int a, b, res;
			a = top(S);
			pop(S);
			b = top(S);
			pop(S);
			res = calculate(a, b, s[i]);
			push(S, res);
			i++;
		}
	}
	printf("%d\n", top(S));
	return 0;
}
