//============================================================================
// Name        : binary.cpp
// Author      : ellika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class tnode{
public:
		char data;
		 tnode *lchild;
		 tnode *rchild;


	};



class tree{


public:
	tnode *root;

	tnode *create()
	{ tnode *p;char x;
	  cout<<"Enter data(0 for no data):"<<endl;
	  cin>>x;
	  if(x=='0')
	  {
		  return NULL;
	  }
	  p=new tnode;
	  p->data=x;
	  cout<<"Enter left child"<<endl;
	  p->lchild=create();
	  cout<<"Enter right child"<<endl;
	  p->rchild=create();

	return p;
	}

	tnode *displeaves(tnode *root){
		tnode *temp=root;

		if(temp!=NULL)
		{ if(temp->lchild==NULL&&temp->rchild==NULL)
		{
			cout<<temp->data<<endl;

		}


		displeaves(temp->lchild);
		displeaves(temp->rchild);
		}
	return temp;

	}

void *displaytree(tnode *root){
 if(root!=NULL)
 {
	 displaytree(root->lchild);
	 cout<<root->data;
	 displaytree(root->rchild);
 }


}

//tnode *insert(tnode *root)
//{ tnode *temp;int ch;
//	if(root==NULL)
// {
//	temp=new tnode;
//	cout<<"Enter data"<<endl;
//	cin>>temp->data;
//	return temp;
// }
//
//	else{
//		temp=root;
//		while(ch!=0)
//		{
//			cout<<"Enter 1 to add left,2 for right,0 to end"<<endl;
//			cin>>ch;
//			if(ch==1)
//			{
//				if(temp->lchild==NULL)
//				{
//					temp->lchild=
//				}
//
//
//			}
//
//		}
//
//
//	}
//
//
//}
tnode *copy(tnode *root)
{ tnode *temp=NULL;
  if(root!=NULL)
  { temp=new tnode;
    temp->lchild=copy(root->lchild);
    temp->rchild=copy(root->rchild);

  }

 return temp;
}



};








int main() {
tree t1;
tnode *t2;
t1.root=t1.create();
t1.root=t1.displeaves(t1.root);
t1.displaytree(t1.root);
t2=t1.copy(t1.root);
t1.displaytree(t2);
return 0;

}
