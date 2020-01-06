/*
 * quell.h
 *
 *  Created on: 02-Jan-2020
 *      Author: f10
 */
#include<iostream>
#ifndef QUELL_H_
#define QUELL_H_
template <class t>
class quell {

	struct node{

			t data;
			struct node *next;
		};
	struct node *front;
	struct node *rear;
	public:
	quell();
	void enque(t a);

	t deque(int a);
	int isempty();
	virtual ~quell();
};

#endif /* QUELL_H_ */
