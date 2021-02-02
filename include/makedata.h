#include<bits/stdc++.h>
namespace MD
{
	unsigned long long seed=233;
	inline void Srand(unsigned long long a=time(NULL))
	{
		seed=a;
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
	}
}
namespace IO
{
	int double_len(6);
	bool spacebar_can_see(1);
	const char NUMBER_TO_CHAR[36]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
	const int CHAR_TO_NUMBER[128]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0,0,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,0,0,0,0,0};
	template<class T>class Number
	{
	public:
		unsigned int len;
		int hex;
		T number;
		inline Number(const T number=0,const int hex=10,const int len=0):number(number),hex(hex),len(len)
		{

		}
		inline operator T()const
		{
			return number;
		}
		inline Number<T>& operator =(const T &a)
		{
			number=a;
			return *this;
		}
	};
	inline bool CanSee(const char ch)
	{
		return spacebar_can_see?(31<ch&&ch<127):(32<ch&&ch<127);
	}
	inline bool IsNumber(const char ch)
	{
		return (47<ch&&ch<58);
	}
	inline bool IsNumber_(const int hex,const char ch)
	{
		return (47<ch&&ch<48+hex)||(64<ch&&ch<55+hex)||(96<ch&&ch<87+hex);
	}
	const int IN_BUF=1<<23,OUT_BUF=1<<23;
	char buf[IN_BUF],*ps=buf,*pt=buf,pbuf[OUT_BUF],*pp=pbuf;
	inline char GetChar()
	{
		return getchar();
		if(ps==pt)
		{
			ps=buf;
			pt=buf+fread(buf,1,IN_BUF,stdin);
		}
		return ps==pt?EOF:*ps++;
	}
	inline void PutChar(const char ch)
	{
		putchar(ch);return;
		if(pp==pbuf+OUT_BUF)
		{
			fwrite(pbuf,1,OUT_BUF,stdout);
			pp=pbuf;
		}
		*pp++=ch;
	}
	char read_ch(10);
	template<class T>
	inline T ReadInt()
	{
		register T x(0);
		register bool f(1);
		while(!IsNumber(read_ch)&&(~read_ch))
		{
			if(read_ch==45)
			{
				f=0;
			}
			read_ch=GetChar();
		}
		while(IsNumber(read_ch)&&(~read_ch))
		{
			x=(x<<1)+(x<<3)+(read_ch^48);
			read_ch=GetChar();
		}
		return f?x:-x;
	}
	template<class T>
	inline T ReadUInt()
	{
		register T x(0);
		while(!IsNumber(read_ch)&&(~read_ch))
		{
			read_ch=GetChar();
		}
		while(IsNumber(read_ch)&&(~read_ch))
		{
			x=(x<<1)+(x<<3)+(read_ch^48);
			read_ch=GetChar();
		}
		return x;
	}
	template<class T>
	inline T ReadKInt(const int hex)
	{
		register T x(0);
		register bool f(1);
		while(!IsNumber_(hex,read_ch)&&(~read_ch))
		{
			if(read_ch==45)
			{
				f=0;
			}
			read_ch=GetChar();
		}
		while(IsNumber_(hex,read_ch)&&(~read_ch))
		{
			x=x*hex+CHAR_TO_NUMBER[read_ch];
			read_ch=GetChar();
		}
		return f?x:-x;
	}
	template<class T>
	inline T ReadUKInt(const int hex)
	{
		register T x(0);
		while(!IsNumber_(hex,read_ch)&&(~read_ch))
		{
			read_ch=GetChar();
		}
		while(IsNumber_(hex,read_ch)&&(~read_ch))
		{
			x=x*hex+CHAR_TO_NUMBER[read_ch];
			read_ch=GetChar();
		}
		return x;
	}
	inline double ReadDouble()
	{
		register long long int_num(ReadInt<long long>());
		if(read_ch==46)
		{
			register double pow10(1.0),result(0);
			read_ch=GetChar();
			while(IsNumber(read_ch)&&(~read_ch))
			{
				pow10/=10.0;
				result+=pow10*(read_ch^48);
				read_ch=GetChar();
			}
			return int_num+(int_num<0?-result:result);
		}
		else
		{
			return (double)int_num;
		}
	}
	inline void ReadT(int &x)
	{
		x=ReadInt<int>();
	}
	inline void ReadT(long long &x)
	{
		x=ReadInt<long long>();
	}
	inline void ReadT(bool &x)
	{
		x=ReadUInt<bool>();
	}
	inline void ReadT(unsigned int &x)
	{
		x=ReadUInt<unsigned int>();
	}
	inline void ReadT(unsigned long long &x)
	{
		x=ReadUInt<unsigned long long>();
	}
	inline void ReadT(double &x)
	{
		x=ReadDouble();
	}
	inline void ReadT(char &ch)
	{
		for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar());
		ch=read_ch;
		read_ch=10;
	}
	inline void ReadT(Number<int> &x)
	{
		x.number=ReadKInt<int>(x.hex);
	}
	inline void ReadT(Number<long long> &x)
	{
		x.number=ReadKInt<long long>(x.hex);
	}
	inline void ReadT(Number<unsigned int> &x)
	{
		x.number=ReadUKInt<unsigned int>(x.hex);
	}
	inline void ReadT(Number<unsigned long long> &x)
	{
		x.number=ReadUKInt<unsigned long long>(x.hex);
	}
	inline void ReadT(char *s)
	{
		register int len(0);
		for(;!CanSee(read_ch)&&(~read_ch);read_ch=GetChar());
		for(;CanSee(read_ch)&&(~read_ch);read_ch=GetChar())
		{
			s[len++]=read_ch;
		}
		s[len]=0;
		read_ch=10;
	}
	template<class T>
	inline void Read(T &t)
	{
		ReadT(t);
	}
	template<class T,class ...Args>
	void Read(T &t,Args &...args)
	{
		ReadT(t);
		Read(args...);
	}
	template<class T>
	inline void WriteUInt(T x)
	{
		static char out_number[25];
		static int cnt;
		out_number[cnt=1]=x%10^48;
		while(x/=10)
		{
			out_number[++cnt]=x%10^48;
		}
		while(cnt)
		{
			PutChar(out_number[cnt--]);
		}
	}
	template<class T>
	inline void WriteInt(const T x)
	{
		if(x<0)
		{
			PutChar(45);
			WriteUInt(-x);
			return;
		}
		WriteUInt(x);
	}
	template<class T>
	inline void WriteUKInt(T x,const int hex,int len)
	{
		static char out_number[25];
		static int cnt;
		out_number[cnt=1]=NUMBER_TO_CHAR[x%hex];
		while(x/=hex)
		{
			out_number[++cnt]=NUMBER_TO_CHAR[x%hex];
		}
		len-=cnt;
		while(0<len--)
		{
			PutChar(48);
		}
		while(cnt)
		{
			PutChar(out_number[cnt--]);
		}
	}
	template<class T>
	inline void WriteKInt(const T x,const int hex,const int len)
	{
		if(x<0)
		{
			PutChar(45);
			WriteUKInt(-x,hex,len-1);
			return;
		}
		WriteUKInt(x,hex,len);
	}
	inline void WriteDouble(double x,int len)
	{
		if(x<0)
		{
			PutChar(45);
			x=-x;
		}
		WriteUInt<unsigned long long>((unsigned long long)x);
		if(len)
		{
			x-=(int)x;
			PutChar(46);
			while(len--)
			{
				x*=10;
				if(!(unsigned long long)x)
				{
					PutChar(48);
				}
			}
			if((unsigned long long)x)
			{
				WriteUInt<unsigned long long>((unsigned long long)x);
			}
		}
	}
	inline void WriteT(const int x)
	{
		WriteInt<int>(x);
	}
	inline void WriteT(const long long x)
	{
		WriteInt<long long>(x);
	}
	inline void WriteT(const bool x)
	{
		PutChar(x|48);
	}
	inline void WriteT(const unsigned int x)
	{
		WriteUInt<unsigned int>(x);
	}
	inline void WriteT(const unsigned long long x)
	{
		WriteUInt<unsigned long long>(x);
	}
	inline void WriteT(const double x)
	{
		WriteDouble(x,double_len);
	}
	inline void WriteT(const char *s)
	{
		while(*s)
		{
			PutChar(*s++);
		}
	}
	inline void WriteT(const char x)
	{
		PutChar(x);
	}
	inline void WriteT(const Number<int> x)
	{
		WriteKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<long long> x)
	{
		WriteKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<unsigned int> x)
	{
		WriteUKInt(x.number,x.hex,x.len);
	}
	inline void WriteT(const Number<unsigned long long> x)
	{
		WriteUKInt(x.number,x.hex,x.len);
	}
	template<class T>
	inline void Write(const T t)
	{
		WriteT(t);
	}
	template<class T,class ...Args>
	void Write(const T t,const Args ...args)
	{
		WriteT(t);
		Write(args...);
	}
	inline void Writeln()
	{
		PutChar(10);
	}
	template<class T>
	inline void Writeln(const T t)
	{
		WriteT(t);
		PutChar(10);
	}
	template<class ...Args>
	inline void Writeln(const Args ...args)
	{
		Write(args...);
		PutChar(10);
	}
	template<class ...Args>
	inline void WriteExit(const Args ...args)
	{
		Write(args...);
		PutChar(10);
		exit(0);
	}
}
template<typename T>
inline T Max(const T a,const T b)
{
	return a<b?b:a;
}
template<typename T,typename ...Args>
T Max(const T a,const Args ...args)
{
	return Max(a,Max(args...));
}
template<typename T>
inline T Min(const T a,const T b)
{
	return a<b?a:b;
}
template<typename T,typename ...Args>
T Min(const T a,const Args ...args)
{
	return Min(a,Min(args...));
}
template<typename T>
inline void Swap(T &a,T &b)
{
	register T temp=a;
	a=b;
	b=temp;
}
#include<windows.h>
#define REP(i,first,last) for(int i=first;i<=last;++i)
#define DOW(i,first,last) for(int i=first;last<=i;--i)
#define RAND_INT Random(-(int)1e9,(int)1e9)
#define RAND_LL Random(-(long long)5e17,(long long)5e17)
#define _RAND_INT Random(0,(unsigned int)1e9)
#define _RAND_LL Random(0,(unsigned long long)1e18)
#define _abc_ 'a','z'
#define _ABC_ 'A','Z'
#define NUM '0','9'
#define CHAR 32,126
std::vector<int>null_vector;
std::vector<std::pair<int,int> >edge;
class Graph
{
private:
public:
	std::vector<std::vector<int> >out_point;
	bool link;
	inline Graph(int n=0,bool l=0)
	{
		link=l;
		REP(i,0,n)
		{
			out_point.push_back(null_vector);
		}
	}
	inline void AddEdge(int form,int to)
	{
		out_point[form].push_back(to);
		if(link)
		{
			out_point[to].push_back(form);
		}
	}
	inline void Clean()
	{
		out_point.clear();
	}
	#define FOR(edge,now) for(int edge_i=0,to=edge.out_point[now].size()?edge.out_point[now][0]:0;edge_i<edge.out_point[now].size();edge_i++,to=edge.out_point[now][edge_i])
	inline void Write()
	{
		if(!out_point.size())
		{
			return;
		}
		edge.clear();
		REP(i,1,out_point.size()-1)
		{
			for(int edge_i=0,to=out_point[i].size()?out_point[i][0]:0;edge_i<out_point[i].size();edge_i++,to=out_point[i][edge_i])
			{
				if(link)
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
				if(link)
				{
					if(rand()&1)
					{
						IO::Writeln(edge[i].first,' ',edge[i].second);
					}
					else
					{
						IO::Writeln(edge[i].second,' ',edge[i].first);
					}
				}
				else
				{
					IO::Writeln(edge[i].first,' ',edge[i].second);
				}
			}
		}
	}
	template<typename T>
	inline void Write(T(*MakeValue)())
	{
		if(!out_point.size())
		{
			return;
		}
		edge.clear();
		REP(i,1,out_point.size()-1)
		{
			for(int edge_i=0,to=out_point[i].size()?out_point[i][0]:0;edge_i<out_point[i].size();edge_i++,to=out_point[i][edge_i])
			{
				if(link)
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
				if(link)
				{
					if(rand()&1)
					{
						IO::Writeln(edge[i].first,' ',edge[i].second,' ',MakeValue());
					}
					else
					{
						IO::Writeln(edge[i].second,' ',edge[i].first,' ',MakeValue());
					}
				}
				else
				{
					IO::Writeln(edge[i].first,' ',edge[i].second);
				}
			}
		}
	}
};
template<class T=int>class GraphWithValue
{

};
namespace MD
{
	inline unsigned long long RandomNumber(unsigned long long a)
	{
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
		return seed%a;
	}
	template<typename T>
	inline T Random(T f,T e)
	{
		return f+RandomNumber((unsigned long long)(e-f+1));
	}
	template<typename T>
	inline T Random(T a)
	{
		return RandomNumber((unsigned long long)a);
	}
	inline char RandomChar(char s[],int len=-1)
	{
		return s[RandomNumber(~len?len:strlen(s))];
	}
	template<typename T>
	inline void MakeRange(T &l,T &r,T range_l,T range_r)
	{
		T len=range_r-range_l+1;
		if(Random((T)1,len*(len+1))<=len-1)
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
	inline void MakeTree(Graph &a,int n,int root=1,bool link=0,int opt=0,int k=2)
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
				int father=f[Random(i)];
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
				int father=f[Random(i)];
				while(sum[father-1]==k)
				{
					father=f[Random(i)];
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
	inline void MakeTree(Graph &a,int *father_array,int n,int root=1,bool link=0,int opt=0,int k=2)
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
				int father=f[Random(i)];
				a.AddEdge(father,f[i]);
				father_array[f[i]]=father;
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
				father_array[f[i]]=f[i-1];
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
					father_array[i]=root;
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
				int father=f[Random(i)];
				while(sum[father-1]==k)
				{
					father=f[Random(i)];
				}
				sum[father-1]++;
				a.AddEdge(father,f[i]);
				father_array[f[i]]=father;
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
				father_array[f[i]]=f[i/2];
			}
			f.clear();
		}
	}
	struct Hash_Pair
	{
		template<class T1,class T2>
		inline size_t operator()(const std::pair<T1,T2>&p)const
		{
			auto hash1=std::hash<T1>{}(p.first);
			auto hash2=std::hash<T2>{}(p.second);
			return hash1^hash2;
		}
	};
	std::unordered_map<std::pair<int,int>,bool,Hash_Pair>Hash;
	inline void MakeGraph(Graph &gra,int n,int m,bool connect=0,bool link=0,int opt=0)
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
}
