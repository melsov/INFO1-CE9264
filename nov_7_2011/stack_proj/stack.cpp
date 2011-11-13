#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

/* Matthew Poindexter.  HW 2.6 a/b for CPP Part I  */

stack::stack(const stack& another)
{
	for (size_t i =0; i < stack_max_size; ++i) {
		a[i] = another.a[i];
	}
	
	p = a;
}

stack::~stack()   //destructor
{
	//cout << "destructor for stack\n";
	
	if (size() != 0) {
		cerr << "Warning: stack still contains " << size() << " value(s).\n";
	}
}

//Push a value onto the stack.

void stack::push(int i)
{
	if (full()) {   //overflow
		cerr << "Can't push when size " << size() << " == capacity "
		<< stack_max_size << ".\n";
		exit(EXIT_FAILURE);
	}

	*p++ = i; 
}

//Pop a value off the stack.

int stack::pop()
{
	if (empty()) {                //underflow
		cerr << "Can't pop when size " << size() << " == 0.\n";
		exit(EXIT_FAILURE);
	}
	
	return *--p;
}
