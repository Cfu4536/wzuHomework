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
CSTree createTree() {
	char a, buf[100];
	scanf("%c", &a);
	getchar();
	CSTree root = NewNode(a);
	CSTree u, p, t;
	queue <CSTree> q;
	q.push(root);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		gets(buf);
		if (buf[0] == '#') {
			continue;
		}
		p = NewNode(buf[0]);
		u->child = p;
		q.push(p);
		for (int i = 1; buf[i] != '#'; i++) {
			p = NewNode(buf[i]);
			q.push(p);
			t = u->child;
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = p;
		}
	}
	return root;
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
	CSTree tree;
	tree = createTree();
	preOrder(tree);
	cout << endl;
	postOrder(tree);
	return 0;
}
