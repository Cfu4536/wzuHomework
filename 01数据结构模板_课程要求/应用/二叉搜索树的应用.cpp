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

void printTree(BSTree bt){
    if(bt!=NULL){
        printf("%d",bt->data);
        if(bt->lchild!=NULL||bt->rchild!=NULL){
            printf("(");
            printTree(bt->lchild);
            printf(",");
            printTree(bt->rchild);
            printf(")");
        }
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
}
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
	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		root = insert(root, t);
	}
	printTree(root);
	cout<<endl;
	return 0;
}
