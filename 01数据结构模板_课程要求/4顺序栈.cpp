#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array; //存放栈数据
	int top;	 		//栈顶
	int capacity;  		//容量
} SeqStack;

int full(SeqStack *S);
SeqStack* createStack(int capacity);
int empty(SeqStack *S);
/*--------------------------------------------------------------------------------------*/
SeqStack* S;
void destroyStack(SeqStack *S) {
	free(S->array);
	free(S);
}//销毁
void clearStack(SeqStack *S) {
	S->top = -1;
}//清除数据
ElementType top(SeqStack *S) {
	return S->array[S->top];
}//栈顶数据
int pop(SeqStack *S) {
	if (empty(S)) {
		return 0;
	}
	S->top--;
	return 1;
}//出栈
int empty(SeqStack *S) {
	if (S->top == -1) return 1;
	else return 0;
}//判空
int push(SeqStack *S, ElementType x) {
	if (full(S)) {
		return 0;
	}
	S->top++;
	S -> array[S->top] = x;
	return 1;
}//入栈
int full(SeqStack *S) {
	if (S->top >= S->capacity - 1) return 1;
	else return 0;
}//判满
SeqStack* createStack(int capacity) {
	S = (SeqStack*)malloc(sizeof(SeqStack));
	S->top = -1;
	S->capacity = capacity;
	S->array = (ElementType*)malloc(sizeof(ElementType) * capacity);
	return S;
}//创建
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


