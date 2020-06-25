# MakeData.h

一个用于生成数据的库

## Srand(ull seed)

初始化随机数,默认为 `seed=time(NULL)`.

## Bgein()

开始生成一个数据,其中包含 `Sleep(1000)`(防止相邻数据的随机化种子相同)以及初始化随机数.

## Random(ll a)

等概率随机生成一个 ![](https://latex.codecogs.com/svg.latex?[0,a%29) 内的整数.

## Random(ll l,ll r)

等概率随机生成一个 ![](https://latex.codecogs.com/svg.latex?[l,r]) 内的整数.

## RandomChar(char l,char r)

随机返回一个在 ![](https://latex.codecogs.com/svg.latex?l) 到 ![](https://latex.codecogs.com/svg.latex?r) 范围内的字符.

其中包含以下可用的宏定义:

```cpp
#define _abc_ 'a','z'//小写字母
#define _ABC_ 'A','Z'//大写字母
#define NUM '0','9'//数字
#define CHAR 32,126//可见字符
```

~~虽然这个东西和 `Random(ll l,ll r)` 一毛一样.~~

## RandomChar(char *s)

随机返回字符串 ![](https://latex.codecogs.com/svg.latex?s) 中的一个字符.

其中如果 `s="abb"`,那么返回的元素出现 `a` 的概率为 ![](https://latex.codecogs.com/svg.latex?\frac{1}{3}),出现 `b` 的概率为 ![](https://latex.codecogs.com/svg.latex?\frac{2}{3}).

## MakeArray(ll \*array,int l,int r,ll num_l,ll num_r)

对于 ![](https://latex.codecogs.com/svg.latex?array_l\sim%20array_r) 中的元素随机给出一个 ![](https://latex.codecogs.com/svg.latex?[num\_l,num\_r]) 范围内的整数.

## MakeArray(ll \*array,int n,ll num_l,ll num_r)

相当于 `MakeArray(array,1,n,num_l,num_r)`.

## MakeArray(ll \*array,int l,int r,ll(\*MakeNum)())

对于 ![](https://latex.codecogs.com/svg.latex?array_l\sim%20array_r) 中的元素都用 `MakeNum()` 赋值一次.

## MakeArray(ll \*array,int n,ll(\*MakeNum)())

相当于 `MakeArray(array,1,n,MakeNum())`.

## MakeArray(int \*array,int n)

对于 ![](https://latex.codecogs.com/svg.latex?array_1\sim%20array_n) 中的元素随机给出一个 ![](https://latex.codecogs.com/svg.latex?1\sim%20n) 的排列(![](https://latex.codecogs.com/svg.latex?1\sim%20n) 中每个元素有且出现一次但是没有顺序).

## MakeString(char \*s,int l,int r,char *t)

对于 ![](https://latex.codecogs.com/svg.latex?s_l\sim%20s_r) 中的元素都等概率随机给出 `t[]` 中的元素.

其中如果 `t="abb"`,那么对于 ![](https://latex.codecogs.com/svg.latex?s) 中的每个元素出现 `a` 的概率为 ![](https://latex.codecogs.com/svg.latex?\frac{1}{3}),出现 `b` 的概率为 ![](https://latex.codecogs.com/svg.latex?\frac{2}{3}).

## MakeString(char \*s,int len,char *t)

相当于 `MakeString(s,0,len-1,char t[])`.

## MakeRange(int &l,int &r,int range_l,int range_r)

将 ![](https://latex.codecogs.com/svg.latex?l,r) 变成 ![](https://latex.codecogs.com/svg.latex?[range\_l,range\_r]) 内的随机一个整数,且严格保证 ![](https://latex.codecogs.com/svg.latex?l\leq%20r).

## MakeTree(int \*father,int n,int root,int opt,int k)

制造一颗树,其中 ![](https://latex.codecogs.com/svg.latex?root) 的默认值为 ![](https://latex.codecogs.com/svg.latex?1),![](https://latex.codecogs.com/svg.latex?opt) 的默认值为 ![](https://latex.codecogs.com/svg.latex?0),![](https://latex.codecogs.com/svg.latex?k) 的默认值为 ![](https://latex.codecogs.com/svg.latex?2).

对于不同的 ![](https://latex.codecogs.com/svg.latex?opt=):

0. 随机生成一颗以 ![](https://latex.codecogs.com/svg.latex?root) 为根的树.
1. 随机生成一颗以 ![](https://latex.codecogs.com/svg.latex?root) 为根的树,且保证这棵树是一条链
2. 生成一颗以 ![](https://latex.codecogs.com/svg.latex?root) 为根的菊花图(即 ![](https://latex.codecogs.com/svg.latex?root) 的度为 ![](https://latex.codecogs.com/svg.latex?n-1).
3. 生成一颗以 ![](https://latex.codecogs.com/svg.latex?root) 为根的 ![](https://latex.codecogs.com/svg.latex?k) 叉树(即每个点的儿子个数小于等于 ![](https://latex.codecogs.com/svg.latex?k),默认生成的是二叉树)

## WriteArray(ll \*array,int l,int r,char s[2])

输出 ![](https://latex.codecogs.com/svg.latex?array_l\sim%20array_r),其中对于 ![](https://latex.codecogs.com/svg.latex?array_l\sim%20array_{r-1}) 后会输出 `s[0]`,![](https://latex.codecogs.com/svg.latex?array_r) 后会输出 `s[1]`.

其中 ![](https://latex.codecogs.com/svg.latex?s) 的默认值是 `" \n"`,即在一行内输出 ![](https://latex.codecogs.com/svg.latex?array_l\sim%20array_r) 用空格隔开,并且在最后换行.

## WriteTree(int *father,int n)

输出一颗树.

输出有 ![](https://latex.codecogs.com/svg.latex?n-1) 行,每行包含两个数字 ![](https://latex.codecogs.com/svg.latex?a,b),表示在 ![](https://latex.codecogs.com/svg.latex?a,b) 中有一条边,其中 ![](https://latex.codecogs.com/svg.latex?father) 数组必须保证在 ![](https://latex.codecogs.com/svg.latex?1\sim%20n) 的范围内有且只有一个 ![](https://latex.codecogs.com/svg.latex?0),且必须为一颗树,否则不保证输出正确,建议用 `MakeTree()` 来生成所需的树.

# make.bat

一个可以和 makedata.h 一起使用的批处理文件.

## 使用方法

makedata.exe,std.exe,make.bat 放在同一目录下,并运行 bat 文件,其中的 ![](https://latex.codecogs.com/svg.latex?l) 和 ![](https://latex.codecogs.com/svg.latex?r) 为数据的编号范围 ![](https://latex.codecogs.com/svg.latex?l.cpp\sim%20r.cpp).

其中的 std 和 makedata 都不需要读入输出文件.

# 近期推出(完善)

建各种图,用于存图的结构体(树的部分也会使用).

欢迎联系 QQ2303504461 提出建议.
