# 详细设计

void addEdge(int from, int to, int weight)  
向图中添加边
```c++
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
```

void vertexInit(vertex *v)  
初始化顶点
```c++
void vertexInit(vertex *v)
{
    v->firstEdge = NULL;
    v->inDegree = 0;
    v->outDegree = 0;
    v->from = -1;
}
```

void work()  
处理用户输入,计算路径,输出结果
```c++
void work()
{
    int num, vnum; //点数 边数
    int ans, ansFrom, ansTo; //输出
    int start, end, w;
    //用户输入
    for (int i = 0; i <= num; i++)
        if (ve[i].inDegree == 0)
            solveDis(i); //从每一个入度为零的点开始计算
    for (int i = 1; i <= num; i++)
        for (int j = 1; j <= num; j++)
            //遍历数组找到最远的两点
    cout << "相距最远的两点为: " << ansFrom << " "<< ansTo << "\n";
    cout<< "最远路径: ";
    int cur=ansTo;
    stack<int> s;
    while(cur!=-1)
    {
        s.push(cur);
        cur=ve[cur].from;
    }
    cout<<s.top();
    s.pop();
    while(!s.empty())
    {
        cout<<" -> "<<s.top();
        s.pop();
    }
    cout<<"\n";
    return;
}
```

void solveDis(int num)  
求出从num开始的最远距离
```c++
void solveDis(int num)
{
    queue<int> q;
    dis[num][num] = 0;
    q.push(num);
    while (!q.empty())
    {
        int cur = q.front();
        edge *p = ve[cur].firstEdge;
        while (p) //遍历每一条边
        {
            int to = p->to;
            if (dis[num][p->to] < dis[num][p->from] + p->weight)
            {
                //顶点入队
                //更新距离
                //更新顶点前驱
            }
            p = p->nextEdge;
        }
        q.pop();
    }
}
```
