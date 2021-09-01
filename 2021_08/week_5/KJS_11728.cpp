//문제풀이: https://githubseob.tistory.com/56

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A_cnt = 0;
	int B_cnt = 0;
	int idx = 0;

	cin >> A_cnt;
	cin >> B_cnt;
	vector<int>Arr(A_cnt + B_cnt, 0);

	for (int idx = 0; idx < A_cnt + B_cnt; ++idx)
		cin >> Arr[idx];

	sort(Arr.begin(), Arr.end());

	for (idx = 0; idx < Arr.size(); ++idx)
		cout << Arr[idx] << " ";
}