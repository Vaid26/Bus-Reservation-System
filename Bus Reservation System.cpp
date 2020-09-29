#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

class Bus

{

  char bus_no[5], driver[20], arrival[5], depart[5], from[10], to[10], seat[8][4][10], daysavail[10];

public:

  void addnewbus();

  void booking();

  void empty();

  void display();

  void available();

  void status(int i);

  void payment();

}

bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void Bus::addnewbus(){
    cout<<"\nEnter Bus number:";
    cin>>bus[p].bus_no;
    cout<<"\nEnter Driver's name:";
    cin>>bus[p].driver;
    cout<<"\nEnter time of Arrival:";
    cin>>bus[p].arrival;
    cout<<"\nEnter time of Departure:";
    cin>>bus[p].depart;
    cout<<"\nEnter Boarding place:";
    cin>>bus[p].from;
    cout<<"\nEnter Destination:";
    cin>>bus[p].to;
    cout<<"\nEnter the days for which bus is available for given route:";
    cin>>bus[p].daysavail;
    bus[p].empty();
    p++;
    }



void Bus::booking(){
     int seat, n, age, phonenum[10];
  char number[5], gender[10];
  string email[20];
  top:
  cout<<"\nEnter Bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].bus_no, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nEnter desired Seat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passenger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        cout<<"\nAge:";
        cin>>age;
        cout<<"\nGender:";
        cin>>gender;
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }



void Bus::empty()

{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}


void Bus::display(){
  int n;
  char number[5];
  cout<<"\nEnter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].bus_no, number)==0)
    break;
  }
while(n<=p)
{
  cout<<"\n\nBus no: \t"<<bus[n].bus_no
  <<"\nDriver's name: \t"<<bus[n].driver
  <<"\tArrival time: \t"<<bus[n].arrival
  <<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom:"<<bus[n].from
  <<"\tTo:\t"<<bus[n].to<<"\n"
  <<"\nThe bus is available for:"<<bus[n].daysavail<<" days\n\n";
  vline('*');
  bus[0].status(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}



void Bus::status(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j=0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].bus_no;
  }

  void Bus::available()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"Bus no: \t"<<bus[n].bus_no
    <<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival
    <<"\tDeparture Time: \t"<<bus[n].depart
    <<"\nFrom:\t"<<bus[n].from
    <<"\tTo:\t"<<bus[n].to<<"\n";
    vline('*');
  }
}



void Bus::payment(){
    int choice;
    char name[20], amount[10], cardno[15];
    top:
    cout<<"\nEnter payment option:\n1.Pay two days prior boarding.\t2.Pay online.";
    cin>>choice;
    if(choice==1){
            cout<<"\nYour seat will be locked for you. If you fail to pay two days befor boarding then your seat will be alloted to someone else.";
    }
    else{
        cout<<"\nEnter bank name:";
        cin>>name;
        cout<<"\nEnter card number";
        cin>>cardno;
        cout<<"\nEnter the amount to be payed:";
        cin>>amount;
        cout<<"\nDo you want to confirm booking?\n1.Yes\t2.No";
        cin>>choice;
        if(choice==1){
            cout<<"\n\nYour booking has been confirmed.\nHave a safe journey:)";
        }
        else{
            goto top;
        }
    }
}




int main(){
system("cls");
int r;
while(1)
{
  cout<<"\n\t\t\t\t\t\t**WELCOME TO SAINI TRAVELS**";
  cout<<"\n\n\n\t\t\t\t\t\t1.Add new Bus details\n\t\t\t\t\t\t"
  <<"2.Booking\n\t\t\t\t\t\t"
  <<"3.Display\n\t\t\t\t\t\t"
  <<"4.Buses Available. \n\t\t\t\t\t\t"
  <<"5.Payment gateway.\n\t\t\t\t\t\t"
  <<"6.Exit";
  cout<<"\n\n\t\t\t\t\t\tEnter your choice:";
  cin>>r;
  switch(r)
  {
    case 1:  bus[p].addnewbus();
      break;
    case 2:  bus[p].booking();
      break;
    case 3:  bus[0].display();
      break;
    case 4:  bus[0].available();
      break;
    case 5:  bus[0].payment();
      break;
    case 6:  exit(0);
  }
}
return 0;
}
