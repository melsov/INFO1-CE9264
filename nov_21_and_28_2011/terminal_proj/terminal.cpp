#include <iostream>
#include <cstdlib>
#include <cctype>   //for isprint
#include "terminal.h"
using namespace std;

terminal::terminal(char initial_background)
{
	_background = initial_background;
	
	term_construct();
	
	_xmax = term_xmax();
	_ymax = term_ymax();
	
	if (_background != ' ') {
		for (unsigned y = 0; y < _ymax; ++y) {
			for (unsigned x = 0; x < _xmax; ++x) {
				put(x, y);
			}
		}
	}
}

terminal::~terminal()
{
	for (unsigned y = 0; y < _ymax; ++y) {
		for (unsigned x = 0; x < _xmax; ++x) {
			put(x, y, ' ');
		}
	}
	
	term_destruct();
}

void terminal::put(unsigned x, unsigned y, char c) const
{
	if (isprint(static_cast<unsigned char>(c)) == 0) {
		cerr << "unprintable character "
		<< static_cast<unsigned>(static_cast<unsigned char>(c))
		<< ".\n";
		exit(EXIT_FAILURE);
	}
	
	check(x, y);
	term_put(x, y, c);
}

void terminal::put(unsigned x, unsigned y, const char *s) const
{
	for (; *s != '\0'; ++s) {
		put(x, y, *s);
		next(x, y);
	}
}

//Move to the next (x, y) position: left to right, top to bottom.
//Warning: will change the values of the arguments.

void terminal::next(unsigned& x, unsigned& y) const
{
	check(x, y);
	
	if (++x >= _xmax) {
		x = 0;
		if (++y >= _ymax) {
			cerr << "can't go to or beyond row " << _ymax << "\n";
			exit(EXIT_FAILURE);
		}
	}
}

void terminal::check(unsigned x, unsigned y) const
{
	if (!in_range(x, y)) {
		cerr << "coordinates (" << x << ", " << y
		<< ") must be >= (0, 0) and < ("
		<< _xmax << ", " << _ymax << ")\n";
		exit(EXIT_FAILURE);
	}
}