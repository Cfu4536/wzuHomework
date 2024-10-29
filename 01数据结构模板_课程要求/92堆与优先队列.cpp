#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct {
	ElementType *data; //����
	int size;	 		//��С
	int capacity;  		//����
} HNode, *Heap;

Heap createHeap(int capacity) {          //����
	Heap p;
	p = (Heap)malloc(sizeof(HNode));
	p->data = (ElementType*)malloc(sizeof(ElementType) * (capacity + 1));
	p->size = 0;
	p->capacity = capacity;
	return p;
}
int parent(int i) {          //���ڵ��±�
	return i / 2;
}
int left(int i) {          //�����±�
	return i * 2;
}
int right(int i) {          //�Һ����±�
	return i * 2 + 1;
}
int full(Heap H) {          //����
	if (H->size == H->capacity) return 1;
	return 0;
}
int empty(Heap H) {          //�п�
	if (H->size == 0) return 1;
	return 0;
}
void swap(Heap H, int i, int j) {          //����
	ElementType t;
	t = H->data[i];
	H->data[i] = H->data[j];
	H->data[j] = t;
}
void increase(Heap H, int i, ElementType x) {          //�ڵ�����
	if (H->data[i] < x) {
		H->data[i] = x;
		while (i > 1 && H->data[i] > H->data[parent(i)]) {
			swap(H, i, parent(i));
			i = parent(i);
		}
	}
}
int insert(Heap H, ElementType x) {          //����
	if (full(H)) return 0;
	H->size++;
	int i = H->size;
	H->data[i] = x;
	while (i > 1 && H->data[i] > H->data[parent(i)]) {
		swap(H, i, parent(i));
		i = parent(i);
	}
	return 1;
}
void heapify(Heap H, int i) {          //�����ӽڵ�����
	int l, r, largest;
	l = left(i);
	r = right(i);
	if (l <= H->size && H->data[i] < H->data[l]) largest = l;
	else largest = i;
	if (r <= H->size && H->data[largest] < H->data[r]) largest = r;
	if (largest != i) {
		swap(H, i, largest);
		heapify(H, largest);
	}
}
void initHeap(Heap H, ElementType data[], int n) {          //��ʼ��
	for (int i = 1; i <= n; i++) H->data[i] = data[i];
	H->size = n;
	for (int i = n / 2; i >= 1; i--) {
		heapify(H, i);
	}
}
void heapSort(Heap H) {          //������
	int n = H->size;
	for (int i = H->size; i > 1; i--) {
		swap(H, 1, i);
		H->size--;
		heapify(H, 1);
	}
	H->size = n;
}
void destroyHeap(Heap H) {          //����
	if (H != NULL) {
		free(H->data);
		free(H);
	}
}
void pop(Heap H) {          //���ȶ��г���
	if (!empty(H)) {
		H->data[1] = H->data[H->size];
		H->size--;
		heapify(H, 1);
	}
}
int push(Heap H, ElementType x) {          //���ȶ������
	return insert(H, x);
}
ElementType front(Heap H) {          //���ȶ��ж�������
	return H->data[1];
}
int main() {

	return 0;
}
