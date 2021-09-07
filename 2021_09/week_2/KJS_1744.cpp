//문제풀이: https://githubseob.tistory.com/85

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int idx = 0;
	cin >> N;
	vector<int>negative;
	vector<int>positive;
	
	int num = 0;
	for (idx = 0; idx < N; ++idx) {
		cin >> num;
		if (num <= 0) negative.push_back(num);
		else positive.push_back(num);
	}

	sort(positive.begin(), positive.end(), greater<>());
	sort(negative.begin(), negative.end());

	for (idx = 0; idx + 1 < negative.size(); idx += 2) {
		negative[idx] = negative[idx] * negative[idx + 1];
		negative[idx + 1] = 0;
	}

	for (idx = 0; idx + 1 < positive.size(); idx += 2) {
		if (positive[idx] > 1 && positive[idx + 1] > 1) {
			positive[idx] = positive[idx] * positive[idx + 1];
			positive[idx + 1] = 0;
		}
	}
	
	int answer = 0;
	for (idx = 0; idx < negative.size(); ++idx)
		answer += negative[idx];
	for (idx = 0; idx < positive.size(); ++idx)
		answer += positive[idx];

	cout << answer;
}