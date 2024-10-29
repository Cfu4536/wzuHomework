#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 99
#define MAXVEX 1000 //最大顶点数
typedef char VertexType;

typedef struct ENode {
	int adjVertex;  //该边所指的顶点编号
	int weight;     //边权
	struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode {
	VertexType data;   //顶点信息
	ENode *firstEdge; //第一条出边
} VNode;

typedef struct {
	VNode vexs[MAXVEX];
	int vertexNum, edgeNum; //点数和边数
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
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
	*/
	return 0;
}
