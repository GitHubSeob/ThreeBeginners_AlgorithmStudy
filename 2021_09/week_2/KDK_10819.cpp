#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int i = 0;
	int sum;
	cin >> N;
	vector<int>v(N, 0);

	for (i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());//(next_permutation 을 사용하기 위한 sort

	int answer = 0;
	do {
		for (i = 0; i < N - 1; ++i) {
			sum = 0;
			for (i = 0; i < N - 1; i++) {
				sum += abs(v[i] - v[i + 1]);
				answer = max(answer, sum);
			}
		}
	} while (next_permutation(v.begin(), v.end())); //순열 해주는거 개꿀;


	cout << answer;
}