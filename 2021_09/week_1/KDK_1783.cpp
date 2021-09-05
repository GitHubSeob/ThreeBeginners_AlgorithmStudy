#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int n, m, count;
	cin >> n >> m;
	if (n == 1)
		count = 1;
	else if (n == 2) {
		count = min(4, (m + 1) / 2); //m7이하일 경우 
	}
	else if (n >= 3) {
		if (m >= 7) {
			count = m - 2;
		}
		else if (m < 7) {
			count = m <= 4 ? m : 4;
		}
	}
	cout << count;
}
