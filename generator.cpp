#include"makedata.h"
using namespace std;
using namespace IO;
using namespace MD;
const bool WRITET=0;
const int T=1;

inline void Make(const int testid,const int dataid)
{

}
int main(int argc,char* argv[])
{
	int dataid=-1;
	if(argc==2)
	{
		dataid=atoi(argv[1]);
	}
	if(WRITET)
	{
		Writeln(T);
	}
	REP(i,1,T)
	{
		Make(i,dataid);
	}
	return 0;
}
