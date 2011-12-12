#ifndef RABBITH
#define RABBITH
#include "terminal.h"

class rabbit {
	const terminal *t;
	unsigned x, y;
	static const char c = 'r';
public:
	rabbit(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
	~rabbit();
	rabbit(const rabbit& another);  //DELIBERATELY EMPTY
	bool move();
};
#endif