# makedata.h

一个用于生成数据的 C++ 库。

## 全局函数

### Max(a,b)

返回 $a,b$ 中较大的值，如果有大于两个参数也可以通过空格隔开查询，如 `Max(a,b,c)`。

### Min(a,b)

返回 $a,b$ 中较小的值，如果有大于两个参数也可以通过空格隔开查询，如 `Max(a,b,c)`。

### Swap(a,b)

交换 $a,b$ 的值。

### UnorderedPair(a,b)

返回一个 `std::pair<int,int>` 表示**无序对** $(a,b)$。

### EdgePair(a,b,link)

返回一个 `std::pair<int,int>` 表示一条边 $(a,b)$，若 $link=1$ 则返回无序对（无向图），否则返回有序对（有向图）。 

## namespace IO

### Write(a)

输出 $a$ 的内容，如果要输出多种不同类型的内容可以通过空格隔开如 `Write(123," 123");`。

### Writeln()

输出回车。

### Writeln(a)

同 `Write()` 函数，但是会在输出完其中内容后输出一个回车。

## namespace MD

### Srand()

设置随机数种子。

引用库时后，运行程序时会默认以 `std::chrono::high_resolution_clock::now().time_since_epoch().count()` 作为种子。

### Random()

返回一个 $[0,2^{64})$ 范围内的随机数。

### RandomShuffle(begin,end)

同 `std::random_shuffle` 但是使用库中的随机数。

### Random(l,r)

返回 $[l,r]$ 范围内的随机数（$l\leq r$ 且为同类型整数）。

### Random(a)

返回 $[0,a)$ 范围内的随机数。

### RandomChar(s[],len=-1)

若 $len$ 为 $-1$ 则会在 $s$ 中随机一个字符返回。

否则会在 $s$ 的 $[0,len)$ 中随机一个字符返回。

### Graph

表示图的类。

下标从 $1$ 开始。

包含图中边从信息和图的类型 $link$（若为 $1$ 则为无向图，否则为有向图）。

通过 $\text{Graph(n,link)}$ 初始化。

#### Size()

返回图中点的个数。

#### Edge()

返回图中边的个数。

#### Clean()

清空图，需要重新初始化。

#### 遍历

对于一个 $Graph$ 类型的变量 $g$，可以通过 `FOR(g,i)` 枚举 $i$ 的出边，会存储在 $to$ 变量中。

#### AddEdge(u,v)

添加一条 $(u,v)$ 边，若为无向图，则也会添加反向边。

#### ReShuffle(root=0)

打乱图中的点的编号，若 $root\not=0$，则 $root$ 点的编号不会被打乱。

#### Write()

输出图，共 $\text{Edge()}$ 行，每行两个由空格隔开的整数，表示一条边。

#### Write(F())

输出图，共 $\text{Edge()}$ 行，每行三个由空格隔开的整数，表示一条边和由 $\text{F()}$ 生成的边权。

#### Merge(g,add_edge=0,l=-1,r=-1)

将该图与 $g$ 图合并，会将 $g$ 图中的点的编号加上当前图的点的个数。

在合并后会在两个子图中选择 $add\_edge$ 条新的边连接两个图。

其中在第二个图中选择的点的编号在 $[l,r]$ 范围内。若为 $-1$ 则设置为默认值 $l=1$ 和 $r=g.Size()$。

### MakeSimpleTree(n,kind,link)

生成一个 $Graph(n,link)$ 的树。

生成的树都比较特殊，更具 $kind$ 分类为（其中若 $link=0$，树为有根树，连边均从编号较小的点连向编号较大的点）：

0. 每个大于 $1$ 的节点会选择一个编号小于自己的点连边；
1. 每个大于 $1$ 的节点会选择一个编号为自己减一的点连边；（为一条长度为 $n$ 的链）
2. 每个大于 $1$ 的节点会选择 $1$ 号点连边；（为包含 $n-1$ 个叶节点的菊花树）
3. 每个大于 $1$ 的节点会选择自己编号除以二向下取整的编号的点连边；（完全二叉树）
4. 会选择 $[3,10]$ 个点与 $1$ 连边，剩下的点与这几个点连边；
5. 会选择 $[\lfloor\frac{n}{3}\rfloor,2\lfloor\frac{n}{3}\rfloor]$ 个点与 $1$ 连边，剩下的点与这几个点连边。

### MixTree(n,link,div=3)

生成一个 $\text{Graph(n,link)}$ 的树。

通过 $\text{MakeSimpleTree()}$ 函数生成的特殊的树通过拼接生成一个较大的树。

当 $n$ 较大时（阈值为 $15$），会先构造大小约为 $\frac{n}{div}$ 大小的链（$kind$ 为 $1$）和菊花树（$kind$ 为 $2$）树合并。剩余节点生成若干较小的树（随机选择 $kind$）继续合并。

### GraphAddEdge(g,add_edge)

在图 $g$ 中添加 $add\_edge$ 条边，保证与原图无重边和自环。

该函数会判断图是否稠密，通过不同方式加边。

### MakeSimpleGraph(n,m,kind,link)

生成一个 $\text{Graph(n,link)}$ 且包含 $m$ 条边的图。

需要注意必须满足 $m\geq n-1$。

生成的图都比较特殊，更具 $kind$ 分类为：

0. 通过 $\text{MixTree(n,link)}$ 生成一颗 $n$ 个节点的树，并通过 $\text{GraphAddEdge()}$ 添加 $m-n+1$ 条边；
1. 这个 $kind$ 必须满足 $m\geq n$，会先生成一个 $n$ 个节点的环，再添加 $m-n$ 条边；
2. 生成链，并添加 $m-n+1$ 条边；
3. 生成菊花树，并添加 $m-n+1$ 条边。

### MixGraphConnect(n,m,link,div=4)

通过 $\text{MakeSimpleGraph()}$ 函数生成一个连通图。

### MixGraph(n,m,link,connect_num=-1)

通过 $\text{MixGraphConnect()}$ 尝试生成 $connect\_num$（若为 $-1$ 则会在一个范围内随机）个连通子图构成的图。

如果剩余的边过多可能最后连通块个数会小于 $connect\_num$。

## define

## bat

在文件夹中需要有 `std.cpp` 和 `generator.cpp`。

### compile.bat

编译 `std.cpp` 和 `generator.cpp`。

### make.bat

输入 $left$ 和 $right$，会通过 `generator.exe` 生成 `i.in` 并使用 `std.exe` 获得 `i.out`，其中 $i\in[left,right]$。

生成的数据会保存到 `/data` 文件夹中（不存在会尝试新建该文件夹），同时会复制 `generator.cpp` 到文件夹中的 `generator(left-right).cpp` 文件。
