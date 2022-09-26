#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
#define N 10

int Add(char *mem1, char *mem2, char *res, int n)
{   int i,j=0,num=0,more=0;
	for(i=N-1;i>=0;i--)
	{
		num=more+(mem1[i]-'0')+(mem2[i]-'0');
		if(num>10){more=num/10;num=num%10;}
		res[j++]=num+'0';
	}
	if(more){res[j]=more+'0';}
	else j--;
	return j;
}

int main()
{ char ten1[N], ten2[N], result[N+1]={0};
  int k;
  cout<<"请输入第一个十位数"<<endl;
  cin>>ten1;
  cout<<"请输入第二个十位数"<<endl;
  cin>>ten2;
  k=Add(ten1, ten2, result, N);
  cout<<ten1<<'+'<<ten2<<'=';
  for(;k>=0;k--)
  cout<<result[k];}
