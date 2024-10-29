#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
#define INT_MAX 132

typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //�����
	EdgeType edge[MAXVEX][MAXVEX]; //�ڽӾ���,���߱�
	int vertexNum, edgeNum;
} MGraph, *Graph;
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
	int finnal[MAXVEX];
	for (int i = 0; i < g->vertexNum; i++) {
		D[i] = g->edge[s][i];
		if (D[i] != INT_MAX) {
			P[i] = s; //i��ǰ����s
		}
		finnal[i] = 0;
	}
	finnal[s] = 1;
	P[s] = s; //s ��ǰ����s
	D[s] = 0;//��ʼ��
	int k;
	while (1) {
		k = findmin(g, D, finnal);
		if (k == -1) {
			return;
		}
		finnal[k] = 1;
		for (int i = 0; i < g->vertexNum; i++) {
			if (g->edge[k][i] == INT_MAX || finnal[i]) {
				continue;//��k����ȥ
			}
			if (D[i] > D[k] + g->edge[k][i]) {
				D[i] = D[k] + g->edge[k][i];
				P[i] = k;
			}
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
/*����ύ�Ĵ��뽫������ڴ˴����������Ŀ��Ҫ��ĺ����Ķ���*/
