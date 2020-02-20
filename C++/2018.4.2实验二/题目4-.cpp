#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
public:
	Time(int h= 0, int m= 0, int s= 0) {} // default constructor

									 // set functions (the Time & return types enable cascading)
	Time &setTime(int, int, int); // set hour, minute, second
	Time &setHour(int); // set hour
	Time &setMinute(int); // set minute
	Time &setSecond(int); // set second				
	void printUniversal() const; // print universal time
	void printStandard() const; // print standard time
private:
	int totalSeconds; // number of seconds since midnight
}; // end class Time
Time &Time::setHour(int h) {
	if (h >= 0 && h < 24) {totalSeconds = h * 3600;}
	else cout << "不合法";
	return *this;
}
Time &Time::setMinute(int m) {
	if (m >= 0 && m < 60){totalSeconds += m * 60;}
	else cout << "不合法";
	return *this;
}
Time &Time::setSecond(int s) {
	if (s >= 0 && s < 60) { totalSeconds += s; }
	else cout << "不合法";
		return *this;
}
Time &Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this;
}
void Time::printUniversal() const {
	int hour = totalSeconds / 3600;
	int minute=(totalSeconds-hour*3600)/60;
	int second = totalSeconds % 60;
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) 
		<< minute << ":" << setw(2) << second << endl;
}
void Time::printStandard() const {
	int hour = totalSeconds / 3600;
	int minute = (totalSeconds - hour * 3600) / 60;
	int second = totalSeconds % 60;
	cout<<((hour==0||hour==12)?12:hour%12)<<":"<<setfill('0') << setw(2) 
		 << minute << ":" << setw(2) << second <<(hour<12?"AM":"PM")<< endl;
}

int main()
{
	Time t;
	t.setHour(18).setMinute(30).setSecond(22);
	// output time in universal and standard formats
	cout << "Universal time: ";
	t.printUniversal();
	cout << "\nStandard time: ";
	t.printStandard();
	cout << "\n\nNew standard time: ";
	// cascaded function calls
	t.setTime(20, 20, 20).printStandard();
	cout << endl;
	system("pause");
	return 0;
}

