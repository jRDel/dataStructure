// C++ program to find angle between hour and minute hands
#include <iostream>
using namespace std;

int calcAngle(double hours, double minutes)
{
	if(hours<0 || hours>12 || minutes<0 || minutes>60){
		return -1;
	}
	if(minutes==60){
		minutes=0;
		hours=hours+1;
		if(hours>12){
			hours-=12;
		}
	}
	if(hours==12){
		hours=0;
	}
	int h = .5*(hours*60+minutes);
	int m = 6*minutes;

	int result = abs(h-m);

	if(result>180){
		return 360-result;
	}
	else{
		return result;
	}
}

// Driver Code
int main()
{
	cout << calcAngle(12, 60) << endl;
	cout << calcAngle(3, 30) << endl;
	return 0;
}

