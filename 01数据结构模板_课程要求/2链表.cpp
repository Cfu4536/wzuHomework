#include<bits/stdc++.h>
using namespace std;
typedef int ElementType;

typedef struct Node {
	int data;
	struct Node * next;
} Node, *LinkList;
LinkList L;


LinkList createList();
void printList(LinkList L);
Node* find(LinkList L, ElementType x);
Node* locate(LinkList L, int i);
void insertHead(LinkList L, ElementType x);
void insertTail(LinkList L, ElementType x);
int insertList(LinkList L, int i, ElementType x);
int getLength(LinkList L);
int delNode(LinkList L, ElementType x);
int delNode(LinkList L, int i, ElementType *px);
void clearList(LinkList L);
void destroyList(LinkList L);

/*------------------------------------------------------------------------------------*/
int main() {
	L = createList();
	Node* tag;
	insertHead(L, 1);
	insertTail( L, 2);
	if (insertList(L, 2, 3)) {
		tag = find(L, 2);
		tag = locate(L, 2);
	}
	printList(L);
	printf("lenght:%d\n", getLength(L));
	if (delNode(L, 2)) {
		printList(L);
	}
	int xp;
	ElementType* x = &xp;
	if (delNode(L, 2, x)) {
		printList(L);
	}
	printf("%d\n", *x);
	clearList(L);
	destroyList(L);
	return 0;
}
/*------------------------------------------------------------------------------------*/
LinkList createList() {
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}//chuangjian;
Node*p;
void printList(LinkList L) {
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}//shuchu

Node* find(LinkList L, ElementType x) {
	p = L->next;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}//chazhaozhi
Node* locate(LinkList L, int i) {
	p = L;
	int k = 0;
	while (p != NULL && k < i) {
		p = p->next;
		k++;
	}
	if (i == 0) {
		p = NULL;
	}
	return p;
}//chazhaoweizhi

void insertHead(LinkList L, ElementType x) {
	Node*s;
	s = (Node*)malloc(sizeof(Node));
	s->data = x;
	s->next = L->next;
	L->next = s;
}//touchafa
void insertTail(LinkList L, ElementType x) {
	Node*pre;
	p = L->next;
	while (p != NULL) {
		pre = p;
		p = p->next;
	}
	Node*s;
	s = (Node*)malloc(sizeof(Node));
	s->data = x;
	s->next = pre->next;
	pre->next = s;
}//weicharu
int insertList(LinkList L, int i, ElementType x) {
	p = locate(L, i - 1);
	if (i < 1 || p == NULL) {
		return 0;
	}
	Node*s;
	s = (Node*)malloc(sizeof(Node));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return 1;
}//zhongjiancharu
int getLength(LinkList L) {
	p = L->next;
	int cnt = 0;
	while (p != NULL) {
		p = p->next;
		cnt++;
	}
	return cnt;
}//changdu
int delNode(LinkList L, ElementType x) {
	p = L->next;
	Node*pre;
	pre = L;
	while (p != NULL && p->data != x) {
		pre = p;
		p = p->next;
	}
	if (p == NULL) {
		return 0;
	}
	pre->next = p->next;
	free(p);
	return 1;
}//shanchuzhi
int delNode(LinkList L, int i, ElementType *px) {
	p = locate(L, i - 1);
	if (p == NULL || i < 1 || p->next == NULL  ) {
		return 0;
	}
	Node* temp;
	temp = p->next;
	p->next = temp->next;
	*px = temp->data;
	free(temp);
	return 1;
}//shanchu weizhi
void clearList(LinkList L) {
	Node*temp;
	p = L->next;
	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
	L->next=NULL;
}//qingchu
void destroyList(LinkList L){
	clearList(L);
	free(L);
}//xiaohui




