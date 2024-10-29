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
int main() {
	BSTree root = NULL;
	BSTNode*f;
	root = createTree();
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
