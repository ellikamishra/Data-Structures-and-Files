//============================================================================
// Name        : expression.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<algorithm>
#include<cstring>
#include"stack.h"
using namespace std;

 class expression{

    	string a;
    	

        public:
    	void display();
    	void input();
    	void prefix();
    	void postfix();
        int priority(char c);

};



int main() {
	expression e;

	int ch;
		do{
	 cout<<"Enter 1 to input,2 to display,3 for postfix,4 for prefix,5 to evaluate"<<endl;
	 cin>>ch;
	 switch(ch)
	 {	case 1:e.input();
	 	       break;
	    case 2:e.display();
	           break;
	    case 3:e.postfix();
               break;
	    case 4:e.prefix();
               break;
	 }

		 }while(ch!=0);
	return 0;
}


void expression::input()
{   cout<<"Enter expression"<<endl;
    cin.ignore();
    getline(cin, a);

}


void expression::display()
{   int n=a.length();
	cout<<"\nExpression is:";
	for(int i=0;i<n;i++)
	{
		cout<<a[i];

	}
	cout<<"\n";
}

void expression::postfix()
{ 	stack s;
    int n=a.length();
    char b[100];
    int k=0,i=0;
	for( i=0;i<n;i++)
 	{ 	if(isalpha(a[i]))
 	  { 	b[k]=a[i];k++;

 	  }


 	else if(a[i]==')')
       {
      while(s.tope()!='(')
      { b[k]=s.pop();k++;


      }
      s.pop();
       }
 	else if(a[i]=='(')
 	{s.push(a[i]);}

 		else
 		{
          while(!s.val()&&priority(s.tope())>=priority(a[i]))
          {
               b[k]=s.pop();k++;
 		  }

         s.push(a[i]);



        }
 }


	while(!s.val())
	{b[k]=s.pop();k++;}

  for(int j=0;j<k;j++)
  {cout<<b[j];}
  cout<<endl;
}
int expression::priority(char c)
{ 	switch(c)

	{

      case ')': return 0;

	  case '(':return 0;

	  case '+':return 1;

	  case '-':return 1;

	  case '*':return 2;


	 case '/':return 2;

	}
	return 0;
}


void expression::prefix()
{  	stack s;
    int n,k=0,i;
	string b;
	reverse(a.begin(),a.end());
	
	
	 n=a.length();
	for(int j=0;j<n;j++)
	{ if(a[j]==')')
	    {a[j]='(';}
	  else if(a[j]=='(') 
	    {a[j]=')';}
	  else
	    continue;
	}
	cout<<"\nExpression:"<<a<<endl;
	for( i=0;i<n;i++)
 	{ 	if(isalpha(a[i]))
 	  { 	b[k]=a[i];k++;

 	  }


 	else if(a[i]==')')
       {
      while(s.tope()!='(')
      { b[k]=s.pop();k++;


      }
      s.pop();
       }
 	else if(a[i]=='(')
 	{s.push(a[i]);}

 		else
 		{
          while(!s.val()&&priority(s.tope())>=priority(a[i]))
          {
               b[k]=s.pop();k++;
 		  }

         s.push(a[i]);



        }
 }


	while(!s.val())
	{b[k]=s.pop();k++;}
	reverse(b.begin(),b.end());
   	for(int j=0;j<k;j++)
  {cout<<b[j];}
  cout<<endl;
	}
	
    
