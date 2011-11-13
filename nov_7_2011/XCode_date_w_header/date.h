#ifndef DATEH
#define DATEH

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