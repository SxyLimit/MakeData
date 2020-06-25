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
	Graph(int n)
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
	int point[10000005];
	int out[10000005];
	void MakeTree(int *father,int n,int root=1,int opt=0,int k=2)
	{
		if(n==1)
		{
			return;
		}
		if(opt==0)
		{
			REP(i,1,n)
			{
				if(i^root)
				{
					father[i]=Random(1,n);
				}
			}
		}
		if(opt==1)
		{
			REP(i,1,n)
			{
				father[i]=i%n+1;
			}
			REP(i,1,n)
			{
				int a=Random(1,n);
				int b=Random(1,n);
				if(father[a]^b&&father[b]^a)
				{
					std::swap(father[a],father[b]);
				}
			}
		}
		if(opt==2)
		{
			REP(i,1,n)
			{
				if(i^root)
				{
					father[i]=root;
				}
			}
		}
		if(opt==3)
		{
			REP(i,1,n)
			{
				point[i]=i;
				out[i]=0;
			}
			std::random_shuffle(point+1,point+1+n);
			REP(i,1,n)
			{
				if(point[i]^root)
				{
					father[point[i]]=Random(1,n);
					while(out[father[point[i]]]==k)
					{
						father[point[i]]=Random(1,n);
					}
					out[father[point[i]]]++;
				}
			}
		}
		if(opt==4)
		{
			REP(i,1,n)
			{
				point[i]=i;
			}
			std::swap(point[1],point[root]);
			std::random_shuffle(point+2,point+1+n);
			REP(i,2,n)
			{
				father[point[i]]=point[i/2];
			}
		}
		father[root]=0;
	}
	void WriteArray(long long *array,int l,int r,char s[2]=" \n")
	{
		REP(i,l,r)
		{
			printf("%lld%c",array[i],s[i==r]);
		}
	}
	std::vector<std::pair<int,int> >edge;
	void WriteTree(int *father,int n)
	{
		edge.clear();
		REP(i,1,n)
		{
			edge.push_back(std::make_pair(father[i],i));
		}
		std::random_shuffle(edge.begin(),edge.end());
		REP(i,1,n)
		{
			if(edge[i].first)
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
	void WriteGraph(Graph &a)
	{
		edge.clear();
		REP(i,1,a.out_point.size())
		{
			FOR(a,i)
			{
				edge.push_back(std::make_pair(i,to));
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
