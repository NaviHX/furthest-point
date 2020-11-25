#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct edge
{
    int weight;     //边权
    int from;       //出点
    int to;         //入点
    edge *nextEdge; //下一条边的指针
};

struct vertex
{
    int inDegree;    //入度
    int outDegree;   //出度
    edge *firstEdge; //第一条边的指针
};

int dis[1001][1001];
vertex ve[1001];

void addEdge(int from,int to,int weight);
void vertexInit(vertex* v);
