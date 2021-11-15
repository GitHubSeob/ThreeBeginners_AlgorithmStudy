#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num(0), idx(0);
	cin >> num;	
	int sum(0);
	char number(' ');
	
	for (idx = 0; idx < num; ++idx) {
		cin >> number;
		sum += number-'0';
	}
	cout << sum;
}