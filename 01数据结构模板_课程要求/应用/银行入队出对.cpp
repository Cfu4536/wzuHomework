#include<bits/stdc++.h>
using namespace std;
struct customer {
	int no;
	char id[10];
	char guesttype[10];
};
typedef struct Node {
	customer data;
	struct Node *next;
} QNode;
typedef struct {
	QNode *front; //¶ÓÊ×
	QNode *rear;  //¶ÓÎ²
} LinkQueue;

LinkQueue* Q;
LinkQueue* vip;

int od_no = 0, vip_no = 0, no = 0;
int od_out = 0, vip_out = 0;

LinkQueue* createQueue() {
	LinkQueue*Qu;
	Qu = (LinkQueue*)malloc(sizeof(LinkQueue));
	Qu->rear = NULL;
	Qu->front = NULL;
	return Qu;
}
int empty(LinkQueue *Qu) {
	if (Qu->front == NULL) return 1;
	else return 0;
}
int push(LinkQueue *Qu, customer x) {
	QNode*s;
	s = (QNode*)malloc(sizeof(QNode));
	if (s == NULL) {
		return 0;
	}
	s->next = NULL;
	s->data = x;
	if (Qu->front == NULL) {
		Qu->front = s;
		Qu->rear = s;
	} else {
		Qu->rear->next = s;
		Qu->rear = s;
	}
	return 1;
}//push
customer front(LinkQueue *Qu) {
	return Qu->front->data;
}//front
int pop(LinkQueue *Qu) {
	if (empty(Qu)) {
		return 0;
	}
	QNode*p;
	p = Qu->front;
	Qu->front = Qu->front->next;
	free(p);
	return 1;
}
int main() {
	char s[20];
	Q = createQueue();
	vip = createQueue();
	while (1) {
		scanf("%s", s);
		if (strcmp(s, "IN") == 0) {
			char id[10], guesttype[10];
			customer data;
			scanf("%s %s", id, guesttype);
			if (strcmp(guesttype, "Ordinary") == 0) {
				od_no++;
				no++;
				data.no = no;
				strcpy(data.id, id);
				strcpy(data.guesttype, guesttype);
				push(Q, data);
				printf("IN:%d %s %s %d\n", data.no, id, guesttype, od_no + vip_no - vip_out - od_out - 1);
			} else {
				vip_no++;
				no++;
				data.no = no;
				strcpy(data.id, id);
				strcpy(data.guesttype, guesttype);
				push(vip, data);
				printf("IN:%d %s %s %d\n",data.no, id, guesttype, vip_no - vip_out - 1);
			}
		} else if (strcmp(s, "LIST") == 0) {
			printf("LIST:\n");
			for (int i = 1; i <= vip_no - vip_out; i++) {
				customer data;
				data = front(vip);
				printf("%d %s %s\n", data.no, data.id, data.guesttype);
				push(vip, data);
				pop(vip);
			}
			for (int i = 1; i <= od_no - od_out; i++) {
				customer data;
				data = front(Q);
				printf("%d %s %s\n", data.no, data.id, data.guesttype);
				push(Q, data);
				pop(Q);
			}
		} else if (strcmp(s, "OUT") == 0) {
			if (empty(vip) && empty(Q)) {
				printf("FAILED:\n");
			} else {
				customer data;
				if (!empty(vip)) {
					data = front(vip);
					printf("OUT:%d %s %s\n", data.no, data.id, data.guesttype);
					pop(vip);
					vip_out++;
				} else {
					data = front(Q);
					printf("OUT:%d %s %s\n", data.no, data.id, data.guesttype);
					pop(Q);
					od_out++;
				}
			}
		} else if (strcmp(s, "QUIT") == 0) {
			printf("GOOD BYE!\n");
			break;
		}
	}
	return 0;
}
