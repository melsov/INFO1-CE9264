#ifndef WOLFH
#define WOLFH
#include "terminal.h"

class wolf {
	const terminal *t;
	unsigned x, y;
	static const char c = 'w';
public:
	wolf(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
	~wolf();
	wolf(const wolf& another);  //DELIBERATELY EMPTY	
	bool move();
};
#endif