#include <cmath>
#include <iostream>

using namespace std;

class Time
{
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
public:

	Time();

	void changePlusPlus();

	void changeMinusMinus();

	Time operator++(int);

	Time operator--(int);

	friend Time& operator++(Time& time);

	friend Time& operator--(Time& time);

	friend ostream& operator << (ostream& s, Time& time);
};