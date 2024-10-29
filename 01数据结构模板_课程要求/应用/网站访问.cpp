#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node {
	ElementType data[50];
	struct Node *next;
} Node, *LinkStack;
LinkStack S;
LinkStack temp;
LinkStack createStack() {
	Node*top;
	top = (LinkStack)malloc(sizeof(Node));
	top->next = NULL;
	return top;
}//����
int empty(LinkStack S) {
	if (S->next == NULL) {
		return 1;
	}
	return 0;
}//�п�
int push(LinkStack S, ElementType x[]) {
	Node*s = (Node*)malloc(sizeof(Node));
	if (s == NULL) {
		return 0;
	}
	strcpy(s->data, x);
	s->next = S->next;
	S->next = s;
	return 1;
}//��ջ
int pop(LinkStack S) {
	Node*p;
	p = S->next;
	if (p == NULL) {
		return 0;
	}
	S->next = p->next;
	free(p);
	return 1;
}//��ջ
ElementType* getTop(LinkStack S) {
	return S->next->data;
}//ջ������
void clearStack(LinkStack S) {
	S->next = NULL;
}//�������
void destroyStack(LinkStack S) {
	clearStack(S);
	free(S);
}//��������
int scount = 0, tempcount = 0;//S��temp�е����ݸ���
int main() {
	char ins[10];
	S = createStack();
	temp = createStack();
	while (1) {
		scanf("%s", ins);
		if (strcmp(ins, "VISIT")==0) {
			char web[50];
			scanf("%s", web);
			push(S, web);
			printf("%s\n", web);
			clearStack(temp);
			scount++;
			tempcount=0;
		} else if (strcmp(ins, "BACK")==0) {
			if (scount <= 1) {
				printf("Ignored\n");
			} else {
				push(temp, getTop(S));
				pop(S);
				printf("%s\n", getTop(S));
				tempcount++;
				scount--;
			}
		} else if (strcmp(ins, "FORWARD")==0) {
			if (tempcount < 1) {
				printf("Ignored\n");
			} else {
				push(S, getTop(temp));
				pop(temp);
				printf("%s\n", getTop(S));
				tempcount--;
				scount++;
			}
		} else if (strcmp(ins, "QUIT")==0) {
			return 0;
		}
	}
}
