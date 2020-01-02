/*
 * quell.cpp
 *
 *  Created on: 02-Jan-2020
 *      Author: f10
 */
#include<iostream>
#include "quell.h"
template <class t>
void quell<t>::enque(t){
	node *temp;

	t x;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
    if(isempty())
    {   front=temp;
    	rear=temp;
    }

    else
    {
    	rear->next=temp;
    	rear=temp;
    }

}
template <class t>
int quell<t>::isempty(){

   if(front==NULL&&rear==NULL)
  {return 1;}

}
template <class t>
t quell<t>::deque(){
   node *temp;
   temp=front;
   t x=temp->data;
   front=front->next;
   return x;
}
template <class t>
quell<t>::quell() {
	// TODO Auto-generated constructor stub
front=NULL;
rear=NULL;

}
template <class t>
quell<t>::~quell() {

	node *temp;

	while(front!=NULL)
	{ front=front->next;
	  delete temp;

	} // TODO Auto-generated destructor stub
}

