#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int* array;
	int length;
	int capacity;
} Seqlist;
Seqlist* L;
Seqlist* creat_seqlist() {
	L = (Seqlist*)malloc(sizeof(Seqlist));
	L->array = (int*)malloc(sizeof(int));
	L->length = 0;
	L->capacity = 100;
}

int isempty(Seqlist*L);
int insert(int i, int x);
int get_data(int x);
void destory(Seqlist*L);

int main() {
	L = creat_seqlist();
	if (isempty(L) == 0) {
		printf("it is empty!\n");
	} else {
		printf("it is not empty");
	}
	for (int i = 0; i <= 5; i++) {
		insert(i, i);
	}
	printf("%d\n", get_data(2));
	destory(L);
	return 0;
}
void destory(Seqlist* L) {
	free(L->array);
	free(L);
}

int isempty(Seqlist*L) {
	return L->length;
}
int insert(int i, int x) {
	L->array[i] = x;
	L->length++;
}
int get_data(int x) {
	return L->array[x - 1];
}
