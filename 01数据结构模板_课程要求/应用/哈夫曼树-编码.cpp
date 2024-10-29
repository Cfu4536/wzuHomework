#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct {
	KeyType value;
	int weight;
} Node;

typedef struct HTNode {
	KeyType value; //节点数值
	int weight;  //节点权
	HTNode * lchild;
	HTNode * rchild;
	int depth;
	bool operator < (const HTNode &a)const {
		return weight < a.weight || (weight == a.weight && value < a.value);
	}
} HTNode, *HuffmanTree;

typedef HuffmanTree ElementType;
typedef struct {
	ElementType * data; //数据
	int size;	 		//大小
	int capacity;  		//容量
} HNode, *Heap;

void swap(Heap H, int i, int j) {          //交换
	ElementType t;
	t = H->data[i];
	H->data[i] = H->data[j];
	H->data[j] = t;
}
int parent(int i) {          //父节点下标
	return i / 2;
}
int left(int i) {          //左孩子下标
	return i * 2;
}
int right(int i) {          //右孩子下标
	return i * 2 + 1;
}
void heapify(Heap H, int i) {
	int l, r;
	int smallest ;
	l = left(i);
	r = right(i);
	smallest = i;
	if (l <= H->size && *(H->data[l]) < * (H->data[i])) smallest = l;
	if (r <= H->size && *(H->data[r]) < * (H->data[smallest])) smallest = r;
	if (smallest != i) {
		swap(H, i, smallest);
		heapify(H, smallest);
	}
}
void initHeap(Heap H, Node data[], int n) {
	HTNode *p = NULL;
	for (int i = 1; i <= n; i++) {
		p = (HTNode *)malloc(sizeof(HTNode));
		p->value = data[i].value;
		p->weight = data[i].weight;
		p->lchild = NULL;
		p->rchild = NULL;
		H->data[i] = p;
	}
	H->size = n;
	for (int i = n / 2; i >= 1; i--)
		heapify(H, i);
}
ElementType front(Heap H) {
	return H->data[1];
}
void push(Heap H, ElementType x) {
	H->size++;
	int i = H -> size;
	H->data[i] = x;
	while (i > 1 && *(H->data[i]) < * (H->data[parent(i)])) {
		swap(H, i, parent(i));
		i = parent(i);
	}
}
int empty(Heap H) {
	if (H->size == 0) return 1;
	return 0;
}
void pop(Heap H) {
	if (!empty(H)) {
		H->data[1] = H->data[H->size];
		H->size--;
		heapify(H, 1);
	}
}
Heap createHeap(int capacity) {
	Heap p;
	p = (Heap)malloc(sizeof(HNode));
	p->data = (ElementType*)malloc(sizeof(ElementType) * (capacity + 1));
	p->capacity = capacity;
	return p;
}
void destroyHeap(Heap H) {
	if (H != NULL) {
		free(H->data);
		free(H);
	}
}
HuffmanTree createHuffmanTree(Node data[], int n) {
	Heap H = createHeap(n * 2);
	initHeap(H, data, n);
	HTNode *p, *q, *t;
	for (int i = 1; i < n; i++) {
		p = front(H);
		pop(H);
		q = front(H);
		pop(H);
		t = (HTNode *)malloc(sizeof(HTNode));
		t->value = min(p->value, q->value);
		t->weight = p->weight + q->weight;
		t->lchild = p;
		t->rchild = q;
		push(H, t);
	}
	HuffmanTree HT = front(H);
	pop(H);
	destroyHeap(H);
	return HT;
}
void huffmanCode(HuffmanTree HT, int code[], int depth) {
	if (HT == NULL)return ;
	if (HT->lchild == NULL && HT->rchild == NULL) {
		cout << HT->value << ':';
		for (int i = 0; i < depth; i++) cout << code[i];
		cout << endl;
		return;
	}
	if (HT->lchild != NULL) {
		code[depth] = 0;
		huffmanCode(HT->lchild, code, depth + 1);
	}
	if (HT->rchild != NULL) {
		code[depth] = 1;
		huffmanCode(HT->rchild, code, depth + 1);
	}
}
void initDepth(HuffmanTree HT, int depth) {
	if (HT == NULL)
		return;
	HT->depth = depth;//根的深度
	initDepth(HT->lchild, depth + 1);
	initDepth(HT->rchild, depth + 1);
}
int getWPL(HuffmanTree HT) {
	if (HT == NULL)return 0;
	if (HT->lchild == NULL && HT->rchild == NULL)
		return HT->weight * HT->depth;
	return getWPL(HT->lchild) + getWPL(HT->rchild);
}
int main() {
	int n, v, w;
	Node data[100010];
	HuffmanTree hftree;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &v, &w);
		data[i].value = v;
		data[i].weight = w;
	}
	hftree = createHuffmanTree(data, n);
	initDepth(hftree, 0);
	int code[110];
	huffmanCode(hftree, code, 0);
	return 0;
}
