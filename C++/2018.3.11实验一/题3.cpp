#include<iostream>
#include<iomanip>
#include<stdexcept>
using namespace std;
class Time
{
public:
	Time(int hr, int min, int sec);
	void tickprint();

private:
	int hour, minute, second;
};

Time::Time(int hr, int min, int sec)
{
	if ((hr >= 0 && hr < 24) && (min >= 0 && min < 60) && (sec >= 0 && sec < 60)) {
		hour = hr; minute = min; second = sec;
	}
	else
	{
		cout << "输入不合法";
	}
}
void Time::tickprint() {
	for (int n = 0; n < 15; n++) {
		if (second < 60) {
			second++;
		}
		if (second == 60) {
			minute++; second = 0;
		}
		if (minute == 60) {
			hour++; minute = 0;
		}
		if (hour == 24) {
			hour = 0;
		}
		
			cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0')
				<< setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? "AM" : "PM") << endl;
		
		continue;
	}

}
int main() {
	int h, m, s;
	cin >> h >> m >> s;
	Time A(h, m, s);
	A.tickprint();
	system("pause");
	return 0;
}
