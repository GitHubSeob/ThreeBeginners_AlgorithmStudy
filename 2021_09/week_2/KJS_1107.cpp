//문제풀이: https://githubseob.tistory.com/87

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<bool>button(10, true);

int GetSize(int num) {
	int len = 1;
	while (num / 10 > 0) {
		num /= 10;
		++len;
	}
	return len;
}

bool Check(int num) {
	if (num == 0 && button[0] == false)
		return false;
	while (num > 0) {
		if (button[num % 10] == false) {
			return false;
		}
		num /= 10;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, M = 0;
	int idx = 0;
	int num = 0;

	cin >> N >> M;

	for (idx = 0; idx < M; ++idx) {
		cin >> num;
		button[num] = false;
	}

	int answer = abs(N - 100);
	int start = 0;

	if (GetSize(N) > 2) start = pow(10, GetSize(N) - 2);
	int end = pow(10, GetSize(N) + 1);
	end = min(end, 1000001);

	for (idx = start; idx < end; ++idx) {
		if (abs(N - idx) + GetSize(idx) >= answer) continue;
		else if (Check(idx))
			answer = abs(N - idx) + GetSize(idx);
	}
	cout << answer;
}