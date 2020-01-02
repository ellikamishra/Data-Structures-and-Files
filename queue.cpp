//============================================================================
// Name        : queue.cpp
// Author      : ellika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class patients{

	char name[50];
	char mobileno[50];
	char bldg[10];
	char disease[50];
	int  priority;
public:
	void input();
	void display();
	void displaynext();
    int priorityset();


};

int main() {
  patients p[20];
  int ch,n,l=0;
  do
  {cout<<"\nEnter 1 to input,2 to show next,3 to display\n";
   cin>>ch;
   switch(ch)
   	   {

   case 1:cout<<"Enter no. of records to be created"<<endl;
          cin>>n;
          for(int i=l;i<n+l;i++)
          {  p[i].input();


           }
          l=n;


   	   }

  }while(ch!=0);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


void patients::input()
{  cout<<"Enter name:"<<endl;
   cin.ignore();
   cin.getline(name,50);
   cout<<"Enter mobile no."<<endl;
   cin.getline(mobileno,50);
   cout<<"Enter blood group"<<endl;
   cin.getline(bldg,10);
   cout<<"Enter disease"<<endl;
   cin.getline(disease,50);







}
