//	Stack.cc
//		Implementation of member functions in Stack.h.
//		The stack is represented as an array.
//
//	Copyright (c) 2018 Abel Beyene
//	All rights reserved


extern "C" {
	#include <assert.h>
}

#include <iostream>
#include "Stack.h"

using namespace std;

//------------------------------------------------------------------
//	Stack::Stack
//		The constructor to the stack class
//
//	"size" -- The largest number of elements the stack can hold	
//------------------------------------------------------------------

Stack::Stack(int stack_size) {
	
	assert(stack_size>1);

	size = stack_size;
	top = 0;
	stack = new int[size];

}


//------------------------------------------------------------------
//	Stack::~Stack
//		The destructor of the stack class
//------------------------------------------------------------------

Stack::~Stack() {
	delete [] stack;
}

//------------------------------------------------------------------
//	Stack::push
//		Add an element to the top of the stack
//
//	"value" -- The item to be added (which is an integer type)
//------------------------------------------------------------------

void Stack::push(int value) {
	assert(!isFull());

	stack[top++] = value;
}

//------------------------------------------------------------------
//	Stack::pop
//		Remove the top element of the stack
//
//------------------------------------------------------------------

int Stack::pop() {
	assert(!isEmpty());

	return stack[--top];
}


//--------------------------------------------------------------------
//	Stack::isFull
//		Checks if top of the stack corresponds to stack length
//
//--------------------------------------------------------------------

bool Stack::isFull() {
	return top==size;
}	

bool Stack::isEmpty() {
	return top==0;
}

//--------------------------------------------------------------------
//	Stack::selfTest
//		Ensures the stack works by placing 5 numbers inside
//		and then printing them off after they've been removed
//
//--------------------------------------------------------------------

void Stack::selfTest() {
	int count=5;

	while(!isFull() && count>0) {
		cout << "Adding "<< count << " to the stack...\n";
		push(count--);
	}

	cout<<"\nNow printing...\n";

	while(!isEmpty())
		cout<<pop()<<"\n";
}

int main() {
	Stack *stack = new Stack(10);

	stack->selfTest();

	delete stack;
	return 0;
}
