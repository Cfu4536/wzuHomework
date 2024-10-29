#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct HashNode {
	ElementType key;
	struct HashNode * next;
} HashNode, * List;

typedef struct {
	int size;
	List * lists;//槽指针,所有链表均有头结点
} HashTable;
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
HashTable * create(int size) {
	HashTable* h = (HashTable*)malloc(sizeof(HashTable));
	h->size = nextPrime(size);
	h->lists = (List*)malloc(sizeof(List) * h->size);
	for (int i = 0; i < h->size; i++) {
		h->lists[i] = (List)malloc(sizeof(HashNode));
		h->lists[i]->next = NULL;
	}
	return h;
}
int Hash(HashTable * h, ElementType key) {
	return key % h->size;
}
HashNode * find(HashTable * h, ElementType key) {
	int k = Hash(h, key);
	for (HashNode*p = h->lists[k]; p != NULL; p = p->next) {
		if (p->key == key) return p;
	}
	return NULL;
}
void insert(HashTable * h, ElementType key) {
	if (find(h, key) != NULL) return;
	HashNode*s = (HashNode*)malloc(sizeof(HashNode));
	s->key = key;
	s->next = h->lists[key % h->size]->next;
	h->lists[key % h->size]->next = s;
}
HashNode * findPre(HashTable * h, ElementType key) {
	int k = Hash(h, key);
	HashNode*pre = NULL;
	for (HashNode*p = h->lists[k]; p != NULL; p = p->next) {
		if (p->key == key) return pre;
		pre = p;
	}
	return NULL;
}
void del(HashTable * h, ElementType key) {
	HashNode*p = find(h, key);
	if ( p == NULL) return;
	HashNode*pre = findPre(h, key);
	pre->next = p->next;
	free(p);
}
void destroy(HashTable * h) {
	HashNode*pre, *p;
	for (int i = 0; i < h->size; i++) {
		p = h->lists[i];
		while (p != NULL) {
			pre = p;
			p = p->next;
			free(pre);
		}
	}
	free(h->lists);
	free(h);
}
int main() {

	return 0;
}
