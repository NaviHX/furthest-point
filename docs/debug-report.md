# 调试分析报告

## 调试过程中遇到的问题

重复运行程序时,dis数组没有清空导致计算错误

```diff
     cout << "请输入顶点数和边数:";
     cin >> num >> vnum;
+    for (int i = 1; i <= num; i++)
+        for (int j = 1; j <= num; j++)
+            dis[i][j] = 0;
     if (num > 1000)
     {
         cout << "顶点数过大\n\n";
         return;
     }
```

遍历起点时从未初始化的0号结点开始
```diff
-    for (int i = 0; i <= num; i++)
+    for (int i = 1; i <= num; i++)
        if (ve[i].inDegree == 0)
        {
            if (checkCircle(i))
            {
                cout << "查找失败\n图中存在环\n";
                return;
            }
            solveDis(i);
            count++;
        }
```

## 设计回顾

时空分析

|function|T()|S()|
|-|-|-|
|addEdge|O(1)|O(1)|
|vertexInit|O(1)|O(1)|
|solveDis|O(VE)|O(V)|
|work|O(EV^2)|O(V)|
|checkCircle|O(V^2)|O(V)|
