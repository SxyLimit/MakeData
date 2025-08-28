#include<bits/stdc++.h>
#include<chrono>
#define RWRI(i,f,l) for(int i(f);i<=l;Write(i==l?'\n':' '),++i)
#define ULL unsigned long long
#define LL long long
const int INF=1000000000;
const LL INFL=1000000000000000000LL;
namespace MD
{
	ULL seed=233;
	inline void Srand(const ULL a=std::chrono::high_resolution_clock::now().time_since_epoch().count())
	{
		seed=a;
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
	}
	class ToDo
	{
	public:
		inline ToDo()
		{
			Srand();
			// srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		}
	}todo;
	inline ULL Random()
	{
		seed^=seed<<13;
		seed^=seed>>7;
		seed^=seed<<17;
		return seed;
	}
	template <typename RandomIt>
	inline void RandomShuffle(RandomIt begin, RandomIt end)
	{
		if(begin>=end)
		{
			return;
		}
		auto length=std::distance(begin, end);
		for(std::size_t i=1;i<length;++i)
		{
			std::size_t rand_index=Random()%i;
			std::iter_swap(begin+i,begin+rand_index);
		}
	}
	
	template<typename T>
	inline T Random(const T f,const T e)
	{
		if(e<f)
		{
			std::cerr<<"Random Error "<<f<<" > "<<e<<std::endl;
			exit(0);
		}
		return f+Random()%(e-f+1);
	}
	template<typename T>
	inline T Random(const T a)
	{
		return Random()%a;
	}
	inline char RandomChar(const char s[],const int len=-1)
	{
		return s[Random()%(~len?len:strlen(s))];
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
	class HashPair
	{
		public:
		template<class T1,class T2>
		inline size_t operator()(const std::pair<T1,T2>&p)const
		{
			auto hash1=std::hash<T1>{}(p.first);
			auto hash2=std::hash<T2>{}(p.second);
			return hash1^hash2;
		}
	};
	template<int L,int R>class RandomC
	{
		public:
		inline int operator ()()const
		{
			return Random<int>(L,R);
		}
	};
	template<LL L,LL R>class RandomLLC
	{
		public:
		inline LL operator ()()const
		{
			return Random<LL>(L,R);
		}
	};
	template<class GenerateFunction>
	inline void GenerateArray(int *arr,const int n,GenerateFunction MakeValue)
	{
		for(int i=1;i<=n;++i)
		{
			arr[i]=MakeValue();
		}
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
		T x(0);
		bool f(1);
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
		T x(0);
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
		T x(0);
		bool f(1);
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
		T x(0);
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
		long long int_num(ReadInt<long long>());
		if(read_ch==46)
		{
			double pow10(1.0),result(0);
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
	inline void ReadT(ULL &x)
	{
		x=ReadUInt<ULL>();
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
	inline void ReadT(Number<ULL> &x)
	{
		x.number=ReadUKInt<ULL>(x.hex);
	}
	inline void ReadT(char *s)
	{
		int len(0);
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
		WriteUInt<ULL>((ULL)x);
		if(len)
		{
			x-=(int)x;
			PutChar(46);
			while(len--)
			{
				x*=10;
				if(!(ULL)x)
				{
					PutChar(48);
				}
			}
			if((ULL)x)
			{
				WriteUInt<ULL>((ULL)x);
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
	inline void WriteT(const ULL x)
	{
		WriteUInt<ULL>(x);
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
	inline void WriteT(const Number<ULL> x)
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
	template<class T>
	inline void WriteArray(const T *arr,const int n,const char ch=' ')
	{
		for(int i=1;i<=n;++i)
		{
			Write(arr[i]);
			if(i<n)
			{
				Write(ch);
			}
		}
		Writeln();
	}
	template<class GenerateFunction>
	inline void WriteArrayByFunction(const int n,GenerateFunction MakeValue,const char ch=' ')
	{
		for(int i=1;i<=n;++i)
		{
			Write(MakeValue());
			if(i<n)
			{
				Write(ch);
			}
		}
		Writeln();
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
	T temp=a;
	a=b;
	b=temp;
}
template<typename T>
inline T Abs(const T a)
{
	return a<0?-a:a;
}
inline std::pair<int,int> UnorderedPair(const int a,const int b)
{
	return std::make_pair(Min(a,b),Max(a,b));
}
inline std::pair<int,int> EdgePair(const int a,const int b,const int link=1)
{
	if(link)
	{
		return UnorderedPair(a,b);
	}
	else
	{
		return std::make_pair(a,b);
	}
}
inline long long EdgeNumber(const int a,const bool link)
{
	if(link)
	{
		return 1ll*a*(a-1)/2;
	}
	else
	{
		return 1ll*a*(a-1);
	}
}
inline long long EdgeNumber(const int a,const int b,const bool link)
{
	if(link)
	{
		return 1ll*a*b;
	}
	else
	{
		return 1ll*a*b*2;
	}
}
#define REP(i,first,last) for(int i=first;i<=last;++i)
#define DOW(i,first,last) for(int i=first;last<=i;--i)
#define RAND_INT Random(-(int)INF,(int)INF)
#define RAND_LL Random(-(long long)INFL/2,(long long)INFL/2)
#define _RAND_INT Random(0LL,(unsigned int)INF)
#define _RAND_LL Random(0LL,(ULL)INFL)
#define _abc_ 'a','z'
#define _ABC_ 'A','Z'
#define NUM '0','9'
#define CHAR 32,126
class Graph
{
private:

public:
	std::vector<std::vector<int> >out_point;
	bool link;
	inline Graph()
	{
		link=0;
	}
	inline Graph(int n,bool l)
	{
		link=l;
		REP(i,0,n)
		{
			out_point.push_back(std::vector<int>());
		}
	}
	inline bool IsSameEdge()const
	{
		std::set<std::pair<int,int>>edge;
		for(int i=1;i<out_point.size();++i)
		{
			for(auto to:out_point[i])
			{
				auto e=std::make_pair(i,to);
				if(edge.find(e)!=edge.end())
				{
					std::cerr<<e.first<<" "<<e.second<<" Same Edge"<<std::endl;
					return 1;
				}
				edge.insert(e);
			}
		}
		return 0;
	}
	inline int Size()const
	{
		return out_point.size()-1;
	}
	inline int Edge()const
	{
		int res=0;
		for(int i=1;i<out_point.size();++i)
		{
			res+=out_point[i].size();
		}
		if(link)
		{
			res>>=1;
		}
		return res;
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
	inline void ReShuffer(const int root=0)
	{
		std::vector<int>id(out_point.size());
		for(int i=0;i<id.size();i++)
		{
			id[i]=i;
		}
		MD::RandomShuffle(id.begin()+1,id.end());
		if(root)
		{
			for(int i=1;i<id.size();i++)
			{
				if(id[i]==root)
				{
					Swap(id[i],id[root]);
					break;
				}
			}
		}
		std::vector<std::vector<int> >new_out_point(out_point.size());
		for(int i=1;i<id.size();i++)
		{
			for(auto to:out_point[i])
			{
				new_out_point[id[i]].push_back(id[to]);
			}
		}
		new_out_point.swap(out_point);
		new_out_point.clear();
	}
	inline void ErrorWrite()
	{
		std::cerr<<"Graph Error"<<std::endl;
		std::cerr<<"Node: "<<Size()<<std::endl;
		std::cerr<<"Edge: "<<Edge()<<std::endl;
		for(int i=1;i<out_point.size();++i)
		{
			std::cerr<<i<<": ";
			for(auto to:out_point[i])
			{
				std::cerr<<to<<' ';
			}
			std::cerr<<std::endl;
		}
	}
	inline void Write()
	{
		if(!out_point.size())
		{
			return;
		}
		std::vector<std::pair<int,int> >edge;
		edge.clear();
		for(int i=1;i<out_point.size();++i)
		{
			for(auto to:out_point[i])
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
		MD::RandomShuffle(edge.begin(),edge.end());
		if(edge.size())
		{
			for(auto e:edge)
			{
				if(link)
				{
					if(MD::Random()&1)
					{
						IO::Writeln(e.first,' ',e.second);
					}
					else
					{
						IO::Writeln(e.second,' ',e.first);
					}
				}
				else
				{
					IO::Writeln(e.first,' ',e.second);
				}
			}
		}
	}
	template<class GenerateFunction>
	inline void Write(GenerateFunction MakeValue)
	{
		if(!out_point.size())
		{
			return;
		}
		std::vector<std::pair<int,int> >edge;
		edge.clear();
		for(int i=1;i<out_point.size();++i)
		{
			for(auto to:out_point[i])
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
		MD::RandomShuffle(edge.begin(),edge.end());
		if(edge.size())
		{
			for(auto e:edge)
			{
				if(link)
				{
					if(MD::Random()&1)
					{
						IO::Writeln(e.first,' ',e.second,' ',MakeValue());
					}
					else
					{
						IO::Writeln(e.second,' ',e.first,' ',MakeValue());
					}
				}
				else
				{
					IO::Writeln(e.first,' ',e.second,' ',MakeValue());
				}
			}
		}
	}
	inline void Merge(const Graph &a,int add_edge=0,int l=-1,int r=-1)
	{
		int nown=out_point.size()-1;
		for(int i=1;i<a.out_point.size();++i)
		{
			out_point.push_back(std::vector<int>());
			for(auto to:a.out_point[i])
			{
				out_point.back().push_back(to+nown);
			}
		}
		if(add_edge==0)
		{
			return;
		}
		if(l==-1)
		{
			l=1;
		}
		if(r==-1)
		{
			r=a.Size();
		}
		long long edge_num=1ll*nown*(r-l+1);
		if(edge_num<add_edge)
		{
			std::cerr<<"Graph.Merge Error "<<edge_num<<" < "<<add_edge<<std::endl;
			exit(0);
		}
		if(add_edge>edge_num/2)
		{
			std::vector<std::pair<int,int>>edge;
			for(int i=1;i<=nown;++i)
			{
				for(int j=l;j<=r;++j)
				{
					edge.push_back(std::make_pair(i,j+nown));
				}
			}
			MD::RandomShuffle(edge.begin(),edge.end());
			for(int i=0;i<add_edge;++i)
			{
				out_point[edge[i].first].push_back(edge[i].second);
				if(link)
				{
					out_point[edge[i].second].push_back(edge[i].first);
				}
			}
		}
		else
		{
			std::unordered_set<std::pair<int,int>,MD::HashPair>hash;
			for(int i=0;i<add_edge;++i)
			{
				int u=MD::Random(1,nown);
				int v=MD::Random(l,r)+nown;
				while(hash.find(std::make_pair(u,v))!=hash.end())
				{
					u=MD::Random(1,nown);
					v=MD::Random(l,r)+nown;
				}
				out_point[u].push_back(v);
				hash.insert(std::make_pair(u,v));
				if(link)
				{
					out_point[v].push_back(u);
					hash.insert(std::make_pair(v,u));
				}
			}
		}
	}
};
inline long long EdgeNumber(const Graph &g)
{
	return EdgeNumber(g.Size(),g.link);
}
namespace MD
{
	namespace MillerRabin
	{
		const int PRIME[168]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
		inline LL Pow(LL a,LL b,const LL mod)
		{
			LL result=1;
			while(b)
			{
				if(b&1)
				{
					result=(__int128)result*a%mod;
				}
				a=(__int128)a*a%mod;
				b>>=1;
			}
			return result;
		}
		const LL CHECK_NUMBER[7]={2,325,9375,28178,450775,9780504,1795265022};
		inline bool IsPrime(const LL p)
		{
			if(p<3)
			{
				return p==2;
			}
			if(!(p&1))
			{
				return 0;
			}
			LL d(p-1),r(-1);
			while(!(d&1))
			{
				d>>=1;
				++r;
			}
			REP(i,0,6)
			{
				LL v=Pow(CHECK_NUMBER[i],d,p);
				if(v<2||v==p-1)
				{
					continue;
				}
				REP(i,0,r)
				{
					v=(__int128)v*v%p;
					if(v==p-1)
					{
						v=1;
						break;
					}
					if(v==1)
					{
						return 0;
					}
				}
				if(v^1)
				{
					return 0;
				}
			}
			return 1;
		}
	}
	template<typename T>
	inline T RandomPrime(const T a)
	{
		T result=Random((T)2,a);
		while(MillerRabin::IsPrime(result)==0)
		{
			result=Random((T)2,a);
		}
		return result;
	}
	inline void RandomPermutation(int *arr,const int n)
	{
		for(int i=1;i<=n;++i)
		{
			arr[i]=i;
		}
		RandomShuffle(arr+1,arr+n+1);
	}
	inline void RandomSameElement(int *arr,const int n,int round=-1)
	{
		if(round==-1)
		{
			round=Max(n/10,1);
		}
		REP(i,1,round)
		{
			arr[Random(1,n)]=arr[Random(1,n)];
		}
	}
	const int TREE_KIND=6;
	inline Graph MakeSimpleTree(const int n,const int kind,const int link=1)
	{
		Graph g(n,link);
		if(n==1)
		{
			return g;
		}
		if(n==2)
		{
			g.AddEdge(1,2);
			return g;
		}
		if(kind==0)
		{
			REP(i,2,n)
			{
				int father=Random(1,i-1);
				g.AddEdge(father,i);
			}
			return g;
		}
		if(kind==1)
		{
			REP(i,2,n)
			{
				int father=i-1;
				g.AddEdge(father,i);
			}
			return g;
		}
		if(kind==2)
		{
			REP(i,2,n)
			{
				int father=1;
				g.AddEdge(father,i);
			}
			return g;
		}
		if(kind==3)
		{
			REP(i,2,n)
			{
				int father=i>>1;
				g.AddEdge(father,i);
			}
			return g;
		}
		if(kind==4)
		{
			int p=Random(3,Min(10,n));
			REP(i,2,p)
			{
				int father=1;
				g.AddEdge(father,i);
			}
			REP(i,p+1,n)
			{
				int father=Random(2,p);
				g.AddEdge(father,i);
			}
		}
		if(kind==5)
		{
			int p=Random(n/3,n/3*2);
			p=Max(p,2);
			REP(i,2,p)
			{
				int father=1;
				g.AddEdge(father,i);
			}
			REP(i,p+1,n)
			{
				int father=Random(2,p);
				g.AddEdge(father,i);
			}
		}
		if(kind==6)
		{
			for(int i=2;i<=n;++i)
			{
				int father=i-1;
				if(i&1)
				{
					father=i-2;
				}
				g.AddEdge(father,i);
			}
		}
		return g;
	}
	inline Graph MixTree(const int n,const int link=1,const int div=3)
	{
		Graph g(n,link);
		if(n==1)
		{
			return g;
		}
		if(n<15)
		{
			g=MakeSimpleTree(n/2,Random(0,TREE_KIND),link);
			if(g.IsSameEdge())
			{
				std::cerr<<"MixTree Error Same Edge"<<std::endl;
				g.ErrorWrite();
				exit(0);
			}
			Graph g1=MakeSimpleTree(n-n/2,Random(0,TREE_KIND),link);
			if(g1.IsSameEdge())
			{
				std::cerr<<"MixTree Error Same Edge 2"<<std::endl;
				exit(0);
			}
			g.Merge(g1,1,1,1);
			if(g.IsSameEdge())
			{
				std::cerr<<"MixTree Error Same Edge 3"<<std::endl;
				exit(0);
			}
			return g;
		}
		int n1=n/Max(div,3)+Random(-5,5);
		n1=Max(n1,2);
		n1=Min(n1,n-3);
		int n2=n/Max(div,3)+Random(-5,5);
		n2=Max(n2,2);
		n2=Min(n2,n-n1);
		int el=n-n1-n2;
		g=MakeSimpleTree(n1,1,link);
		g.Merge(MakeSimpleTree(n2,2,link),1,1,1);
		for(int i(0);i<30;++i)
		{
			if(el==0)
			{
				break;
			}
			int m=Random(1,Min(el,Max(el/4,5)));
			Graph g1=MakeSimpleTree(m,Random(0,TREE_KIND),link);
			g.Merge(g1,1,1,1);
			el-=m;
		}
		if(el)
		{
			Graph g1=MakeSimpleTree(el,Random(0,TREE_KIND),link);
			g.Merge(g1,1,1,1);
		}
		return g;
	}
	inline Graph GraphAddEdge(const Graph &g,int add_edge)
	{
		if(add_edge==0)
		{
			return g;
		}
		Graph res=g;
		long long edge_num=EdgeNumber(g.Size(),g.link);
		std::unordered_set<std::pair<int,int>,MD::HashPair>hash;
		for(int i=1;i<g.Size();++i)
		{
			for(auto to:g.out_point[i])
			{
				hash.insert(EdgePair(i,to,g.link));
				if(!g.link)
				{
					hash.insert(EdgePair(to,i,g.link));
				}
			}
		}
		edge_num-=g.Edge();
		if(add_edge>edge_num)
		{
			std::cerr<<"GraphAddEdge Error "<<add_edge<<" > "<<edge_num<<std::endl;
			exit(0);
		}
		if(add_edge+g.Edge()>edge_num/2)
		{
			std::vector<std::pair<int,int>>edge;
			for(int i=1;i<g.Size();++i)
			{
				for(int j=i+1;j<=g.Size();++j)
				{
					if(hash.find(EdgePair(i,j,g.link))==hash.end())
					{
						edge.push_back(EdgePair(i,j,g.link));
					}
					if(!g.link)
					{
						if(hash.find(EdgePair(j,i,g.link))==hash.end())
						{
							edge.push_back(EdgePair(j,i,g.link));
						}
					}
				}
			}
			MD::RandomShuffle(edge.begin(),edge.end());
			for(int i=0;i<add_edge;++i)
			{
				res.AddEdge(edge[i].first,edge[i].second);
			}
		}
		else
		{
			for(int i=0;i<add_edge;++i)
			{
				int u=Random(1,res.Size());
				int v=Random(1,res.Size());
				while(u==v||hash.find(EdgePair(u,v,res.link))!=hash.end())
				{
					u=Random(1,res.Size());
					v=Random(1,res.Size());
				}
				hash.insert(EdgePair(u,v,res.link));
				res.AddEdge(u,v);
			}
		}
		return res;
	}
	const int GRAPH_KIND=3;
	inline Graph MakeSimpleGraph(const int n,const int m,const int kind,const int link=1)
	{
		Graph g(n,link);
		if(m<n-1)
		{
			std::cerr<<"MakeSimpleGraph Error"<<" "<<m<<" < "<<n-1<<std::endl;
			exit(0);
		}
		if(kind==0)
		{
			return GraphAddEdge(MixTree(n,link),m-(n-1));
		}
		if(kind==1)
		{
			if(m<n)
			{
				std::cerr<<"MakeSimpleGraph Kind 1 Error"<<" "<<m<<" < "<<n<<std::endl;
				return g;
			}
			for(int i=2;i<=n;++i)
			{
				g.AddEdge(i-1,i);
			}
			g.AddEdge(n,1);
			return GraphAddEdge(g,m-n);
		}
		if(kind==2)
		{
			g=MakeSimpleTree(n,1,link);
			return GraphAddEdge(g,m-(n-1));
		}
		if(kind==3)
		{
			g=MakeSimpleTree(n,2,link);
			return GraphAddEdge(g,m-(n-1));
		}
		return g;
	}
	inline Graph MixGraphConnect(const int n,const int m,const int link=1,const int div=4)
	{
		Graph g(n,link);
		if(m<n-1)
		{
			std::cerr<<"MixGraphConnect Error"<<" "<<m<<" < "<<n-1<<std::endl;
			exit(0);
		}
		if(n<15||m<n+50)
		{
			g=MixTree(n,link);
			if(g.IsSameEdge())
			{
				std::cerr<<"MixGraphConnect Error Same Edge"<<std::endl;
				exit(0);
			}
			return GraphAddEdge(g,m-(n-1));
		}
		int n1=n/Max(div,4)+Random(-5,5);
		n1=Max(n1,3);
		n1=Min(n1,n-6);
		int n2=n/Max(div,4)+Random(-5,5);
		n2=Max(n2,3);
		n2=Min(n2,n-n1-3);
		int n3=n/Max(div,4)+Random(-5,5);
		n3=Max(n3,3);
		n3=Min(n3,n-n1-n2);
		int el=n-n1-n2-n3;
		int add1=Random(2,8);
		int add2=Random(2,8);
		int addn1=Random(2,8);
		int addn2=Random(2,8);
		int addn3=Random(2,8);
		addn1=Min((long long)addn1,EdgeNumber(n1,link)-n1);
		addn2=Min((long long)addn2,EdgeNumber(n2,link)-n2);
		addn3=Min((long long)addn3,EdgeNumber(n3,link)-n3);
		add1=Min((long long)add1,1ll*n1*n2);
		add2=Min((long long)add2,1ll*(n1+n2)*n3);
		int eledge=m-n1-n2-n3-add1-add2-addn1-addn2-addn3-el;
		g=MakeSimpleGraph(n1,n1+addn1,1,link);
		g.Merge(MakeSimpleGraph(n2,n2+addn2,2,link),add1);
		g.Merge(MakeSimpleGraph(n3,n3+addn3,3,link),add2);
		for(int i(0);i<30;++i)
		{
			if(el==0||eledge==0)
			{
				break;
			}
			int use_n=Random(1,Min(el,Max(el/4,5)));
			int use_m=Random(0,Min(eledge,Max(eledge/4,5)));
			use_m=Min(use_m,use_n*2);
			if(use_m&&use_n>2)
			{
				int p=Random(0ll,Min(use_m-1ll,EdgeNumber(use_n,link)-use_n));
				Graph g1=MakeSimpleGraph(use_n,use_n+p,Random(0,GRAPH_KIND),link);
				g.Merge(g1,use_m-p);
			}
			else
			{
				Graph g1=MakeSimpleTree(use_n,Random(0,TREE_KIND),link);
				g.Merge(g1,1);
				g=GraphAddEdge(g,use_m);
			}
			el-=use_n;
			eledge-=use_m;
		}
		if(el)
		{
			Graph g1=MixTree(el,link);
			g.Merge(g1,eledge+1);
		}
		else
		{
			g=GraphAddEdge(g,eledge);
		}
		return g;
	}
	inline Graph MixGraph(const int n,const int m,const int link=1,int connect_num=-1)
	{
		if(connect_num==-1)
		{
			int max_=n/5;
			int min_=2;
			if(m<n)
			{
				min_=Max(min_,n-m);
			}
			if(max_<min_)
			{
				max_=Random(min_,n);
			}
			connect_num=Random(min_,max_);
		}
		std::vector<int>vex(connect_num);
		std::vector<int>edg(connect_num);
		vex[0]=n/3;
		int el=n-vex[0];
		for(int i=1;i<connect_num;++i)
		{
			vex[i]=1;
			--el;
		}
		for(int i=0;i<el;++i)
		{
			int id=Random(0,connect_num+connect_num/3);
			id%=connect_num;
			vex[id]++;
		}
		edg[0]=m/3;
		edg[0]=Min((long long)edg[0],EdgeNumber(vex[0],link));
		edg[0]=Max(vex[0]-1,edg[0]);
		int ele=m-edg[0];
		for(int i=1;i<connect_num;++i)
		{
			edg[i]=vex[i]-1;
			ele-=edg[i];
		}
		int tp=ele*2;
		for(int i=0;i<tp;++i)
		{
			if(!ele)
			{
				break;
			}
			int id=Random(0,connect_num+connect_num/3);
			id%=connect_num;
			if(edg[id]==EdgeNumber(vex[id],link))
			{
				continue;
			}
			edg[id]++;
			--ele;
		}
		Graph g=MixGraphConnect(vex[0],edg[0],link);
		int sum=0;
		for(int i=0;i<connect_num;++i)
		{
			sum+=edg[i];
		}
		for(int i=1;i<connect_num;++i)
		{
			Graph g1=MixGraphConnect(vex[i],edg[i],link);
			g.Merge(g1,0);
		}
		if(ele)
		{
			g=GraphAddEdge(g,ele);
		}
		return g;
	}
	// inline Graph MakeDAG(const int n,const int m)
	// {

	// }
}
