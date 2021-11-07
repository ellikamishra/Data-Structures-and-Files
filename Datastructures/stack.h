/*
 * stack.h
 *
 *  Created on: 19-Dec-2019
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_
template <class t>
class stack {

	struct node{

		t data;
		struct node *next;
	};
	struct node *top;
public:
	stack();
	void push(t x);
	t pop();
	t val();
    t tope();
	virtual ~stack();
};

#endif /* STACK_H_ */
