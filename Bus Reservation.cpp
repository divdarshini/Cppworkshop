#include<iostream>
//#include<conio.h>
#include<string.h>
#include<cstdio>
#include<stdlib.h>

using namespace std;
static int k=0;//global static and the same instance of k variable is used throughout the program
class proj1
{
	char busno[4], driver[20], arrival[5], departure[5], from[10], to[10],
	seat[8][4][15];
	/*8 rows with 4 seats in each row. 
	For each seat the passenger's name is inputted with 15 characters 
	or 'empty' is inputted */
	
	
	public:
		void create();//for administrator
		void reserve();//user side
		void empty();//for administrator
		void show();//for administrator
		void available();//user side
	    void position(int y);//for administrator

}bus[10];//maximum no. of buses that can be created

void vline(char ch)//for neat presentation purposes to give * or _
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void proj1::create()//for the admin to create buses and their travel schedules.
{
  cout<<"Enter bus no: ";
  cin>>bus[k].busno;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[k].driver;
  cout<<"\nArrival time: ";
  cin>>bus[k].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[k].departure;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[k].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[k].to;
  bus[k].empty();
 k++;
}
void proj1::reserve()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=k;n++)
  {
    if(strcmp(bus[n].busno, number)==0)
    break;
  }
  while(n<=k)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
     if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)//if seat is empty
        {
         cout<<"Enter passenger's name: ";
         cin>>bus[n].seat[seat/4][(seat%4)-1];
        
         cout<<"Congratulations! Your booking has been successfully made."<<endl;
         cout<<"Here is your ticket:"<<endl;
         cout<<"\t Bus no: \t"<<bus[n].busno<<endl;
         vline('*');
         cout<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
         <<bus[n].arrival<<"\tDeparture time:\t"<<bus[n].departure
         <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
         bus[n].to<<"\tPassenger Name:\t"<<bus[n].seat[seat/4][(seat%4)-1]<<"\t Paid standard fare: Rs.10"<<endl;
		 vline('*');
         break;
        }
     else
      cout<<"The seat no. is already reserved by "<<bus[n].seat[seat/4][(seat%4)-1]<<"\n";
    }
  
  }
    if(n>k)
    {
      cout<<"Enter correct bus no.\n";
      goto top;//if bus no exceeds number created.
    }
  }
void proj1::empty()//this function is to first allot all seats as empty so that passengers can later book seats.It is also called within function create.
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[k].seat[i][j], "Empty");
    }
  }
}

void proj1::show()
{
  int n;
  char number[5];
  b:
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=k;n++)
  {
    if(strcmp(bus[n].busno, number)==0)
    break;
  }
while(n<=k)
{ cout<<"\t Bus no: \t"<<bus[n].busno<<endl;
  vline('*');
  cout<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].departure
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<endl;//prints bus travel schedule
  
  vline('*');
  bus[0].position(n);//a visual of the bus seats and reservations
  int a=0;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }//this will display all the booked seats in that bus and their respective passenger names.
  break;
  }
  if(n>k)
    cout<<"Enter correct bus no: ";
    goto b;
}

void proj1::position(int y)
{
  int s=0, p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;//seat number count
      if(strcmp(bus[y].seat[i][j], "Empty")==0)//if seat empty
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[y].seat[i][j];
          p++;//to count empty seats/available seats in that bus
        }
        else//if seat booked
        {
        cout.width(5);//set width of 5 characters
        cout.fill(' ');//fill using space
        cout<<s<<".";
        cout.width(10);//set width of 10 characters
        cout.fill(' ');
        cout<<bus[y].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[y].busno;
  }
void proj1::available()//to display details of all existing buses and their travel schedules.
{
  for(int n=0;n<k;n++)
  {
   vline('*');
    cout<<"Bus no: \t"<<bus[n].busno<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].departure<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}


int main()
{

int w;
while(1)
{
    
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Create\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show\n\t\t\t"
  <<"4.Provide Buses Availability.\n\t\t\t"
  <<"5.Exit";
  /*using\t gives four times spoacebar gap and 
  \n enters into new line*/
  
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[k].create();
      break;
    case 2:  bus[k].reserve();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].available();
      break;
    case 5:  exit(0);//will exit if user does not want to repeat 
  }
}
return 0;
}
	    

