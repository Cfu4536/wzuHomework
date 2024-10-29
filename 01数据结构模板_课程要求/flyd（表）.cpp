#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //�����
	EdgeType edge[MAXVEX][MAXVEX]; //�ڽӾ���,���߱�
	int vertexNum, edgeNum;
} MGraph, *Graph;

#define INT_MAX 0x7fffffff

void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]) {
	int n = g->vertexNum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j ++ ) {
			/**/	if (i == j) {
				D[i][j] = 0;
			} else {
				D[i][j] = g->edge[i][j];
			}
			P[i][j] = i;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (D[i][k] == INT_MAX) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (i == j || D[k][j] == INT_MAX) {
					continue;
				}
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}
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
