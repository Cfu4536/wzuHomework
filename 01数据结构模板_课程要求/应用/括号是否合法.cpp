#include<bits/stdc++.h>
using namespace std;
//�����Ƿ�Ϸ�
typedef char ElementType;
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
	S = createStack(1010);
	char s[1100];
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i <= len - 1; i++) {
		if (top(S) == '[' && s[i] == ']' || top(S) == '(' && s[i] == ')' || top(S) == '{' && s[i] == '}') {
			pop(S);
		} else {
			push(S, s[i]);
		}
	}
	if (empty(S)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
}

