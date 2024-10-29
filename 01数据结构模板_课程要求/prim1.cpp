#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 99
#define MAXVEX 1000 //��󶥵���
typedef char VertexType;

typedef struct ENode {
	int adjVertex;  //�ñ���ָ�Ķ�����
	int weight;     //��Ȩ
	struct ENode *nextEdge;  //��һ����
} ENode;

typedef struct VNode {
	VertexType data;   //������Ϣ
	ENode *firstEdge; //��һ������
} VNode;

typedef struct {
	VNode vexs[MAXVEX];
	int vertexNum, edgeNum; //�����ͱ���
} AdjGraph, *Graph;
int locateVertex(Graph G, VertexType v) {
	return 0;
}
int findmin(int lowcost[], int n) {
	int k = -1;
	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (lowcost[i] != 0 && min > lowcost[i]) {
			min = lowcost[i];
			k = i;
		}
	}
	return k;
}
int Prim(Graph g, VertexType u) {
	int lowcost[MAXVEX];
	int n = g->vertexNum;
	ENode*p;
	for (int i = 1; i < n; i++) {
		lowcost[i] = INT_MAX;
	}
	int k = locateVertex(g, u);
	lowcost[k] = 0;
	p = g->vexs[k].firstEdge;
	while (p != NULL) {
		int j = p->adjVertex;
		lowcost[j] = p->weight;
		p = p->nextEdge;
	}//initial
	int sum = 0;
	for (int i = 1; i < n; i++) {
		k = findmin(lowcost, n);
		if (k == -1) return -1;
		sum += lowcost[k];
		lowcost[k] = 0;
		p = g->vexs[k].firstEdge;
		while (p != NULL) {
			int j = p->adjVertex;
			if (lowcost[j] != 0 && lowcost[j] > p->weight) {
				lowcost[j] = p->weight;
			}
			p = p->nextEdge;
		}
	}
	return sum;
}

int main() {
	/*�˴������ɲ��Գ����Զ���ӣ���ҪΪ����˳����в�������
	���������,��������Ĵ˴�����ľ���ʵ��ϸ�ڡ�
	����б�Ҫ�����Լ���Ӵ����Բ�����ĺ����Ƿ���ȷ��
	*/
	return 0;
}
