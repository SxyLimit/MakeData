#include<bits/stdc++.h>
#include<windows.h>
#define REP(i,first,last) for(int i=first;i<=last;++i)
#define DOW(i,first,last) for(int i=first;i>=last;--i)

#define RAND_INT Random(-1e9,1e9)
#define RAND_LONG_LONG Random(-5e17,5e17)
#define _RAND_INT Random(0,1e9)
#define _RAND_LONG_LONG Random(0,1e18)
#define _abc_ 'a','z'
#define _ABC_ 'A','Z'
#define NUM '0','9'
#define CHAR 32,126
namespace MD
{
	unsigned long long seed;
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
	char RandomChar(char s[])
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
	void MakeArray(int *array,int l,int r,int num_l,int num_r)
	{
		REP(i,l,r)
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
	void MakeArray(int *array,int l,int r,int(*MakeNum)())
	{
		REP(i,l,r)
		{
			array[i]=MakeNum();
		}
	}
	void MakeArray(int *array,int n)
	{
		memset(array,0,sizeof(array));
		REP(i,1,n)
		{
			array[i]=i;
		}
		std::random_shuffle(array+1,array+1+n);
	}
	void MakeString(char *s,int l,int r,char t[])
	{
		int len=strlen(t);
		REP(i,l,r)
		{
			s[i]=t[Random(len)];
		}
	}
	void MakeRange(int &l,int &r,int range_l,int range_r)
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
	void MakeTree(int *father,int n,int root=1,int opt=0)
	{
		memset(father,0,sizeof(father));
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
			father[root]=0;
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
	}
	void WriteArray(long long array[],int l,int r,char s[2]=" \n")
	{
		REP(i,l,r)
		{
			printf("%lld%c",array[i],s[i==r]);
		}
	}
	void WriteArray(int array[],int l,int r,char s[2]=" \n")
	{
		REP(i,l,r)
		{
			printf("%d%c",array[i],s[i==r]);
		}
	}
	struct Tree
	{
		int father,son;
	}tree[10000005];
	void WriteTree(int father[],int n)
	{
		REP(i,1,n)
		{
			tree[i].father=father[i];
			tree[i].son=i;
		}
		std::random_shuffle(tree+1,tree+1+n);
		REP(i,1,n)
		{
			if(tree[i].father)
			{
				if(Random(2))
				{
					printf("%d %d\n",tree[i].father,tree[i].son);
				}
				else
				{
					printf("%d %d\n",tree[i].son,tree[i].father);
				}
			}
		}
	}
}
