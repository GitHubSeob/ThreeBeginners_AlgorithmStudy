#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N = 0, C = 0;
	

	cin >> N >> C;

	vector<int>house;
	for (int i=0; i < N; ++i)
		cin >> house[i];
	sort(house.begin(), house.end());                       

	int left = 0, right = house[N - 1];

	while (left <= right) {
		int wifi = 1;
		int pre_idx = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i < N; i++) {
			if (house[i] - house[i-1] >= mid) {
				wifi++;
			}
		}
		if (wifi >= C)
			left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
}
