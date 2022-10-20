#include<iostream>
using namespace std; 

class Rational{
public:
	Rational(int xx=1,int yy=1): x(xx), y(yy) {Dou_Res=1.0*x/y;}
	void Add(Rational a);
	void Sub(Rational s);
	void Mul(Rational m);
	void Div(Rational d);
	void Out_double();
	void Out_rational();
private:
	int x,y;
	double Dou_Res;
	void Simplify(int rx,int ry){
		int temp,Mod;
		int simx,simy;
		simx=rx;simy=ry;
		if(simx>simy){temp=simx;simx=simy;simy=temp;}//y>x
		Mod=simy%simx;
		while(Mod){
			simy=simx;simx=Mod;
			Mod=simy%simx;
		}simy=simx;simx=Mod;
		y=ry/simy; x=rx/simy;
		
	}
	
};



void Rational::Mul(Rational m){
	x=m.x*x; y=m.y*y;
	Simplify(x,y);
}

void Rational::Div(Rational d){
	x=d.y*x; y=d.x*y;
	Simplify(x,y);
}

void Rational::Out_double(){
	Dou_Res=1.0*x/y;
    cout<<(Dou_Res)<<endl;
}

void Rational::Out_rational(){Simplify(x,y);
	if(y==1) cout<<x<<endl;
	else cout<<x<<'/'<<y<<endl;
	
} 

void Rational::Add(Rational a){
	 x*=a.y;  //通分 
	x=x+y*a.x;y*=a.y;
	Simplify(x,y);
}

void Rational::Sub(Rational s){
	 x=s.y*x;  //通分 
	x=x-y*s.x;y*=s.y;
	Simplify(x,y);
}

int main() {
	int a,b;
	cin>>a>>b;
	Rational three_2(a,b), one_2(1,2);
	three_2.Out_rational();
	three_2.Out_double();
	cout<<endl;

	three_2.Add(one_2);   //加
	cout<<"a/b + 1/2=";
	three_2.Out_rational();
	three_2.Out_double();
    cout<<endl;

	three_2.Sub(one_2);   //减
	cout<<"a/b + 1/2- 1/2=";
	three_2.Out_rational();
	three_2.Out_double();
	cout<<endl;

	three_2.Mul(one_2);  //乘
	cout<<"a/b * 1/2=";
	three_2.Out_rational();
	three_2.Out_double();
	cout<<endl;
	
	three_2.Div(one_2);   //除
	cout<<"a/b / 1/2=";
	three_2.Out_rational();
	three_2.Out_double();
	return 0;
}
