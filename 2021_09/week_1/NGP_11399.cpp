#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> number;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n, tmp, sum = 0, min = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		number.push_back(tmp);
	}

	sort(number.begin(), number.end());

	for (int i = 0; i < number.size();i++) {
		sum += number[i];
		min += sum;
	}

	cout << min;
}