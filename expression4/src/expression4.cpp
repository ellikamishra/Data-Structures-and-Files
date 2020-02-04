//============================================================================
// Name        : expression4.cpp
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

   while(a[i]!='\0')
   { t=new tnode;
    t->lchild=NULL;
    t->rchild=NULL;

   //adress of new allocated node
     t->data=a[i];
     if(isalnum(a[i]))
     {  s.push(t);

     }

     else{
          t->rchild=s.pop();
          t->lchild=s.pop();
          s.push(t);
     }

     i++;
   }
  root=s.tope();
  return root;
 }

  void displaytreein(tnode *root1){
  if(root1!=NULL)
  { if(isalpha(root1->data))
    {cout<<root1->data;}
  else
  {  cout<<'(';
 	 displaytreein(root1->lchild);
 	 cout<<root1->data;
 	 displaytreein(root1->rchild);
 	 cout<<')';
  }


  }


 }
  void displaytreepo(tnode *root1){
    if(root1!=NULL)
    {
   	 displaytreepo(root1->lchild);

   	 displaytreepo(root1->rchild);
   	 cout<<root1->data;


    }


   }

  void displaytreepre(tnode *root1){
      if(root1!=NULL)
      {

         cout<<root1->data;
     	 displaytreepre(root1->lchild);

     	 displaytreepre(root1->rchild);




      }


     }
void create1(){

	root=create();

}
void displaytree1(){

	displaytreein(root);
	cout<<"\n";
	displaytreepre(root);
	cout<<"\n";
	displaytreepo(root);
}
};



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
tree t1;
t1.create1();
t1.displaytree1();


	return 0;
}
