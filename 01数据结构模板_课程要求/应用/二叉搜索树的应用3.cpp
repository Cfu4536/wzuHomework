#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node {
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
} BSTNode, *BSTree;
BSTNode* find(BSTree bst, ElementType x) {
	while (bst != NULL) {
		if (x < bst->data) bst = bst->lchild;
		else if (x > bst->data) bst = bst->rchild;
		else return bst;
	}
	return bst;
}
BSTNode* createTree() {
	int k = 0, num = 0;
	char s;
	BSTNode *tree[10000], *p;
	int top = 0;
	s = getchar();
	while (1) {
		if (isalnum(s)) {
			while (isalnum(s)) {
				num = num * 10 + s - '0';
				s = getchar();
			}
			p = (BSTNode*)malloc(sizeof(BSTNode));
			p->data = num;
			num = 0;
			p->lchild = NULL;
			p->rchild = NULL;
			if (k == 1) {
				tree[top]->lchild = p;
			} else if (k == 2) {
				tree[top]->rchild = p;
			}
		} else if (s == '(') {
			top++;
			tree[top] = p;
			k = 1;
			s = getchar();
		} else if (s == ',') {
			k = 2;
			s = getchar();
		} else if (s == ')') {
			top--;
			s = getchar();
		} else {
			break;
		}
	}
	return tree[1];
}
int main() {
	BSTree root = NULL;
	BSTNode*f;
	root = createTree();
	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		f = find(root, t);
		if (f == NULL) {
			cout << "no" << endl;
		} else {
			cout << "yes" << endl;
		}
	}
	return 0;
}
