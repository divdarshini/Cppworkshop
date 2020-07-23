#include<iostream>
using namespace std;

int checksum(int n)
{ int i, l, d; 
int flag=0;
for(int i=2; i<=n/2; i++)
{
	if(n%i==0)
	{
		flag=1;
		break;
	}
	else
	flag=0;
	
}
return flag;
}


int main()
{ int n,j;
	cout<<"Enter  number:";
	cin>>n;
	for(j=2;j<=n/2;j++)
	if(checksum(j)==0)
	{
		if(checksum(n-j)==0)
		{
			cout<<n<<"="<<j<<"+"<<n-j<<endl;
		}
		
		
	}
	
	return 0;
	
}
	
	
	
