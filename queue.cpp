//============================================================================
// Name        : queue.cpp
// Author      : ellika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
#include"quell.cpp"
#include"quell.h"

using namespace std;

class patients{

	char name[50];
	char mobileno[50];
	char bldg[10];
	char disease[50];

public:
	void input();
	void display();

    int priorityset();
    int  priority;

};

int main() {
  patients p[20],r;
  quell<patients> q;
  int ch,n,l=0,max;
  do
  {cout<<"\nEnter 1 to input,2 to show next,3 to display\n";
   cin>>ch;
   switch(ch)
 {

   case 1:cout<<"Enter no. of records to be created"<<endl;
          cin>>n;
          for(int i=0;i<n;i++)
          {  p[i].input();
             q.enque(p[i]);

           }

          break;
   case 2:cout<<"Display next:"<<endl;
           max=p[0].priority;
           for(int i=0;i<n;i++)
          {  if(max<p[i].priority)
              { max=p[i].priority;}
          }
           for(int i=0;i<n;i++)
          {  if(max==p[i].priority)
               {r=q.deque(i);
                break;
               }
          }
           r.display();
          break;

   case 3:for(int i=0;i<n;i++)
          { p[i].display();}
          break;
   	   }
  }while(ch!=0);

	return 0;
}


void patients::input()
{  cin.ignore();

   cout<<"Enter name:"<<endl;
   cin.getline(name,50);
   cout<<"Enter mobile no."<<endl;
   cin.getline(mobileno,50);
   cout<<"Enter blood group"<<endl;
   cin.getline(bldg,10);
   cout<<"Enter disease"<<endl;
   cin.getline(disease,50);
   priority=priorityset();

}

int patients::priorityset()
{  if(!(strcmp(disease,"flue")&&strcmp(disease,"cough")))
       {return 1;}
   else if(!(strcmp(disease,"fracture")&&strcmp(disease,"injury")))
       {  return 2; }
   else
   { return 3;    }



}

void patients::display()
{ cout<<"Name:"<<name<<endl;
  cout<<"Mobile no.:"<<mobileno<<endl;
  cout<<"Blood group:"<<bldg<<endl;
  cout<<"Disease:"<<disease<<endl;

}
