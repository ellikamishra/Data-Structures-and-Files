/*
 * stack.h
 *
 *  Created on: 19-Dec-2019
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_

class stack {

	struct node{

		int data;
		struct node *next;
	};
	struct node *top;
public:
	stack();
	void push(char x);
	char pop();
	int val();
	char tope();
	virtual ~stack();
};

#endif /* STACK_H_ */
