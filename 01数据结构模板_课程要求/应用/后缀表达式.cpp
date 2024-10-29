#include<bits/stdc++.h>
using namespace std;
//后缀表达式求值
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
