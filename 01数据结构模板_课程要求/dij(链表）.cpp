#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 99
#define MAXVEX 200 //��󶥵���
typedef char VertexType;

typedef struct ENode {
	int adjVertex;  //�ñ���ָ�Ķ�����
	int weight;     //��Ȩ
	struct ENode *nextEdge;  //��һ����
} ENode;

typedef struct VNode {
	VertexType data;   //������Ϣ
	int visited; //�������. 1:�ѱ���  0:δ����
	ENode *firstEdge; //��һ������
} VNode;

typedef struct {
	VNode vexs[MAXVEX];
	int vertexNum, edgeNum; //�����ͱ���
} AdjGraph, *Graph;

int findmin(Graph g, int D[], int finnal[]) {
	int k = -1;
	int min = INT_MAX;
	for (int i = 0; i < g->vertexNum; i++) {
		if (finnal[i] != 1 && min > D[i]) {
			min = D[i];
			k = i;
		}
	}
	return k;
}
void Dijkstra(Graph g, int s, int D[], int P[]) {
	ENode*p;
	int final[MAXVEX];
	for (int i = 0; i < g->vertexNum; i++) {
		D[i] = INT_MAX;
		final[i] = 0;
	}
	p = g->vexs[s].firstEdge;
	while (p != NULL) {
		D[p->adjVertex] = p->weight;
		P[p->adjVertex] = s;
		p = p->nextEdge;
	}
	final[s] = 1;
	D[s] = 0;
	while (1) {
		int k = findmin(g, D, final);
		if (k == -1) {
			return;
		}
		final[k] = 1;
		p = g->vexs[k].firstEdge;
		while (p != NULL) {
			if (final[p->adjVertex] == 0 && D[p->adjVertex] > D[k] + p->weight) {
				D[p->adjVertex] = D[k] + p->weight;
				P[p->adjVertex] = k;
			}
			p=p->nextEdge;
		}
	}
}

int main() {
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ��
	*/
	return 0;
}
