# 概要设计

## 功能思路

先找到DAG中入度为0的点,以这些点为起点开始,加入到队列中,遍历队列头的每一条边,如果经由队列头到这条边的终点的距离大于到终点的距离,则更新距离并将终点加到队列中,直到队列中不再有节点为止  

## 数据结构类型定义

```c++
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
    int from;        //如果该点在最远距离路径上,表示路径上该点前一个点
};
```

## 主程序流程

```c++
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
```

## 函数调用关系

main()调用work(), work()调用addEdge(),vertexInit(),solveDis()
