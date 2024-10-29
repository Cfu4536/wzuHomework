#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node {
	ElementType data;
	struct Node *lchild;
	struct Node *rchild;
} BTNode, *BTree;
BTree root;
BTree createTree(char s[]) {
	BTree path[100], p;
	int top = -1, k = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (isalpha(s[i])) {
			p = (BTree)malloc(sizeof(BTNode));
			p->data = s[i];
			p->lchild = NULL;
			p->rchild = NULL;
			if (k == 0) path[0] = p;
			else if (k == 1) {
				path[top]->lchild = p;
			} else if (k == 2) {
				path[top]->rchild = p;
			}
		} else if (s[i] == '(') {
			top++;
			path[top] = p;
			k = 1;
		} else if (s[i] == ',') {
			k = 2;
		} else if (s[i] == ')') {
			top--;
		}
	}
	return path[0];
}
void preOrder(BTree bt) {
	if (bt != NULL) {
		printf("%c", bt->data);
		preOrder(bt->lchild);
		preOrder(bt->rchild);
	}
}
void inOrder(BTree rt) {
	if (rt != NULL) {
		inOrder(rt->lchild);
		printf("%c", rt->data);
		inOrder(rt->rchild);
	}
}
void postOrder(BTree rt) {
	if (rt != NULL) {
		postOrder(rt->lchild);
		postOrder(rt->rchild);
		printf("%c", rt->data);
	}
}
void layerOrder(BTree rt) {
	queue<BTree>Q;
	BTNode*p;
	Q.push(rt);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		printf("%c", p->data);
		if (p->lchild != NULL) {
			Q.push(p->lchild);
		}
		if (p->rchild != NULL) {
			Q.push(p->rchild);
		}
	}
}
int main() {
	char s[50] = "A(B(D,),C(E,F(,H))),";
	root = createTree(s);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");
	layerOrder(root);
	printf("\n");
	return 0;
}
