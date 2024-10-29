#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct Node {
	ElementType data;
	struct Node *next;
} QNode;
typedef struct {
	QNode *front; //¶ÓÊ×
	QNode *rear;  //¶ÓÎ²
} LinkQueue;
int empty(LinkQueue *Q);
int pop(LinkQueue *Q);
void clearQueue(LinkQueue *Q);
/*---------------------------------------------------------------------------------*/
LinkQueue* Q;
void destroyQueue(LinkQueue *Q) {
	while (!empty(Q)) {
		pop(Q);
	}
	free(Q);
}
void clearQueue(LinkQueue *Q) {
	while (!empty(Q)) {
		pop(Q);
	}
}
ElementType front(LinkQueue *Q) {
	return Q->front->data;
}
int pop(LinkQueue *Q) {
	if (empty(Q)) {
		return 0;
	}
	QNode*p;
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	return 1;
}
int empty(LinkQueue *Q) {
	if (Q->front == NULL) return 1;
	else return 0;
}
int push(LinkQueue *Q, ElementType x) {
	QNode*s;
	s = (QNode*)malloc(sizeof(QNode));
	if (s == NULL) {
		return 0;
	}
	s->next = NULL;
	s->data = x;
	if (Q->front == NULL) {
		Q->front = s;
		Q->rear = s;
	} else {
		Q->rear->next = s;
		Q->rear = s;
	}
	return 1;
}
LinkQueue* createQueue() {
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Q->rear = NULL;
	Q->front = NULL;
	return Q;
}
/*---------------------------------------------------------------------------------*/

int main() {
	Q = createQueue();
	return 0;
}
