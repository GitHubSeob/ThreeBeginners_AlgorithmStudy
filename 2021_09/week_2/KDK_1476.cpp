#include <iostream>
using namespace std;
int main() {

	int e,s,m;
	int year = 1;
	int result;

	cin >> e >> s >> m;

	while (1) {
		if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0)
		{
			result = year;
			break;
		}
		year++;
	}
	cout << year << endl;
}