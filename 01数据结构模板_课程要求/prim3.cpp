#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 99
#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
	int vertexNum, edgeNum;
} MGraph, *Graph;
int locateVertex(Graph G, VertexType v) {
	return 1;
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
	int k = locateVertex(g, u);
	int n = g->vertexNum;
	for (int i = 0; i < n; i++) {
		lowcost[i] = g->edge[k][i];
	}
	lowcost[k] = 0;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		k = findmin(lowcost, n);
		if (k == -1) return -1;
		sum += lowcost[k];
		lowcost[k] = 0;
		for (int j = 0; j < n; j++) {
			if (lowcost[j] != 0 && lowcost[j] > g->edge[k][j]) {
				lowcost[j] = g->edge[k][j];
			}
		}
	}
	return sum;
}

int main() {

	return 0;
}
