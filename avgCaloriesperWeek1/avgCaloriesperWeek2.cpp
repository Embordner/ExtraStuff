// The Point of this program is a While loop for average number of calories burned in a week.

#include <iostream>

using namespace std;

int main()
{
	int calBurnedInADay;                                                                       // int = interger values so no decimal places
	int calBurnedInAWeek;
	int day;

	int calEatenInADay;
	int calEatenInAWeek;
	int day2;
	
	day = 1;
	calBurnedInAWeek = 0;

	calEatenInAWeek = 0;
	day2 = 1;
	

		while (day <= 7)                                                                           // this WHILE loop will continue the day equals 7
		{
			cout << "Enter calories burned in day " << day << ": ";                              // cout is the output that will show up / think of it as a message to user
			cin >> calBurnedInADay;                                                               // cin is the input by the user 
			cout << endl;

			calBurnedInAWeek = calBurnedInAWeek + calBurnedInADay;
			day = day + 1;

		}
		&& 
		while (day2 <= 7)
		{
			cout << "Enter calories eaten on day " << day2 << ": ";
			cin >> calEatenInADay;
			cout << endl;

			calEatenInAWeek = calEatenInAWeek + calEatenInADay;
			day2 = day2 + 1;
		}
	cout << "Average number of calories burned each day: " << calBurnedInAWeek / 7 << endl; 
	cout << "Average number of calories eaten each day: " << calEatenInAWeek / 7 << endl; // this contains average calories formula
	return 0; 
}
