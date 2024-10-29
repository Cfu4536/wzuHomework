#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node {
	ElementType  data;
	struct Node  *lchild;
	struct Node  *rchild;
} BSTNode, *BSTree;
BSTree newnode(int x) {
	BSTree root = (BSTree)malloc(sizeof(BSTNode));
	root->data = x;
	root->lchild = NULL;
	root->rchild = NULL;
	return root;
}

BSTree insert(BSTree bst, ElementType x) {
	if (bst == NULL) bst = newnode(x);
	else if (x < bst->data) bst->lchild = insert(bst->lchild, x);
	else if (x > bst->data) bst->rchild = insert(bst->rchild, x);
	return bst;
}
void inOrder(BSTree bst) {
	if (bst != NULL) {
		inOrder(bst->lchild);
		printf("%d ", bst->data);
		inOrder(bst->rchild);
	}
}

BSTNode* findMin(BSTree bst) {
	if (bst == NULL) return NULL;
	while (bst->lchild != NULL) {
		bst = bst->lchild;
	}
	return bst;
}
BSTNode* findMax(BSTree bst) {
	if (bst == NULL) return NULL;
	while (bst->rchild != NULL) {
		bst = bst->rchild;
	}
	return bst;
}
BSTNode* find(BSTree bst, ElementType x) {
	while (bst != NULL) {
		if (x < bst->data) bst = bst->lchild;
		else if (x > bst->data) bst = bst->rchild;
		else return bst;
	}
	return bst;
}/*µÝ¹éÐ´·¨
BSTNode* find(BSTree bst, ElementType x) {
	BSTree a = bst;
	if (a == NULL)return NULL;
	else if (x == a->data) return a;
	else if (x < a->data) return find(a->lchild, x);
	else if (x > a->data) return find(a->rchild, x);
}*/
BSTree deleteNode(BSTree bst, ElementType x) {
	BSTNode* p;
	if (bst == NULL) return bst;
	if (x < bst->data) bst->lchild = deleteNode(bst->lchild, x);
	else if (x > bst->data) bst->rchild = deleteNode(bst->rchild, x);
	else {
		if (bst->lchild != NULL && bst->rchild != NULL) {
			p = findMin(bst->rchild);
			bst->data = p->data;
			bst->rchild = deleteNode(bst->rchild, bst->data);
		} else {
			p = bst;
			if (bst->lchild == NULL) bst = bst->rchild;
			else if (bst->rchild == NULL) bst = bst->lchild;
			free(p);
		}
	}
	return bst;
}
BSTree destroyBSTree(BSTree bst) {
	if (bst != NULL) {
		destroyBSTree(bst->lchild);
		destroyBSTree(bst->rchild);
		free(bst);
	}
	return NULL;
}
int main() {
	BSTree root = NULL;
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 7);
	inOrder(root);
	cout << endl;
	BSTree p;
	p = findMin(root);
	cout << p->data << endl;
	p = findMax(root);
	cout << p->data << endl;
	p = find(root, 2);
	if (p == NULL)
		cout << "-1" << endl;
	root = deleteNode(root, 3);
	inOrder(root);
	destroyBSTree(root);
	return 0;
}
