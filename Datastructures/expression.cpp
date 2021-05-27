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
#include"stack.cpp"
using namespace std;

 class expression{

    	string a;
        string b;

        public:
    	void display();
    	void input();
    	void prefix();
    	void postfix();
        int priority(char c);
        void eval();
        int operate(int,int,char);
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
	    case 5:e.eval();
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
{ 	stack<char>s;
    int n=a.length();

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
{  	stack<char>s;
	string c;
    int n,k=0,i;
    n=a.length();
    for(int j=0;j<n;j++)
    {
    	s.push(a[j]);


    }
    for(int j=0;j<n;j++)
       {
        	c[j]=s.pop();


        }
    cout<<c;



	for(int j=0;j<n;j++)
	{ if(c[j]==')')
	    {c[j]='(';}
	  else if(c[j]=='(')
	    {c[j]=')';}
	  else
	    continue;
	}
	cout<<"\nExpression:"<<c<<endl;
	for( i=0;i<n;i++)
 	{ 	if(isalpha(c[i]))
 	  { 	b[k]=c[i];k++;

 	  }


 	else if(c[i]==')')
       {
      while(s.tope()!='(')
      { b[k]=s.pop();k++;


      }
      s.pop();
       }
 	else if(c[i]=='(')
 	{s.push(c[i]);}

 		else
 		{
          while(!s.val()&&priority(s.tope())>=priority(c[i]))
          {
               b[k]=s.pop();k++;
 		  }

         s.push(c[i]);



        }
 }


	while(!s.val())
	{b[k]=s.pop();k++;}
	for(int j=0;j<n;j++)
	    {
	    	s.push(b[j]);


	    }
	 for(int j=0;j<n;j++)
	     {
	        b[j]=s.pop();


	     }


  for(int j=0;j<k;j++)
   {cout<<b[j];}
  cout<<endl;
}

void expression::eval()
{
	stack<int>s;

	int i=0;
	int op1,op2;
	int n=b.length();

	if(isalpha(b[i])||isdigit(b[i]))
	{ while(i<n)
	{if(isalpha(b[i]))
	   { cout<<"Enter value for term"<<endl;
	     cin>>b[i];
		 s.push(b[i]);i++;
	    }
	else if(isdigit(b[i]))
	   {

		s.push(b[i]);i++;

	   }
	  else
	   { op2=s.pop();
		 op1=s.pop();
		 s.push(operate(op1,op2,b[i]));i++;

	   }

	}

	}

	else
	{ while(i<n)
	{	if(isalpha(b[i]))
	   { cout<<"Enter value for term"<<endl;
	     cin>>b[i];
		 s.push(b[i]);i++;
	    }
	else if(isdigit(b[i]))
	   {

		s.push(b[i]);i++;

	   }
	  else
	   { op1=s.pop();
		 op2=s.pop();
		 s.push(operate(op1,op2,b[i]));
		 i++;
	   }




	}

	}

	cout<<"Result:"<<s.pop()<<endl;


}

int expression::operate(int a,int b,char c)
{
	switch(c)

		{



		  case '+':return a+b;

		  case '-':return a-b;

		  case '*':return a*b;

          case '/':return a/b;



		}

	return 0;


}


	
    
