#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
	int visited[MAXVEX];//遍历标记. 1:已遍历  0:未遍历
	int vertexNum, edgeNum;
} MGraph, *Graph;
Graph createGraph() {
	Graph M = (Graph)malloc(sizeof(MGraph));
	M->edgeNum = 0;
	M->vertexNum = 0;
	return M;
}
int locateVertex(Graph g, VertexType v) {
	for (int i = 0; i < g->vertexNum; i++) {
		if (g->vexs[i] == v) return i;
	}
	return -1;
}
void addVertex(Graph g, VertexType v) {
	if (locateVertex(g, v) != -1) return;
	int n = g->vertexNum;
	g->vexs[n] = v;
	g->vertexNum++;
	for (int i = 0; i <= n; i++) {
		g->edge[n][i] = 0;
		g->edge[i][n] = 0;
	}
}
void addEdge(Graph g, VertexType x, VertexType y) {
	int i = locateVertex(g, x);
	int j = locateVertex(g, y);
	if (i != -1 && j != -1 && g->edge[i][j] == 0 ) {
		g->edge[i][j] = 1;
		g->edge[j][i] = 1;
		g->edgeNum++;
	}
}
void delEdge(Graph g, VertexType x, VertexType y) {
	int i = locateVertex(g, x);
	int j = locateVertex(g, y);
	if (i != -1 && j != -1 && g->edge[i][j] == 1 ) {
		g->edge[i][j] = 0;
		g->edge[j][i] = 0;
		g->edgeNum--;
	}
}
void delVertex(Graph g, VertexType v) {
	int k = locateVertex(g, v);
	if (k == -1) return;
	int n = g->vertexNum - 1;
	g->vexs[k] = g->vexs[n];
	for (int i = 0; i < g->vertexNum ; i++) {
		if (g->edge[i][k] == 1) g->edgeNum --;
		g->edge[i][k] = g->edge[i][n];
	}
	for (int i = 0; i < g->vertexNum; i++) {
		g->edge[k][i] = g->edge[n][i];
	}
	g->vertexNum--;
}
int degree(Graph g, VertexType v) {
	int k = locateVertex(g, v);
	int cnt = 0;
	for (int i = 0; i < g->vertexNum; i++) {
		if (g->edge[k][i] == 1) cnt++;
	}
	return cnt;
}
void DFS(Graph g, int i) {
	if (i >= g->vertexNum) return;
	g->visited[i] = 1;
	for (int j = 0; j < g->vertexNum; j++) {
		if (g->edge[i][j] == 1 && g->visited[j] == 0) DFS(g, j);
	}
}
void BFS(Graph g, int i) {
	queue<int>Q;
	Q.push(i);
	g->visited[i] = 1;
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int j = 0; j < g->vertexNum; j++) {
			if (g->edge[j][k] == 1 && g->visited[j] == 0) {
				Q.push(j);
				g->visited[j] = 1;
			}
		}
	}
}
void destroyGraph(Graph g) {
	free(g);
}
int distance(Graph g, VertexType v, VertexType u) {
	int x = locateVertex(g, v);
	int y = locateVertex(g, u);
	for (int i = 0; i < g->vertexNum; i++) {
		g->visited[i] = -1;
	}//初始化
	queue<int>Q;//广搜

	Q.push(x);
	g->visited[x] = 0;
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int j = 0; j < g->vertexNum; j++) {
			if (g->edge[j][k] == 1 && g->visited[j] == -1) {
				Q.push(j);
				g->visited[j] = g->visited[k] + 1;//长度+1
			}
		}
	}
	if (g->visited[y] == -1) return 0;
	return g->visited[y];
}
int connectedComps(Graph g) {//分支数
	int cnt = 0;
	for (int i = 0; i < g->vertexNum; i++) {
		if (g->visited[i] == 0) {
			cnt++;
			BFS(g, i);
		}
	}
	return cnt;
}
int connect(Graph g, VertexType v, VertexType u) {
	int x = locateVertex(g, v);
	int y = locateVertex(g, u);
	BFS(g, x);
	if (g->visited[y] == 1) return 1;
	return 0;
}

int main() {

	return 0;
}
