#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
#define INT_MAX 132

typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
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
			P[i] = s; //i的前驱是s
		}
		finnal[i] = 0;
	}
	finnal[s] = 1;
	P[s] = s; //s 的前驱是s
	D[s] = 0;//初始化
	int k;
	while (1) {
		k = findmin(g, D, finnal);
		if (k == -1) {
			return;
		}
		finnal[k] = 1;
		for (int i = 0; i < g->vertexNum; i++) {
			if (g->edge[k][i] == INT_MAX || finnal[i]) {
				continue;//从k过不去
			}
			if (D[i] > D[k] + g->edge[k][i]) {
				D[i] = D[k] + g->edge[k][i];
				P[i] = k;
			}
		}
	}
}

int main() {
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
	*/
	return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
