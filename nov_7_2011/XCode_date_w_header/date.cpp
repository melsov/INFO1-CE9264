#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"
using namespace std;

/* Matthew Poindexter.  HW 2.4 a/b and 2.5 a for CPP part I */

const int date_length[] = {
	0,   //dummy element so that January will have subscript 1
	31,   //January
	28,   //February
	31,   //March
	30,   //April
	31,   //May
	30,   //June
	31,   //July
	31,   //August
	30,   //September
	31,   //October
	30,   //November
	31    //December
};

date::date(int initial_month, int initial_day, int initial_year)
{
	init(initial_month, initial_day, initial_year);
}

date::date()
{
	const time_t t = time(0);
	
	if (t==static_cast<time_t> (-1)) {
		cout << "Setting the day to January 1 in the year 0 because time failed";
		init(1, 1, 0);
	}
	
	const tm *const p = localtime(&t);
	
	init(p->tm_mon + 1, p->tm_mday, p->tm_year + 1900);
}

void date::init(int initial_month, int initial_day, int initial_year)
{
	if (initial_month < 1 || initial_month > 12) {
		cerr << "bad month " << initial_month << "/" << initial_day
		<< "/" << initial_year << "\n";
		exit(EXIT_FAILURE);
	}
	
	if (initial_day < 1 || initial_day > date_length[initial_month]) {
		cerr << "bad day " << initial_month << "/" << initial_day
		<< "/" << initial_year << "\n";
		exit(EXIT_FAILURE);
	}
	
	day = initial_year * 365;
	
	for (day += initial_day; --initial_month > 0; day += date_length[initial_month]) {
	}
	
}

void date::print() const
{
	const div_t d = div(day, 365);
	int year = d.quot;
	int j = d.rem;
	
	if (j <= 0) {
		j += 365;
		--year;
	}
	
	int m = 1;
	
	for (; j > date_length[m]; ++m) {
		j -= date_length[m];
	}
	
	cout << m << "/" << j << "/" << year;
}

int date::julian() const
{
	int j = day % 365;
	if (j <= 0) {
		j+= 365;
	}
	return j;
}
