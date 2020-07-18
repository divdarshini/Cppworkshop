#include<iostream>
using namespace std;
int main()
{
	int *ptr, arr[5];
	ptr=arr;
	cout<<"Enter the elements of the array:"<<endl;
	int len= sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<len; i++)//user input
	{
	  cin>>*(arr+i);	
	}
	for(int j=0; j<len; j++)//output
	{
		cout<<*ptr<<endl;
		ptr++;
		
	}
	
	return 0;
}
