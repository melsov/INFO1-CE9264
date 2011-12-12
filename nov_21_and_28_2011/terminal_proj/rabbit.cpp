#include <iostream>
#include <cstdlib>   //for rand and exit functions
#include "rabbit.h"
using namespace std;

rabbit::rabbit(const terminal& initial_t, unsigned initial_x, unsigned initial_y)
{
	t = &initial_t;
	x = initial_x;
	y = initial_y;
	//c = 'r';
	
	if (!t->in_range(x, y)) {
		cerr << "Initial rabbit position (" << x << ", " << y
		<< ") off " << t->xmax() << " by " << t->ymax()
		<< " terminal.\n";
		exit(EXIT_FAILURE);
	}
	
	const char other = t->get(x, y);
	const char background = t->background();
	
	if (other != background) {
		cerr << "Initial rabbit position (" << x << ", " << y
		<< ") already occupied by '" << other << "'.\n";
		exit(EXIT_FAILURE);
	}
	
	if (c == background) {
		cerr << "Rabbit character '" << c << "' can't be the same as "
		"the terminal's background character.\n";
		exit(EXIT_FAILURE);
	}
	
	t->put(x, y, c);
}

rabbit::~rabbit()
{
	t->beep();
	t->wait(1000);
	if (c == t->get(x, y))
	{
		t->put(x, y);
	}	
}

rabbit::rabbit(const rabbit& another)
{
}

//Return false if this rabbit was eaten, true otherwise.

bool rabbit::move()
{
	//The values of dx and dy are either -1, 0, or 1.
	const int dx = rand() % 3 - 1;
	const int dy = rand() % 3 - 1;
	
	if (dx == 0 && dy == 0) {
		return true;   //This rabbit had no desire to move.
	}
	
	const unsigned newx = x + dx;
	const unsigned newy = y + dy;
	
	if (!t->in_range(newx, newy)) {
		return true;   //Can't move off the screen.
	}
	
	const char other = t->get(newx, newy);
	
	if (other != t->background()) {
		if (other == c) {
			//This rabbit collided with another rabbit.
			return true;
		} else {
			//This rabbit blundered into the wolf and was eaten.
			return false;
		}
	}
	
	t->put(x, y);      //Erase this rabbit from its old location.
	x = newx;
	y = newy;
	t->put(x, y, c);   //Redraw this rabbit at its new location.
	
	return true;
}