#include<bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *array;
	int front;      //队首位置
	int rear;       //尾指下一个位置
	int length;     //长度
	int capacity;   //总容量
} SeqQueue;
int full(SeqQueue *Q);
int empty(SeqQueue *Q);
/*-----------------------------------------------------------------------------------------*/
SeqQueue*Q;
void destroyQueue(SeqQueue *Q) {
	free(Q->array);
	free(Q);
}
void clearQueue(SeqQueue *Q) {
	Q->front = Q->rear;
	Q->length = 0;
}
ElementType front(SeqQueue *Q) {
	return Q->array[Q->front];
}
int pop(SeqQueue *Q, ElementType *x) {
	if (empty(Q)) return 0;
	*x = Q->array[Q->front];
	Q->front = (Q->front + 1) % Q->capacity;
	Q->length--;
	return 1;
}
int push(SeqQueue *Q, ElementType x) {
	if (full(Q)) return 0;
	Q->array[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->length++;
	return 1;
}

int empty(SeqQueue *Q) {
	if (Q->front == Q->rear) return 1;
	else return 0;
}
int full(SeqQueue *Q) {
	if (Q->length == Q->capacity) return 1;
	else return 0;
}
SeqQueue* createQueue(int capacity) {
	SeqQueue*Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
	Q->capacity = capacity;
	Q->array = (ElementType*)malloc(sizeof(ElementType) * capacity);
	return Q;
}
/*-----------------------------------------------------------------------------------------*/
int main() {
	int n;
	scanf("%d", &n);
	Q = createQueue(n);
	return 0;
}
