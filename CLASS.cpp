#include<iostream>
using namespace std;

class enterhr
{
protected:
int h=0;
public:
 void gethour()
 {
 	cout<<"Enter hours value:"<<endl;
 	cin>>h;
 	
 }	

	
};
	


class entermin
{
protected:
int m=0;
public:
 void getmin()
 {
 	cout<<"Enter minutes value:"<<endl;
 	cin>>m;
}
	
};

class entersec:public entermin
{
	protected:
	int s=0;
	public:
	void getsec()
	{
	cout<<"Enter seconds value:"<<endl;
	cin>>s;
    }
	
	
	
};

class converter:public entersec, public enterhr
{
	public:
		int res=0;
		void convert()
		{
			res=(h*3600)+(m*60)+s;
			cout<<"In total seconds: "<<res<<endl;
		}
	
	
	
};

int main()
{
	converter con;
	con.gethour();
	con.getmin();
	con.getsec();
	con.convert();
	return 0;}
