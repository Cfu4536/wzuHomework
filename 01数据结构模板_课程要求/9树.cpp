#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct CSNode {
	ElementType data;
	struct CSNode * child;
	struct CSNode * sibling;
} CSTNode, *CSTree;

CSTree NewNode(char c) {
	CSTree p = (CSTree)malloc(sizeof(CSTNode));
	p->data = c;
	p->child = NULL;
	p->sibling = NULL;
	return p;
}
CSTree createTree(char s[]) {
	int k, top;
	CSTree path[100], p, t;
	k = 0;
	top = -1;
	for (int i = 0; s[i] != '\0'; i++) {
		if (isalpha(s[i])) {
			p = NewNode(s[i]);
			if (k == 0) path[0] = p;
			else if (k == 1) path[top]->child = p;
			else if (k == 2) {
				t = path[top]->child;
				while (t->sibling != NULL) {
					t = t->sibling;
				}
				t->sibling = p;
			}
		}
		if (s[i] == '(') {
			path[++top] = p;
			k = 1;
		}
		if (s[i] == ',') {
			k = 2;
		}
		if (s[i] == ')') {
			top--;
		}
	}
	return path[0];
}
void preOrder(CSTree root) {
	CSTree p;
	if (root != NULL) {
		printf("%c", root->data);
		preOrder(root->child);
		if (root->child != NULL) {
			for (p = root->child->sibling; p != NULL; p = p->sibling)
				preOrder(p);
		}
	}
}
void postOrder(CSTree root) {
	CSTree p;
	if (root != NULL) {
		postOrder(root->child);
		if (root->child != NULL) {
			for (p = root->child->sibling; p != NULL; p = p->sibling)
				postOrder(p);
		}
		printf("%c", root->data);
	}
}
int main() {
	char s[1000];
	CSTree tree;
	scanf("%s", s);
	tree = createTree(s);
	preOrder(tree);
	cout << endl;
	postOrder(tree);
	return 0;
}
