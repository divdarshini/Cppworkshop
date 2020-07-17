#include<iostream>
using namespace std;

//Checking Voting eligibility

void Elibilitycheck(int date, int month, int year)
{ int age,dd,mm,yy, ch;

	do{
	cout<<"Please enter your date of birth in format:dd/mm/yyyy";
	cin>>dd>>mm>>yy;
	if (year>yy)
	{
		int ydiff=year-yy;
		if(ydiff>=19)
		{
			cout<<"You are eligible for voting.";
			
		}
	
		else if(ydiff==18)
		{
	
			if(month>mm)
			cout<<"You are eligible for voting.";
			if(month==mm)
			{
				if(dd<=date)
				cout<<"You are eligible for voting.";
				
				else
				cout<<"You are not eligible for voting."<<"You will be in "<<dd-date<<" days";
				
			}
			if(month<mm)
			cout<<"You are not eligible for voting"<<"You will be in "<<mm-month<<" months";
		}
		
		else if(ydiff<19)
	     cout<<"You are not eligible for voting."<<"You will be in "<<18-ydiff<<" years.";
		
	}
	else
	{
		cout<<"Error. Enter accurate date of birth.";
	}
	cout<<"Do you want to try again? Enter 0/1";
	cin>>ch;
}while(ch==1);
	
	
	
}

int main()

{ int cd=17, cm=7, cy=2020;
		cout<<"Welcome to the vote-eligibility checker:\n";
		cout<<"Today's date:"<<cd<<"/"<<cm<<"/"<<cy;
		Elibilitycheck(cd, cm, cy);
		return 0;
}
