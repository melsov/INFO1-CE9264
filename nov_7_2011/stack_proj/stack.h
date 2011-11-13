#ifndef STACKH       //C++ example
#define STACKH
#include <cstddef>   //for size_t

/* Matthew Poindexter. HW 2.6 a/b for CPP part I */

const size_t stack_max_size = 100;

class stack {
	int a[stack_max_size];
	int* p;
public:
	stack() {p = a;}   //constructor: start with the stack empty
	stack(const stack& another);
	~stack();          //destructor
	
	void push(int i);
	int pop();         //C++ doesn't need the keyword void
	bool empty() const {return p == a;}  
	bool full() const {return p == &a[stack_max_size];}
	size_t size() const {return p - a;}
};
#endif
