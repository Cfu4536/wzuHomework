#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
	int  coef;	//系数(coefficient)
	int  exp;	//指数(exponent)
	struct Node *next;
} PolyNode, *PolyList;
/*-----------------------------------------------------------------------------------------*/
PolyList L, LA, LB, LC;
PolyList createList() {
	L = (PolyList)malloc(sizeof(PolyNode));
	L->next = NULL;
	return L;
}
void insertTail(PolyList L, int coef, int exp) {
	PolyNode*s;
	PolyNode*p, *pre;
	s = (PolyNode*)malloc(sizeof(PolyNode));
	s->coef = coef;
	s->exp = exp;
	pre = L;
	p = L->next;
	while (p != NULL) {
		pre = p;
		p = p->next;
	}
	s->next = pre->next;
	pre->next = s;
}
void printList(PolyList L) {
	PolyNode*p;
	p = L->next;
	int co, ex;
	int flag = 1;
	if (p == NULL) {
		printf("0");
	}
	while (p != NULL) {
		co = p->coef;
		ex = p->exp;
		p = p->next;
		if (ex == 0) {
			if (flag == 1) {
				if (co == 1) printf("1");
				else if (co == -1) printf("-1");
				else printf("%d", co);
				flag = 0;
			} else {
				if (co == 1) printf("+1");
				else if (co == -1) printf("-1");
				else if (co > 0) printf("+%d", co);
				else printf("%d", co);
			}
		} else if (ex == 1) {
			if (flag == 1) {
				if (co == 1) printf("x");
				else if (co == -1) printf("-x");
				else printf("%dx", co);
				flag = 0;
			} else {
				if (co == 1) printf("+x");
				else if (co == -1) printf("-x");
				else if (co > 0) printf("+%dx", co);
				else printf("%dx", co);
			}
		} else {
			if (flag == 1) {
				if (co == 1) printf("x^%d", ex);
				else if (co == -1) printf("-x^%d", ex);
				else printf("%dx^%d", co, ex);
				flag = 0;
			} else {
				if (co == 1) printf("+x^%d", ex);
				else if (co == -1) printf("-x^%d", ex);
				else if (co > 0) printf("+%dx^%d", co, ex);
				else printf("%dx^%d", co, ex);
			}
		}
	}
	printf("\n");
}
void derivative(PolyList L) {
	PolyNode*p, *pre;
	pre = L;
	p = L->next;
	int co, ex;
	while (p != NULL) {
		co = p->coef;
		ex = p->exp;
		if (ex == 0) {
			pre->next = NULL;
		} else {
			co *= ex;
			ex--;
		}
		p->coef = co;
		p->exp = ex;
		pre = p;
		p = p->next;
	}
}
void polyAdd(PolyList LA, PolyList LB, PolyList LC) {
	PolyNode*pa, *pb, *pc;
	pa = LA->next;
	pb = LB->next;
	pc = LC;
	while (pa != NULL && pb != NULL) {
		if (pa->exp > pb->exp) {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = pa->coef;
			s->exp = pa->exp;
			pc->next = s;
			pc = s;
			pa = pa->next;
		} else if (pa->exp == pb->exp) {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = pa->coef + pb->coef;
			s->exp = pa->exp;
			if (s->coef != 0) {
				pc->next = s;
				pc = s;
				pa = pa->next;
				pb = pb->next;
			} else {
				free(s);
				pa = pa->next;
				pb = pb->next;
			}
		} else {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = pb->coef;
			s->exp = pb->exp;
			pc->next = s;
			pc = s;
			pb = pb->next;
		}
	}
	while (pa != NULL) {
		PolyNode*s;
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = pa->coef;
		s->exp = pa->exp;
		pc->next = s;
		pc = s;
		pa = pa->next;
	}
	while (pb != NULL) {
		PolyNode*s;
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = pb->coef;
		s->exp = pb->exp;
		pc->next = s;
		pc = s;
		pb = pb->next;
	}
}
void polySub(PolyList LA, PolyList LB, PolyList LC) {
	PolyNode*pa, *pb, *pc;
	pa = LA->next;
	pb = LB->next;
	pc = LC;
	while (pa != NULL && pb != NULL) {
		if (pa->exp > pb->exp) {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = pa->coef;
			s->exp = pa->exp;
			pc->next = s;
			pc = s;
			pa = pa->next;
		} else if (pa->exp == pb->exp) {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = pa->coef - pb->coef;
			s->exp = pa->exp;
			if (s->coef != 0) {
				pc->next = s;
				pc = s;
				pa = pa->next;
				pb = pb->next;
			} else {
				free(s);
				pa = pa->next;
				pb = pb->next;
			}
		} else {
			PolyNode*s;
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->coef = -pb->coef;
			s->exp = pb->exp;
			pc->next = s;
			pc = s;
			pb = pb->next;
		}
	}
	while (pa != NULL) {
		PolyNode*s;
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = pa->coef;
		s->exp = pa->exp;
		pc->next = s;
		pc = s;
		pa = pa->next;
	}
	while (pb != NULL) {
		PolyNode*s;
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = -pb->coef;
		s->exp = pb->exp;
		pc->next = s;
		pc = s;
		pb = pb->next;
	}
}
/*-----------------------------------------------------------------------------------------*/
int main() {
	L = createList();
	int n, coef, exp;
	/*	scanf("%d", &n);
		while (n--) {
			scanf("%d %d", &coef, &exp);
			insertTail(L, coef, exp);
		}
		printList(L);
		derivative(L);
		printList(L);
	printf("-------------------xiangjia-------------------------\n");
	LA = createList();
	LB = createList();
	LC = createList();
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &coef, &exp);
		insertTail(LA, coef, exp);
	}//
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &coef, &exp);
		insertTail(LB, coef, exp);
	}//
	polyAdd(LA, LB, LC);
	printList(LC);*/
	printf("-------------------xiangjian-------------------------\n");
	LA = createList();
	LB = createList();
	LC = createList();
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &coef, &exp);
		insertTail(LA, coef, exp);
	}//
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &coef, &exp);
		insertTail(LB, coef, exp);
	}//
	polySub(LA, LB, LC);
	printList(LC);
	return 0;
}
