#include<bits/stdc++.h>
#include<windows.h>
#define REP(i,first,last) for(int i=first;i<=last;++i)
#define DOW(i,first,last) for(int i=first;i>=last;--i)

#define RAND_INT Random(-1e9,1e9)
#define RAND_LL Random(-5e17,5e17)
#define _RAND_INT Random(0,1e9)
#define _RAND_LL Random(0,1e18)
#define _abc_ 'a','z'
#define _ABC_ 'A','Z'
#define NUM '0','9'
#define CHAR 32,126
std::vector<int>null_vector;
struct Graph
{
	std::vector<std::vector<int> >out_point;
	Graph(int n=0)
	{
		REP(i,0,n)
		{
			out_point.push_back(null_vector);
		}
	}
	void AddEdge(int form,int to)
	{
		out_point[form].push_back(to);
	}
	void Clean()
	{
		out_point.clear();
	}
};
#define FOR(edge,now) for(int edge_i=0,to=edge.out_point[now].size()?edge.out_point[now][0]:0;edge_i<edge.out_point[now].size();edge_i++,to=edge.out_point[now][edge_i])
namespace MD
{
	unsigned long long seed=233;
	void Srand(unsigned long long a=time(NULL))
	{
		seed=a;
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
	}
	void Begin()
	{
		Sleep(1000);
		srand(time(NULL));
		Srand();
	}
	long long Random(long long a)
	{
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
		return seed%a;
	}
	long long Random(long long f,long long e)
	{
		return f+Random(e-f+1);
	}
	char RandomChar(char l,char r)
	{
		return (char)Random(l,r);
	}
	char RandomChar(char *s)
	{
		return s[Random(strlen(s))];
	}
	void MakeArray(long long *array,int l,int r,long long num_l,long long num_r)
	{
		REP(i,l,r)
		{
			array[i]=Random(num_l,num_r);
		}
	}
	void MakeArray(long long *array,int n,long long num_l,long long num_r)
	{
		REP(i,1,n)
		{
			array[i]=Random(num_l,num_r);
		}
	}
	void MakeArray(long long *array,int l,int r,long long(*MakeNum)())
	{
		REP(i,l,r)
		{
			array[i]=MakeNum();
		}
	}
	void MakeArray(long long *array,int n,long long(*MakeNum)())
	{
		REP(i,1,n)
		{
			array[i]=MakeNum();
		}
	}
	void MakeArray(int *array,int n)
	{
		REP(i,1,n)
		{
			array[i]=i;
		}
		std::random_shuffle(array+1,array+1+n);
	}
	void MakeString(char *s,int l,int r,char *t)
	{
		int lent=strlen(t);
		REP(i,l,r)
		{
			s[i]=t[Random(lent)];
		}
	}
	void MakeString(char *s,int len,char *t)
	{
		int lent=strlen(t);
		REP(i,0,len-1)
		{
			s[i]=t[Random(lent)];
		}
	}
	void MakeRange(long long &l,long long &r,long long range_l,long long range_r)
	{
		long long len=range_r-range_l+1;
		if(Random(1,len*(len+1))<=len-1)
		{
			l=r=Random(range_l,range_r);
			return;
		}
		l=Random(range_l,range_r);
		r=Random(range_l,range_r);
		if(r<l)
		{
			std::swap(l,r);
		}
	}
	std::vector<int>f;
	std::vector<int>father;
	int Find(int now)
	{
		if(now==f[now])
		{
			return now;
		}
		return f[now]=Find(f[now]);
	}
	void MakeTree(Graph &a,int n,int root=1,int opt=0,int k=2)
	{
		a=Graph(n);
		if(n<2)
		{
			return;
		}
		if(opt==0)
		{
			f.clear();
			REP(i,0,n)
			{
				f.push_back(i);
			}
			int father;
			REP(i,1,n)
			{
				if(i^root)
				{
					father=Random(1,n);
					while(Find(father)==Find(i))
					{
						father=Random(1,n);
					}
					a.AddEdge(father,i);
					a.AddEdge(i,father);
				}
				f[Find(i)]=Find(father);
			}
		}
		if(opt==1)
		{
			father.clear();
			REP(i,1,n)
			{
				father.push_back(i);
			}
			std::random_shuffle(father.begin(),father.end());
			REP(i,0,father.size()-1)
			{
				if(father[i]==root)
				{
					std::swap(father[i],father[0]);
				}
			}
			REP(i,1,father.size()-1)
			{
				a.AddEdge(father[i-1],father[i]);
				a.AddEdge(father[i],father[i-1]);
			}
		}
		if(opt==2)
		{
			REP(i,1,n)
			{
				if(i^root)
				{
					a.AddEdge(i,root);
					a.AddEdge(root,i);
				}
			}
		}
		if(opt==3)
		{
			f.clear();
			father.clear();
			REP(i,0,n)
			{
				f.push_back(i);
				father.push_back(0);
			}
			int fa;
			REP(i,1,n)
			{
				if(i^root)
				{
					fa=Random(1,n);
					while(Find(fa)==Find(i)||father[fa]==k)
					{
						fa=Random(1,n);
					}
					father[fa]++;
					f[Find(i)]=Find(fa);
					a.AddEdge(fa,i);
					a.AddEdge(i,fa);
				}
			}
		}
		if(opt==4)
		{
			father.clear();
			REP(i,0,n)
			{
				father.push_back(i);
			}
			std::swap(father[1],father[root]);
			std::random_shuffle(father.begin()+2,father.end());
			REP(i,2,n)
			{
				a.AddEdge(father[i],father[i/2]);
				a.AddEdge(father[i/2],father[i]);
			}
		}
	}
	void WriteArray(long long *array,int l,int r,char s[2]=" \n")
	{
		REP(i,l,r)
		{
			printf("%lld%c",array[i],s[i==r]);
		}
	}
	std::vector<std::pair<int,int> >edge;
	void WriteGraph(Graph &a,int opt=0)
	{
		if(!a.out_point.size())
		{
			return;
		}
		edge.clear();
		REP(i,1,a.out_point.size()-1)
		{
			FOR(a,i)
			{
				if(opt==1)
				{
					if(i<to)
					{
						edge.push_back(std::make_pair(i,to));
					}
				}
				if(opt==0)
				{
					edge.push_back(std::make_pair(i,to));
				}
			}
		}
		std::random_shuffle(edge.begin(),edge.end());
		if(edge.size())
		{
			REP(i,0,edge.size()-1)
			{
				if(Random(2))
				{
					printf("%d %d\n",edge[i].first,edge[i].second);
				}
				else
				{
					printf("%d %d\n",edge[i].second,edge[i].first);
				}
			}
		}
	}
}
