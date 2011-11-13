#ifndef DATEH
#define DATEH

/* Matthew Poindexter HW 2.4 a/b and 2.5 a for CPP part I */

using namespace std;

class date {
	int day;
	void init(int _month, int _day, int _year);
public:
	date(int initial_month, int initial_day, int initial_year);
	date();
	void next(int count = 1) {day += count;}    //Go count days forward.
	void print() const;
	int julian() const;
};
#endif
