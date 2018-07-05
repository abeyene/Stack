//	Stack.h
//	Implementation of stack data structure representing integer values 
//
//	Copyright (c) 2018 Abel Beyene
//	All rights reserved.
//


#ifndef STACK_H
#define STACK_H

class Stack {
	public:
		Stack (int stack_size);
		~Stack();

		void push(int value);
		int pop();

		bool isFull();
		bool isEmpty();

		void selfTest();

	private:
		int size;
		int top;
		int *stack;
};

#endif		
