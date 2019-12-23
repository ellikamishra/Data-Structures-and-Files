/*
 * stack.cpp
 *
 *  Created on: 19-Dec-2019
 *      Author: f10
 */

#include<iostream>
#include "stack.h"

void stack::push(char x)
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

char stack::pop()
{
	node *temp=top;
	char x=top->data;
	top=top->next;
	delete temp;
	return x;
}


stack::stack() {
	top=NULL;// TODO Auto-generated constructor stub

}

stack::~stack() {
node *temp;

while(top!=NULL)
{ top=top->next;
  delete temp;

} // TODO Auto-generated destructor stub
}
 int stack::val()
 {
	 if(top==NULL)
	 {return 1;}
	 else
	 {return 0;}

 }

 char stack::tope()
 { return top->data;

 }
