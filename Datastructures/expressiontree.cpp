//============================================================================
// Name        : expressiontree.cpp
// Author      : ellika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "stack.cpp"
#include "stack.h"
using namespace std;

class tnode{
     char data;
     tnode *lchild;
     tnode *rchild;
    friend class tree;

};

class tree{
 tnode *root;


public:
 tnode *create()
 { stack<tnode*>s;
   char a[20];int i=0;
   tnode *t;
   cout<<"Enter expression"<<endl;
   cin>>a;

   while(a[i]!=NULL)
   { t=new tnode; //adress of new allocated node
     t->data=a[i];
     if(isalnum(a[i]))
     {  s.push(t);

     }

     else{
          t->rchild=s.pop();
          t->lchild=s.pop();
          s.push(t);
     }

   }

 }

  tnode * displaytree(tnode *root1){
  if(root1!=NULL)
  {  if(isalpha(root1->data))
     {cout<<root1->data;}
  else
  {  cout<<'(';
 	 displaytree(root1->lchild);
 	 cout<<root1->data;
 	 displaytree(root1->rchild);
 	 cout<<')';
  }
 return root1;
  }

 }

void create1(){

	root=create();

}
void displaytree1(){

	root=displaytree(root);

}
};



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
tree t1;
t1.create1();
t1.displaytree1();


	return 0;
}
