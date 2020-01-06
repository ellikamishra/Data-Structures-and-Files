/*
 * quell.cpp
 *
 *  Created on: 02-Jan-2020
 *      Author: f10
 */
#include<iostream>
#include "quell.h"
using namespace std;
template <class t>
void quell<t>::enque(t a){
	node *temp;


	temp=new node;
	temp->data=a;
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
return 0;
}
template <class t>
t quell<t>::deque(int a){
   node *temp;node *prev;
   temp=front;prev=front;
   while(a!=0)
   {prev=temp;
	temp=temp->next;
    a--;
   }
   t x=temp->data;
  prev->next=temp->next;
  delete(temp);
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



	while(front!=NULL)
	{ front=front->next;
	  delete front;

	} // TODO Auto-generated destructor stub
}

