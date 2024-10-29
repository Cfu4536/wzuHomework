#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
	ElementType data;
	struct Node *next;
} Node, *LinkStack;
/*-----------------------------------------------------------------------------------*/
void clearStack(LinkStack S);

Node*midS, *backS;

char temp[110];
char s[110];
int t = 0;
void destroyStack(LinkStack S) {
	clearStack(S);
	free(S);
}
void clearStack(LinkStack S) {
	S->next = NULL;
}
ElementType getTop(LinkStack S) {
	return S->next->data;
}
int pop(LinkStack S) {
	Node*p;
	p = S->next;
	if (p == NULL) {
		return 0;
	}
	S->next = p->next;
	free(p);
	return 1;
}
int empty(LinkStack S) {
	if (S->next == NULL) {
		return 1;
	}
	return 0;
}
int push(LinkStack S, ElementType x) {
	Node*s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		return 0;
	}
	s->data = x;
	s->next = S->next;
	S->next = s;
	return 1;
}
LinkStack createStack() {
	LinkStack S = (LinkStack)malloc(sizeof(Node));
	S->next = NULL;
	return S;
}
int isnum(char x) {
	if (x >= '0' && x <= '9') return 1;
	else return 0;
}
int leve(char c) {
	if (c == '(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
}
void output(LinkStack S) {
	while (getTop(S) != '(') {
		temp[t] = getTop(S);
		pop(S);
		t++;
	}
	pop(S);
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
/*-----------------------------------------------------------------------------------*/
int main() {
	midS = createStack();
	backS = createStack();
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i <= len - 1; i++) {
		if (isnum(s[i])) {
			temp[t] = s[i];
			t++;
		} else {
			if (empty(midS)) {
				push(midS, s[i]);
			} else {
				if (s[i] == '(') {
					push(midS, s[i]);
				} else if (s[i] == ')') {
					output(midS);
				} else if (leve(s[i]) > leve(getTop(midS))) {
					push(midS, s[i]);
				} else {
					while (!empty(midS) && leve(s[i]) <= leve(getTop(midS))  ) {
						temp[t] = getTop(midS);
						t++;
						pop(midS);
					}
					push(midS, s[i]);
				}
			}
		}
	}
	while (!empty(midS)) {
		temp[t] = getTop(midS);
		pop(midS);
		t++;
	}
	len = strlen(temp);
	for (int i = 0; i <= len - 1; i++) {
		if (isnum(temp[i])) {
			push(backS, temp[i] - '0');
		} else {
			int a, b, res;
			a = getTop(backS);
			pop(backS);
			b = getTop(backS);
			pop(backS);
			res = calculate(a, b, temp[i]);
			push(backS, res);
		}
	}
	printf("%d\n", getTop(backS));
	return 0;
}
