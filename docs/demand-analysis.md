# 需求分析

任务: 找出一个有向无环图中相距最远的两个点

输入数据: DAG的顶点数n和边数m,下面m行是每一条边的起点,终点和边权  
输出数据: 相距最远的两个点,最远的路经  

测试数据:  
输入:
```
9 9
1 2 3
1 3 4
2 4 1
3 4 5
5 6 1
6 8 2
6 7 10
4 9 1
7 9 1
```
输出
```
相距最远的两点为: 5 9
最远路径: 5 -> 6 -> 7 -> 9
```
