#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	char id[10];
	char name[20];
	char sex;
	double x, y, z;
	struct Node  *next;
} Node, *LinkList;
LinkList L;

LinkList createList();
void insert();
void stu_list();
void stu_find();
void stu_change();
void stu_delete();
void listsort(LinkList L);
void listswap(LinkList l1, LinkList l2, LinkList l3);

char opt[10], id[10], name[20], sex;
char findid[10];
double x, y, z;
int stucount = 0;

int main() {
	L = createList();
	while (1) {
		scanf("%s", opt);
		if (strcmp(opt, "Insert") == 0) {
			scanf("%s %s %c %lf %lf %lf", id, name, &sex, &x, &y, &z);
			strcpy(findid, id);
			insert();
		} else if (strcmp(opt, "List") == 0) {
			stu_list();
		} else if (strcmp(opt, "Find") == 0) {
			scanf("%s", findid);
			stu_find();
		} else if (strcmp(opt, "Change") == 0) {
			scanf("%s %s %c %lf %lf %lf", id, name, &sex, &x, &y, &z);
			strcpy(findid, id);
			stu_change();
		} else if (strcmp(opt, "Delete") == 0) {
			scanf("%s", findid);
			stu_delete();
		} else {
			printf("Good bye!\n");
			break;
		}
	}
	return 0;
}

LinkList createList() {
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}
void listswap(LinkList l1, LinkList l2, LinkList l3) {
	l1->next = l2->next;
	l2->next = l3->next;
	l3->next = l2;
}
void insert() {
	Node* p = L->next;
	Node*pre = L;
	printf("Insert:\n");
	while (p != NULL) {
		if (strcmp(p->id, findid) == 0) {
			break;
		}
		pre = p;
		p = p->next;
	}
	if (p != NULL) {
		printf("Failed\n");
	} else {
		Node* s = (Node*)malloc(sizeof(Node));
		strcpy(s->id, id);
		strcpy(s->name, name);
		s->sex = sex;
		s->x = x;
		s->y = y;
		s->z = z;
		pre->next = s;
		s->next = NULL;
		printf("%s %s %c %.1f %.1f %.1f\n", id, name, sex, x, y, z);
		stucount++;
	}
}
void stu_list() {
	listsort(L);
	Node* p = L->next;
	printf("List:\n");
	while (p != NULL) {
		printf("%s %s %c %.1f %.1f %.1f\n", p->id, p->name, p->sex, p->x, p->y, p->z);
		p = p->next;
	}
}
void stu_find() {
	Node* p = L->next;
	printf("Find:\n");
	while (p != NULL) {
		if (strcmp(p->id, findid) == 0) {
			printf("%s %s %c %.1f %.1f %.1f\n", p->id, p->name, p->sex, p->x, p->y, p->z);
			break;
		}
		p = p->next;
	}
	if (p == NULL) printf("Failed\n");
}
void stu_change() {
	Node* p = L->next;
	while (p != NULL) {
		if (strcmp(p->id, findid) == 0) {
			break;
		}
		p = p->next;
	}
	printf("Change:\n");
	if (p == NULL) {
		printf("Failed\n");
	} else {
		strcpy(p->name, name);
		p->sex = sex;
		p->x = x;
		p->y = y;
		p->z = z;
		printf("%s %s %c %.1f %.1f %.1f\n", p->id, p->name, p->sex, p->x, p->y, p->z);
	}
}
void stu_delete() {
	Node* p = L->next;
	Node*pre = L;
	printf("Delete:\n");
	while (p != NULL) {
		if (strcmp(p->id, findid) == 0) {
			break;
		}
		pre = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("Failed\n");
	} else {
		pre->next = p->next;
		free(p);
		printf("Deleted\n");
		stucount--;
	}
}
void listsort(LinkList L) {
	LinkList pi = L, pj = L;
	while (pi->next != NULL) {
		pj = pi;
		while (pj->next->next != NULL) {
			if (strcmp(pj->next->id,pj->next->next->id)>0) {
				listswap(pj, pj->next, pj->next->next);
			}
			pj = pj->next;
		}
		pi = pi->next;
	}
}
