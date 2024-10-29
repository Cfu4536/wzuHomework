#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
	ElementType data;
	struct Node *next;
} Node, *LinkStack;
/*-----------------------------------------------------------------------------------*/
void clearStack(LinkStack S);

Node*S;
void destroyStack(LinkStack S) {
	clearStack(S);
	free(S);
}
void clearStack(LinkStack S) {
	Node*p, *pre;
	p=S->next;
	pre=S;
	while(p){
		
	}
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
	S = (LinkStack)malloc(sizeof(Node));
	S->next = NULL;
	return S;
}

/*-----------------------------------------------------------------------------------*/
int main() {
	S = createStack();
	/*	int n;
		scanf("%d", &n);
		while (n--) {
			int x;
			scanf("%d", &x);
			push(S, x);
		}
		printf("%d\n", getTop(S));*/
	destroyStack(S);
	return 0;
}
