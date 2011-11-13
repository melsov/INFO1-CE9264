#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

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