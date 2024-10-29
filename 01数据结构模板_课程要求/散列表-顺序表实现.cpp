#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct {
	ElementType key; //关键数字
	int flag;        //状态标志：USED(槽已用)或EMPTY(空闲)
} Cell;

typedef struct {
	Cell *cells;  //散列表槽指针
	int capacity; //散列表容量
	int size;     //散列表大小
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
	h->capacity = cap;//插入的时候要%
	h->cells = (Cell*)malloc(sizeof(Cell) * cap);
	h->size = 0;//插入的时候会++
	//先修改h的值
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
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
	*/
	return 0;
}
