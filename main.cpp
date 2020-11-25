#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>

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

#ifdef DEBUG
int dis[11][11];
vertex ve[1001];
#else
int dis[1001][1001];
vertex ve[1001];
#endif

void addEdge(int from, int to, int weight);
void vertexInit(vertex *v);
void work();
void solveDis(int num);

int main()
{
    int arg;
    do
    {
        cout << "请输入功能选项\n1.求最远两点\n0.结束程序\n选项:";
        cin >> arg;
        switch (arg)
        {
        case 1:
            work();
            break;
        case 0:
            cout << "感谢使用\n";
            break;
        default:
            cout << "无效的选项\n";
            break;
        }
        cout << "\n";
    } while (arg);
    return 0;
}

void addEdge(int from, int to, int weight)
{
    edge *e = (edge *)malloc(sizeof(edge));
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->nextEdge = ve[from].firstEdge;
    ve[from].firstEdge = e;
    ve[from].outDegree++;
    ve[to].inDegree++;
}

void vertexInit(vertex *v)
{
    v->firstEdge = NULL;
    v->inDegree = 0;
    v->outDegree = 0;
}

void work()
{
    int num, vnum;
    int ans, ansFrom, ansTo;
    int start, end, w;
    cout << "请输入顶点数和边数:";
    cin >> num >> vnum;
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            dis[i][j] = 0;
    if (num > 1000)
    {
        cout << "顶点数过大\n\n";
        return;
    }
    for (int i = 1; i <= num; i++)
        vertexInit(ve + i);
    cout << "请输入每条边的起点,终点,边权 (点的编号从1开始, 到n结束) :\n";
    for (int i = 1; i <= vnum; i++)
    {
        cin >> start >> end >> w;
        addEdge(start, end, w);
    }
    for (int i = 0; i <= num; i++)
        if (ve[i].inDegree == 0)
            solveDis(i);
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            if (ans < dis[i][j])
            {
                ans = dis[i][j];
                ansFrom = i;
                ansTo = j;
            }
    cout << "相距最远的两点为: " << ansFrom << " "
         << " " << ansTo << "\n\n";
    return;
}

void solveDis(int num)
{
    queue<int> q;
    dis[num][num] = 0;
    q.push(num);
    while (!q.empty())
    {
        int cur = q.front();
        edge *p = ve[cur].firstEdge;
        while (p)
        {
            int to = p->to;
            if (dis[num][p->to] < dis[num][p->from] + p->weight)
            {
                q.push(p->to);
                dis[num][p->to] = dis[num][p->from] + p->weight;
            }
            p = p->nextEdge;
        }
        q.pop();
    }
}
