#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100 /*最大顶点数*/
typedef char VertexType;

struct AOENetworkStruct;
typedef struct AOENetworkStruct *AOENetwork;

typedef struct ENode {
	int adjVertex;  //边的终点编号
	int weight;     //边权
	int earliest;   //活动最早开始时间
	int latest;     //活动最晚开始时间
	struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode {
	VertexType data;    //顶点信息/
	int inDegree;       //入度/
	int earliest;       //事件最早发生时间/
	int latest;         //事件最晚发生时间
	ENode *firstEdge; //第一条出边
} VNode;

struct AOENetworkStruct {
	VNode vexs[MAXVEX];    //点表
	int vertexNum, edgeNum; //顶点数和弧数
};


int locateVertex(AOENetwork g, VertexType v) {
	for (int i = 0; i < g->vertexNum; i++) {
		if (g->vexs[i].data == v) return i;
	}
	return -1;
}//查找点的编号
void addVertex(AOENetwork g, VertexType v) {
	if (locateVertex(g, v) != -1) {
		return;
	}
	g->vexs[g->vertexNum].data = v;
	g->vexs[g->vertexNum].firstEdge = NULL;
	g->vexs[g->vertexNum].inDegree= 0;
	g->vertexNum++;

}//插入点
ENode* findEdge(AOENetwork g, int i, int j) {
	for (ENode*p = g->vexs[i].firstEdge; p != NULL; p = p->nextEdge) {
		if (p->adjVertex == j) return p;
	}
	return NULL;
}//查找边的指针
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w) {
	int i = locateVertex(g, v1);
	int j = locateVertex(g, v2);
	if (i == -1 || j == -1) return;
	ENode*p = findEdge(g, i, j);
	if (p != NULL) {
		if (p->weight > w) p->weight = w;
		return;
	}
	ENode*s = (ENode*)malloc(sizeof(ENode));
	s->adjVertex = j;
	s->weight = w;
	s->nextEdge = g->vexs[i].firstEdge;
	g->vexs[i].firstEdge = s;
	g->edgeNum++;
	g->vexs[j].inDegree++;
}//插入边
int TopSort(AOENetwork g, stack<int>&out) {
	int count, i, x, y;
	ENode* p;
	stack<int> in;
	for (i = 0; i < g->vertexNum; i++) {
		g->vexs[i].earliest = 0;
		if (g->vexs[i].inDegree == 0) in.push(i);
	}
	count = 0;
	while (!in.empty()) {
		x = in.top();
		in.pop();
		count++;
		out.push(x);
		for (p = g->vexs[x].firstEdge; p != NULL; p = p->nextEdge) {
			y = p->adjVertex;
			g->vexs[y].inDegree--;
			if (g->vexs[y].inDegree == 0) in.push(y);
			if (g->vexs[y].earliest < g->vexs[x].earliest + p->weight)
				g->vexs[y].earliest = g->vexs[x].earliest + p->weight;
		}
	}
	if (count < g->vertexNum) return 0;
	return 1;
}//最早发生时间
void event(AOENetwork g) {
	stack<int>out;
	if (!TopSort(g, out)) {
		return;
	}
	for (int i = 0; i < g->vertexNum; i++) {
		g->vexs[i].latest = g->vexs[g->vertexNum - 1].earliest;
	}
	while (!out.empty()) {
		int x = out.top();
		out.pop();
		for (ENode*p = g->vexs[x].firstEdge; p != NULL; p = p->nextEdge) {
			int y = p->adjVertex;
			if (g->vexs[x].latest > g->vexs[y].latest - p->weight) {
				g->vexs[x].latest = g->vexs[y].latest - p->weight;
			}
		}
	}
}//最晚发生时间
int active(AOENetwork g) {
	int x, y;
	ENode*p;
	int cnt = 0;
	for (x = 0; x < g->vertexNum; x++) {
		for (p = g->vexs[x].firstEdge; p != NULL; p = p->nextEdge) {
			y = p->adjVertex;
			p->earliest = g->vexs[x].earliest;
			p->latest = g->vexs[y].latest - p->weight ;
			if (p->earliest == p->latest) {
				cnt++;
			}
		}
	}
	return cnt;
}//所有边的早晚发生时间

int DFS(AOENetwork g, int x) {
	int n = 0;
	if (x == g->vertexNum - 1) return 1;
	ENode*p = NULL;
	for (p = g->vexs[x].firstEdge; p != NULL; p = p->nextEdge) {
		if (p->earliest != p->latest) {
			continue;
		} else {
			n += DFS(g, p->adjVertex);
		}
	}
	return n;
}
int pathNum(AOENetwork g) {
	return DFS(g, 0);
}//关键路径数

AOENetwork createGraph() {
	AOENetwork aoe = (AOENetwork)malloc(sizeof(AOENetworkStruct));
	aoe->edgeNum = 0;
	aoe->vertexNum = 0;
	return aoe;
}
int main() {
	int n;
	AOENetwork g = createGraph();
	cin >> n;
	char s[110];
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++) {
		addVertex(g, s[i]);
	}
	while (1) {
		getchar();
		char a, b;
		int w;
		scanf("%c%c", &a, &b);
		if (a == '0' && b == '0') break;
		scanf("%d", &w);
		addEdge(g, a, b, w);
	}
	event(g);
	active(g);
	cout << pathNum(g) << endl;
	return 0;
}
