# MakeData.h

一个用于生成数据的库

## Srand(ull seed)

初始化随机数,默认为 `seed=time(NULL)`.

## Begin()

开始生成一个数据,其中包含 `Sleep(1000)`(防止相邻数据的随机化种子相同)以及初始化随机数.

## RandomNumber(ll a)

等概率随机生成一个 ![](https://latex.codecogs.com/svg.latex?[0,a%29) 内的整数.

## Random(T l,T r)

等概率随机生成一个 ![](https://latex.codecogs.com/svg.latex?[l,r]) 内的整数.

```cpp
#define _abc_ 'a','z'//小写字母
#define _ABC_ 'A','Z'//大写字母
#define NUM '0','9'//数字
#define CHAR 32,126//可见字符
```

## MakeRange(ll/int &l,ll/int &r,ll/int range_l,ll/int range_r)

将 ![](https://latex.codecogs.com/svg.latex?l,r) 变成 ![](https://latex.codecogs.com/svg.latex?[range\_l,range\_r]) 内的随机一个整数,且严格保证 ![](https://latex.codecogs.com/svg.latex?l\leq%20r).

## struct Graph

一个用于存储图的结构体.

构造函数 `Graph(n,l)`,其中 ![](https://latex.codecogs.com/svg.latex?n) 为节点个数编号为 ![](https://latex.codecogs.com/svg.latex?1\sim%20n),![](https://latex.codecogs.com/svg.latex?l) 是否为有向图(![](https://latex.codecogs.com/svg.latex?l=0) 为有向图,![](https://latex.codecogs.com/svg.latex?l=1) 为无向图).

### Graph.AddEdge(int a,int b)

添加一条连接 ![](https://latex.codecogs.com/svg.latex?a,b) 的边.

### Graph.Write()

输出这个图.

### Clean()

清空图.

对于此结构体包含以下 `define`:

```cpp
#define FOR(edge,now) for(int edge_i=0,to=edge.out_point[now].size()?edge.out_point[now][0]:0;edge_i<edge.out_point[now].size();edge_i++,to=edge.out_point[now][edge_i])
/*
FOR(e,a) 表示在遍历 e 这个图中 a 的出边,其中 to 表示连出的节点的编号
*/
```
## MakeTree(Graph &a,int n,int root,bool link,int opt,int k)

其中 ![](https://latex.codecogs.com/svg.latex?root) 默认为 ![](https://latex.codecogs.com/svg.latex?1),![](https://latex.codecogs.com/svg.latex?link) 默认为 ![](https://latex.codecogs.com/svg.latex?0),![](https://latex.codecogs.com/svg.latex?opt) 默认为 ![](https://latex.codecogs.com/svg.latex?0),![](https://latex.codecogs.com/svg.latex?k) 默认为 ![](https://latex.codecogs.com/svg.latex?2).

![](https://latex.codecogs.com/svg.latex?a) 表示要生成的树所存储的图,![](https://latex.codecogs.com/svg.latex?n) 表示有 ![](https://latex.codecogs.com/svg.latex?n) 个节点,![](https://latex.codecogs.com/svg.latex?root) 表示根节点编号,![](https://latex.codecogs.com/svg.latex?link) 表示十分是无向图(![](https://latex.codecogs.com/svg.latex?link=0) 是有向图,只有父亲向儿子连边,![](https://latex.codecogs.com/svg.latex?link=1) 是无向图),![](https://latex.codecogs.com/svg.latex?opt) 表示生成树的种类,![](https://latex.codecogs.com/svg.latex?k) 是辅助用数.

![](https://latex.codecogs.com/svg.latex?opt):

0. 生成一颗随机的树.
1. 生成一条随机的链.
2. 生成一个随机的菊花图(根节点出度为 ![](https://latex.codecogs.com/svg.latex?n-1)).
3. 生成一个随机的 ![](https://latex.codecogs.com/svg.latex?k) 叉树(每个点的儿子个数最多为 ![](https://latex.codecogs.com/svg.latex?k)).
4. 生成一个随机的满二叉树.

## MakeGraph(Graph &gra,int n,int m,bool connect,bool link,int opt)

其中 ![](https://latex.codecogs.com/svg.latex?connect) 默认值为 ![](https://latex.codecogs.com/svg.latex?0),![](https://latex.codecogs.com/svg.latex?link) 默认为 ![](https://latex.codecogs.com/svg.latex?0),![](https://latex.codecogs.com/svg.latex?opt) 默认为 ![](https://latex.codecogs.com/svg.latex?0).

![](https://latex.codecogs.com/svg.latex?a) 表示要生成的图所存储的图,![](https://latex.codecogs.com/svg.latex?n) 表示有 ![](https://latex.codecogs.com/svg.latex?n) 个节点,![](https://latex.codecogs.com/svg.latex?m) 表示有 ![](https://latex.codecogs.com/svg.latex?m) 条边,![](https://latex.codecogs.com/svg.latex?connect) 表示是否连通(![](https://latex.codecogs.com/svg.latex?connect=0) 表示不一定连通,![](https://latex.codecogs.com/svg.latex?connect=1) 表示连通,即每个点都可以到所有其他的点),![](https://latex.codecogs.com/svg.latex?link) 表示是否是无向图(![](https://latex.codecogs.com/svg.latex?link=0) 是有向图,![](https://latex.codecogs.com/svg.latex?link=1) 是无向图),![](https://latex.codecogs.com/svg.latex?opt) 表示生成图的种类.

![](https://latex.codecogs.com/svg.latex?opt):

0. 一个随机的图.

# make.bat

一个可以和 makedata.h 一起使用的批处理文件.

## 使用方法

makedata.exe,std.exe,make.bat 放在同一目录下,并运行 bat 文件,其中的 ![](https://latex.codecogs.com/svg.latex?l) 和 ![](https://latex.codecogs.com/svg.latex?r) 为数据的编号范围 ![](https://latex.codecogs.com/svg.latex?l.cpp\sim%20r.cpp).

其中的 std 和 makedata 都不需要读入输出文件.

# 近期推出(完善)

各种图和树.

欢迎联系 QQ2303504461 提出建议.
