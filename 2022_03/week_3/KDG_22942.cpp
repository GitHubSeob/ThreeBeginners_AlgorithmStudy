#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), i(0), j(0);
	cin >> N;

	vector<pair<int, int>>arr(N, { 0,0 });
	int x(0), r(0);

	for (i = 0; i < N; ++i) {
		cin >> x >> r;
		arr[i].first = x - r;
		arr[i].second = x + r;
	}//x-r 내접 외접
	sort(arr.begin(), arr.end());

	for (i = 0; i + 1 < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (arr[i].first == arr[j].first) { //겹치면.?
				if (arr[i].second != arr[j].second) {
					cout << "NO";
					return 0;
				}
				else continue;
			}
			else if (arr[i].second < arr[j].first) {
				break;
			}
			else if (arr[j].second < arr[i].second) {
				continue;
			} //안에
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}