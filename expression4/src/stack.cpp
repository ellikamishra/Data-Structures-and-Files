/*
 * stack.cpp
 *
 *  Created on: 19-Dec-2019
 *      Author: f10
 */

#include<iostream>
#include "stack.h"
template <class t>
void stack<t>::push(t x)
{
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(top==NULL)
		{top=temp;}
	else
	{
		 temp->next=top;
		 top=temp;
     }
}
template <class t>
t stack<t>::pop()
{
	node *temp=top;
	t x=top->data;
	top=top->next;
	delete temp;
	return x;
}

template <class t>
stack<t>::stack() {
	top=NULL;// TODO Auto-generated constructor stub

}
template <class t>
stack<t>::~stack() {
node *temp;

while(top!=NULL)
{ temp=top;
 top=top->next;
  delete temp;

} // TODO Auto-generated destructor stub
}
template <class t>
 t stack<t>::val()
 {
	 if(top==NULL)
	 {return 1;}
	 else
	 {return 0;}

 }
template <class t>
 t stack<t>::tope()
 { return top->data;

 }
