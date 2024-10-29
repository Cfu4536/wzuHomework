#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 99
#define MAXVEX 200 //最大顶点数
typedef char VertexType;

typedef struct ENode {
	int adjVertex;  //该边所指的顶点编号
	int weight;     //边权
	struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode {
	VertexType data;   //顶点信息
	int visited; //遍历标记. 1:已遍历  0:未遍历
	ENode *firstEdge; //第一条出边
} VNode;

typedef struct {
	VNode vexs[MAXVEX];
	int vertexNum, edgeNum; //点数和边数
} AdjGraph, *Graph;

void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]) {
	int n = g->vertexNum;
	ENode*p;/**/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				D[i][j] = 0;
			} else {
				D[i][j] = INT_MAX;
			}
			P[i][j] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		p = g->vexs[i].firstEdge;
		while (p != NULL) {
			int j = p->adjVertex;/**/
			D[i][j] = p->weight;
			p = p->nextEdge;
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
	/*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
	*/
	return 0;
}
/**/
