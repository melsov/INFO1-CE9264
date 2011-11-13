#ifndef DATEH
#define DATEH

using namespace std;

class date {
	int day;
public:
	date(int initial_month, int initial_day, int initial_year);
	void next(int count = 1) {day += count;}    //Go count days forward.
	void print() const;
	int julian() const;
};
#endif