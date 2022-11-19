# C-learning
#include<iostream>
using namespace std;

class intSet
{
public:
	intSet();
    intSet(int a[ ],int size);
    void Empty();     //清空集合
    bool IsEmpty();   //判断集合是否为空
    bool IsMemberOf(int a);   //判断某个整数是否在该集合内
    bool Add(int a);   //向集合中增加一个元素
	bool Sub(int a);    //从集合中删除一个元素
	bool IsEqual(intSet &set);   //判断两个集合是否相等
	intSet Intersction(intSet &set);   //求两个集合的交集
	intSet Merge(intSet &set);    //求两个集合的并集
	void Copy(intSet &set);     //完成集合的复制
	void Print();
private:
	int element[100];
	int EndPosition;   //指示集合的最后一个元素位置,下标 
};

intSet::intSet(){
	EndPosition=-1;
}


intSet::intSet(int a[],int size)
{EndPosition=size-1;
 for(int i=0;i<size;i++){
 	element[i]=a[i];
 }
}

void intSet::Empty(){
	EndPosition=-1;
} 

bool intSet::IsEmpty(){
	if(	EndPosition==-1) return true;
	return false;
}

bool intSet::IsMemberOf(int a){
	 for(int i=0;i<EndPosition+1;i++){
 	if(element[i]==a) return true;
 }
 return false;
}

bool intSet::Add(int a){
	if(IsMemberOf(a))return true;
	EndPosition++;
	element[EndPosition]=a;
	return true;
}

bool intSet::Sub(int a){
	if(!IsMemberOf(a)) {cout<<"不存在";return false;} 
	int temp=0;	
	 for(int i=0;i<EndPosition+1;i++){
 	if(element[i]==a) temp=i;
 }
	 for(int i=temp;i<EndPosition;i++){
 	element[i]=element[i+1];
 }	
	    EndPosition--;
		return true;
}

bool intSet::IsEqual(intSet &set){
	if(set.EndPosition!=EndPosition) return false;
	for(int i=0;i<set.EndPosition+1;i++)
	{if(IsMemberOf(set.element[i])) return false;}
	return true;
}
	
intSet intSet::Merge(intSet &set)	{ //并集 
	intSet te;
	te.Copy(set);
	for(int i=0;i<=EndPosition;i++){
	if(!te.IsMemberOf(element[i])) te.Add(element[i]);
	
	}return te;
	
}
	
intSet intSet::Intersction(intSet &set)	{  //交集 
	intSet te;
	for(int i=0;i<=set.EndPosition;i++){
	if(IsMemberOf(set.element[i])) te.Add(set.element[i]);
	return te;
	}
}	
	
void intSet::Copy(intSet &set){
	EndPosition=set.EndPosition;
 for(int i=0;i<=EndPosition;i++){
 	element[i]=set.element[i];
 }
}
	
void intSet::Print(){
	if(EndPosition==-1)cout<<"为空集";
	else for(int i=0;i<=EndPosition;i++){
 	cout<<element[i]<<" "; 
 }
}
	
int main() 
{ intSet te;
int temp1[3]={0,1,2};int temp2[4]={0,2,4,5}; 
 cout<<"a集：";
intSet a(temp1,3);a.Print();cout<<endl;
cout<<"b集：";
intSet b(temp2,4);b.Print();cout<<endl;
cout<<"a,b的并集："; 
te=a.Merge(b);
te.Print();//并集 
cout<<endl;
cout<<"a,b的交集：";
te=a.Intersction(b);te.Print();cout<<endl;
	return 0;
}
