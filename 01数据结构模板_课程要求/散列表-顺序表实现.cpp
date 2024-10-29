#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct {
	ElementType key; //�ؼ�����
	int flag;        //״̬��־��USED(������)��EMPTY(����)
} Cell;

typedef struct {
	Cell *cells;  //ɢ�б��ָ��
	int capacity; //ɢ�б�����
	int size;     //ɢ�б��С
} HashTable;
void insert(HashTable * h, ElementType key);

HashTable * create(int capacity) {
	HashTable* H = (HashTable*)malloc(sizeof(HashTable));
	H->cells = (Cell*)malloc(sizeof(Cell) * capacity);
	H->capacity = capacity;
	H->size = 0;
	return H;
}
int isss(int n) {
	if (n == 2) return 1;
	for (int i = 2; i * i <= n + 1; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int nextPrime(int n) {
	if (n % 2 == 0) n++;
	while (isss(n)) {
		n += 2;
	}
	return n;
}
int Hash(HashTable * h, ElementType key) {
	return key % h->capacity;
}
int find(HashTable * h, ElementType key) {
	int i = 0;
	int temp = key;
	while (1) {
		temp += i * i;
		temp = temp % h->capacity;
		int k = Hash(h, temp);
		if (h->cells[k].flag == 0) return k;
		if (h->cells[k].key == key) return k;
		i++;
	}
}
void rehash(HashTable * h) {
	Cell* cells = h->cells;
	int cap = nextPrime(h->capacity * 2);
	int size = h->capacity;
	h->capacity = cap;//�����ʱ��Ҫ%
	h->cells = (Cell*)malloc(sizeof(Cell) * cap);
	h->size = 0;//�����ʱ���++
	//���޸�h��ֵ
	/*for (int i = 0; i < cap; i++) {
		h->cells[i].flag = 0;
	}*/
	for (int i = 0; i < size; i++) {
		if (cells[i].flag == 1)
			insert(h, cells[i].key);
	}
	free(cells);
};
void insert(HashTable * h, ElementType key) {
	if (h->cells[find(h, key)].flag == 1) return;
	h->cells[find(h, key)].key = key;
	h->cells[find(h, key)].flag = 1;
	h->size++;
	if (h->size > h->capacity / 2) rehash(h);
}
void destroy (HashTable * h) {
	free(h->cells);
	free(h);
}

int main() {
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ��
	*/
	return 0;
}
