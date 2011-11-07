#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;



class weather {
	float at;
	float wsp;
	float rh;

public:
	weather(float air_temperature, float wind_speed, float relative_humidity);
	float wind_chill_heat_index();
	float wind_chill();
	float heat_index();
};

int main()
{
	weather w( 34, 45, 2);
	
	cout << "If the air temp is above 50 F this program will return the heat index.\n If below 50 F, the wind chill\n";
	cout << w.wind_chill_heat_index() ;
	
	return EXIT_SUCCESS;
}

weather::weather(float air_temperature, float wind_speed, float relative_humidity)
{
	if (air_temperature < -459.67 )
	{
		cerr << "The temperature " << air_temperature << " is below zero kelvin.";
		exit(EXIT_FAILURE);
	}
	else if (air_temperature > 170 )
	{
		cerr << "Impossibly high temperature! ";
		exit(EXIT_FAILURE);
	}
	
	if (relative_humidity > 100 || relative_humidity < 0)
	{
		cerr << "Bad humidity number: " << relative_humidity;
		exit(EXIT_FAILURE);
	}
	if (wind_speed < 0)
	{
		cerr << "Bad wind speed" << wind_speed;
		exit(EXIT_FAILURE);
	}
	at = air_temperature;
	wsp = wind_speed;
	rh = relative_humidity;
}

float weather::wind_chill_heat_index()
{
	if (at > 50){
		float hi = heat_index();
		cout << "The heat index is " << hi;
		return heat_index();
	}
	else{
		float wc = wind_chill();
		cout << "The wind chill is " << wc;
		return wind_chill();
	}
}

float weather::wind_chill()
{
	return 35.74 + .6215*at - 35.75 * pow(wsp, .16) + .4275*at*pow(wsp, .16);
}

float weather::heat_index()
{
	float hi = -42.38 + 2.04*at + 10.14*rh + -.2248*rh*at + -.006838*at*at + -.005482*rh*rh + .000122*at*at*rh + .00008528*at*rh*rh + .000000199* at*at*rh;
	return hi;
}
