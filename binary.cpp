//============================================================================
// Name        : binary.cpp
// Author      : ellika 23221
// Version     :
// Copyright   : Your copyright notice
// Description : AIM: Create Binary Tree (BT) and perform following operations:
a. Insert
b. Display
c. Depth of a tree
d. Display leaf-nodes
e. Create a copy of a tree
//============================================================================

#include <iostream>
using namespace std;

struct tnode{

		 char data;
		 tnode *lchild;
		 tnode *rchild;


	};
class tree{
	tnode *root=NULL;

public:
    tnode *create()
	{ char x;tnode *p;
	  cout<<"Enter data(0 for no data):"<<endl;
	  cin>>x;

	  if(x=='0')
	  {
		  return NULL;
	  }
	  p=new tnode;
	  p->data=x;
	  if(root==NULL)
	  	  {
	  		  root=p;
	  	  }
	  cout<<"Enter left child of\t"<<x<<endl;
	  p->lchild=create();
	  cout<<"Enter right child\t"<<x<<endl;
	  p->rchild=create();

	return p;
	}

	tnode *displeaves(tnode *root1){
		tnode *temp=root1;

		if(temp!=NULL)
		{ if(temp->lchild==NULL&&temp->rchild==NULL)
		{
			cout<<"\n"<<temp->data<<endl;

		}

        displeaves(temp->lchild);
		displeaves(temp->rchild);
		}
	return temp;

	}

tnode * displaytree(tnode *root1){
 if(root1!=NULL)
 {
	 displaytree(root1->lchild);
	 cout<<root1->data;
	 displaytree(root1->rchild);
 }
return root1;

}

tnode *insert(tnode *root)
{ tnode *temp;int ch;
  temp=root;
  if(temp==NULL)
  {

	  temp=new tnode;
	  cout<<"Enter data"<<endl;
	  cin>>temp->data;

	  	return temp;

  }

  else{
    	cout<<"Enter 1 to add left,2 for right,0 to end"<<endl;
    	cin>>ch;
            if(ch==1)
			{
				temp->lchild=insert(temp->lchild);
                return temp;
			}
				if(ch==2)
				{
				 temp->rchild=insert(temp->rchild);
                 return temp;
				}
             }

  return root;

	}
tnode *copy(tnode *root1)
{ tnode *temp=NULL;
  if(root1!=NULL)
  { temp=new tnode;
    temp->data=root1->data;
    temp->lchild=copy(root1->lchild);
    temp->rchild=copy(root1->rchild);

  }
return temp;
}

int depth(tnode *root)
{ int htl,htr;

 if(root==NULL)
   { return 0;}
 else
 {
	 htl=depth(root->lchild)+1;
	 htr=depth(root->rchild)+1;
 }
if (htl>htr)
 {return htl;}
 else
 {return htr;}
}
};
int main() {
tree t1;int ch;
tnode *t2;
tnode *t3;

do
{ cout<<"\nEnter 1.to create\n2.to display tree\n3.to display leaves\n4.to copy\n5.for depth\n6.to insert"<<endl;
  cin>>ch;
  switch(ch)
  {case 1:t2=t1.create();
          break;
  case 2:t2=t1.displaytree(t2);
          break;
  case 3: t2=t1.displeaves(t2);
          break;
  case 4:t3=t1.copy(t2);
         t3=t1.displaytree(t3);
          break;
  case 5:cout<<"\n"<<t1.depth(t2);
         break;
  case 6:t2=t1.insert(t2);
         t2=t1.displaytree(t2);
	     break;
  }
}while(ch!=0);
return 0;
}
/*
 * Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
1
Enter data(0 for no data):
a
Enter left child of	a
Enter data(0 for no data):
b
Enter left child of	b
Enter data(0 for no data):
c
Enter left child of	c
Enter data(0 for no data):
0
Enter right child	c
Enter data(0 for no data):
0
Enter right child	b
Enter data(0 for no data):
d
Enter left child of	d
Enter data(0 for no data):
0
Enter right child	d
Enter data(0 for no data):
0
Enter right child	a
Enter data(0 for no data):
e
Enter left child of	e
Enter data(0 for no data):
0
Enter right child	e
Enter data(0 for no data):
0

Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
2
cbdae
Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
3

c

d

e

Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
4
cbdae
Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
5

3
Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
6
Enter 1 to add left,2 for right,0 to end
2
Enter 1 to add left,2 for right,0 to end
1
Enter data
w
cbdawe
Enter 1.to create
2.to display tree
3.to display leaves
4.to copy
5.for depth
6.to insert
 *
 *
 *
 *
 * */
