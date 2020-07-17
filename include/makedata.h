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
#define FOR(edge,now) for(int edge_i=0,to=edge.out_point[now].size()?edge.out_point[now][0]:0;edge_i<edge.out_point[now].size();edge_i++,to=edge.out_point[now][edge_i])
struct Graph
{
	std::vector<std::vector<int> >out_point;
	bool link;
	Graph(int n=0,bool l=0)
	{
		link=l;
		REP(i,0,n)
		{
			out_point.push_back(null_vector);
		}
	}
	void AddEdge(int form,int to)
	{
		out_point[form].push_back(to);
		if(link)
		{
			out_point[to].push_back(form);
		}
	}
	void Clean()
	{
		out_point.clear();
	}
};
namespace MD
{
	unsigned long long seed=233;
	void Srand(unsigned long long a=time(NULL)){seed=a;seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;}
	void Begin(){Sleep(1000);srand(time(NULL));Srand();}
	long long Random(long long a){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;return seed%a;}
	long long Random(long long f,long long e){return f+Random(e-f+1);}
	char RandomChar(char l,char r){return (char)Random(l,r);}
	char RandomChar(char *s){return s[Random(strlen(s))];}
	void MakeArray(long long *array,int l,int r,long long num_l,long long num_r){REP(i,l,r){array[i]=Random(num_l,num_r);}}
	void MakeArray(long long *array,int n,long long num_l,long long num_r){REP(i,1,n){array[i]=Random(num_l,num_r);}}
	void MakeArray(long long *array,int l,int r,long long(*MakeNum)()){REP(i,l,r){array[i]=MakeNum();}}
	void MakeArray(long long *array,int n,long long(*MakeNum)()){REP(i,1,n){array[i]=MakeNum();}}
	void WriteArray(long long *array,int l,int r,char s[2]=" \n"){REP(i,l,r){printf("%lld%c",array[i],s[i==r]);}}
	void WriteArray(long long *array,int n,char s[2]=" \n"){REP(i,1,n){printf("%lld%c",array[i],s[i==n]);}}
	void MakeArray(int *array,int l,int r,int num_l,int num_r){REP(i,l,r){array[i]=Random(num_l,num_r);}}
	void MakeArray(int *array,int n,int num_l,int num_r){REP(i,1,n){array[i]=Random(num_l,num_r);}}
	void MakeArray(int *array,int l,int r,int(*MakeNum)()){REP(i,l,r){array[i]=MakeNum();}}
	void MakeArray(int *array,int n,int(*MakeNum)()){REP(i,1,n){array[i]=MakeNum();}}
	void WriteArray(int *array,int l,int r,char s[2]=" \n"){REP(i,l,r){printf("%lld%c",array[i],s[i==r]);}}
	void WriteArray(int *array,int n,char s[2]=" \n"){REP(i,1,n){printf("%lld%c",array[i],s[i==n]);}}
	void MakeArray(int *array,int n){REP(i,1,n){array[i]=i;}std::random_shuffle(array+1,array+1+n);}
	void MakeString(char *s,int l,int r,char *t){int lent=strlen(t);REP(i,l,r){s[i]=t[Random(lent)];}}
	void MakeString(char *s,int len,char *t){int lent=strlen(t);REP(i,0,len-1){s[i]=t[Random(lent)];}}
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
	void MakeRange(int &l,int &r,int range_l,int range_r)
	{
		int len=range_r-range_l+1;
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
	std::vector<int>sum;
	void MakeTree(Graph &a,int n,int root=1,bool link=0,int opt=0,int k=2)
	{
		a=Graph(n,link);
		if(n<2)
		{
			return;
		}
		if(opt==0)
		{
			f.clear();
			REP(i,1,n)
			{
				f.push_back(i);
			}
			std::random_shuffle(f.begin(),f.end());
			REP(i,1,n-1)
			{
				if(f[i]==root)
				{
					std::swap(f[i],f[0]);
					break;
				}
			}
			REP(i,1,n-1)
			{
				int father=f[Random(0,i-1)];
				a.AddEdge(father,f[i]);
			}
			f.clear();
		}
		if(opt==1)
		{
			f.clear();
			REP(i,1,n)
			{
				f.push_back(i);
			}
			std::random_shuffle(f.begin(),f.end());
			REP(i,1,n-1)
			{
				if(f[i]==root)
				{
					std::swap(f[i],f[0]);
					break;
				}
			}
			REP(i,1,n-1)
			{
				a.AddEdge(f[i-1],f[i]);
			}
			f.clear();
		}
		if(opt==2)
		{
			REP(i,1,n)
			{
				if(i^root)
				{
					a.AddEdge(root,i);
				}
			}
		}
		if(opt==3)
		{
			f.clear();
			sum.clear();
			REP(i,1,n)
			{
				f.push_back(i);
				sum.push_back(0);
			}
			std::random_shuffle(f.begin(),f.end());
			REP(i,1,n-1)
			{
				if(f[i]==root)
				{
					std::swap(f[i],f[0]);
					break;
				}
			}
			REP(i,1,n-1)
			{
				int father=f[Random(0,i-1)];
				while(sum[father-1]==k)
				{
					father=f[Random(0,i-1)];
				}
				sum[father-1]++;
				a.AddEdge(father,f[i]);
			}
			f.clear();
			sum.clear();
		}
		if(opt==4)
		{
			f.clear();
			REP(i,0,n)
			{
				f.push_back(i);
			}
			std::swap(f[1],f[root]);
			std::random_shuffle(f.begin()+2,f.end());
			REP(i,2,n)
			{
				a.AddEdge(f[i/2],f[i]);
			}
			f.clear();
		}
	}
	struct Hash_Pair
	{
	    template<class T1,class T2>
	    size_t operator()(const std::pair<T1,T2>&p)const
	    {
	        auto hash1=std::hash<T1>{}(p.first);
	        auto hash2=std::hash<T2>{}(p.second);
	        return hash1^hash2;
	    }
	};
	std::unordered_map<std::pair<int,int>,bool,Hash_Pair>Hash;
	void MakeGraph(Graph &gra,int n,int m,bool connect=0,bool link=0,int opt=0)
	{
		gra=Graph(n,link);
		if(n<2)
		{
			return;
		}
		if(opt==0)
		{
			if(link)
			{
				if(connect)
				{
					if(m<n-1)
					{
						return;
					}
					Hash.clear();
					MakeTree(gra,n,Random(1,n),1);
					m-=n-1;
					REP(i,1,n)
					{
						FOR(gra,i)
						{
							Hash[std::make_pair(i,to)]=
							Hash[std::make_pair(to,i)]=1;
						}
					}
					REP(i,1,m)
					{
						int a=Random(1,n),b=Random(1,n);
						while(a==b)
						{
							b=Random(1,n);
						}
						while(Hash[std::make_pair(a,b)])
						{
							a=Random(1,n);
							b=Random(1,n);
							while(a==b)
							{
								b=Random(1,n);
							}
						}
						Hash[std::make_pair(a,b)]=
						Hash[std::make_pair(b,a)]=1;
						gra.AddEdge(a,b);
					}
					Hash.clear();
				}
				else
				{
					Hash.clear();
					REP(i,1,m)
					{
						int a=Random(1,n),b=Random(1,n);
						while(a==b)
						{
							b=Random(1,n);
						}
						while(Hash[std::make_pair(a,b)])
						{
							a=Random(1,n);
							b=Random(1,n);
							while(a==b)
							{
								b=Random(1,n);
							}
						}
						Hash[std::make_pair(a,b)]=
						Hash[std::make_pair(b,a)]=1;
						gra.AddEdge(a,b);
					}
					Hash.clear();
				}
			}
			else
			{
				if(connect)
				{
					if(m<n)
					{
						return;
					}
					Hash.clear();
					REP(i,1,n)
					{
						f.push_back(i);
					}
					random_shuffle(f.begin(),f.end());
					REP(i,0,n-1)
					{
						gra.AddEdge(f[i],f[(i+1)%n]);
						Hash[std::make_pair(f[i],f[(i+1)%n])]=1;
					}
					m-=n;
					REP(i,1,m)
					{
						int a=Random(1,n),b=Random(1,n);
						while(a==b)
						{
							b=Random(1,n);
						}
						while(Hash[std::make_pair(a,b)])
						{
							a=Random(1,n);
							b=Random(1,n);
							while(a==b)
							{
								b=Random(1,n);
							}
						}
						Hash[std::make_pair(a,b)]=1;
						gra.AddEdge(a,b);
					}
					Hash.clear();
				}
				else
				{
					Hash.clear();
					REP(i,1,m)
					{
						int a=Random(1,n),b=Random(1,n);
						while(a==b)
						{
							b=Random(1,n);
						}
						while(Hash[std::make_pair(a,b)])
						{
							a=Random(1,n);
							b=Random(1,n);
							while(a==b)
							{
								b=Random(1,n);
							}
						}
						Hash[std::make_pair(a,b)]=1;
						gra.AddEdge(a,b);
					}
					Hash.clear();
				}
			}
		}
	}
	std::vector<std::pair<int,int> >edge;
	void WriteGraph(Graph &a)
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
				if(a.link)
				{
					if(i<to)
					{
						edge.push_back(std::make_pair(i,to));
					}
				}
				else
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
				if(a.link)
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
				else
				{
					printf("%d %d\n",edge[i].first,edge[i].second);
				}
			}
		}
	}
}
