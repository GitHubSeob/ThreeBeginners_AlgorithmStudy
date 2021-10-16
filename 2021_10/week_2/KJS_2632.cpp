//문제풀이: https://githubseob.tistory.com/131

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int idx1(0), idx2(0);
	int m(0), n(0);
	int slice(0);

	cin >> slice;
	cin >> m >> n;

	unordered_map<int, int>pick;
	vector<int>A_pizza(m, 0);
	vector<int>B_pizza(n, 0);
	long long answer(0);

	for (idx1 = 0; idx1 < m; ++idx1)
		cin >> A_pizza[idx1];

	for (idx2 = 0; idx2 < n; ++idx2)
		cin >> B_pizza[idx2];

	int sum(0);

	int sum_A(accumulate(A_pizza.begin(), A_pizza.end(), 0));
	int sum_B(accumulate(B_pizza.begin(), B_pizza.end(), 0));

	if (sum_A == slice) answer++;
	else pick[sum_A]++;

	for (idx1 = 0; idx1 < m; ++idx1) {
		sum = 0;
		idx2 = idx1;
		while (!(idx2 / m == 1 && idx2 % m == idx1)) {
			sum += A_pizza[idx2 % m];
			if (sum > slice) break;
			else if (sum != sum_A) {
				if (sum == slice) {
					answer++;
					break;
				}
				else pick[sum]++;
			}
			++idx2;
		}
	}
	if (sum_B == slice) answer++;
	else answer += pick[slice - sum_B];

	for (idx1 = 0; idx1 < n; ++idx1) {
		sum = 0;
		idx2 = idx1;
		while (!(idx2 / n == 1 && idx2 % n == idx1)) {
			sum += B_pizza[idx2 % n];
			if (sum > slice) break;
			else if (sum != sum_B) {
				if (sum == slice) answer++;
				else answer += pick[slice - sum];
			}
			++idx2;
		}
	}

	cout << answer;
}