//문제풀이: https://githubseob.tistory.com/132

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0);
	cin >> T;
	int N(0);
	int sum(0);
	int idx1(0), idx2(0);
	long long answer(0);
	cin >> N;
	unordered_map<int, int>sumA;
	vector<int>A(N, 0);
	for (idx1 = 0; idx1 < N; ++idx1)
		cin >> A[idx1];

	for (idx1 = 0; idx1 < N; ++idx1) {
		sum = 0;
		for (idx2 = idx1; idx2 < N; ++idx2) {
			sum += A[idx2];
			sumA[sum]++;
		}
	}

	cin >> N;
	vector<int>B(N, 0);

	for (idx1 = 0; idx1 < N; ++idx1)
		cin >> B[idx1];

	for (idx1 = 0; idx1 < N; ++idx1) {
		sum = 0;
		for (idx2 = idx1; idx2 < N; ++idx2) {
			sum += B[idx2];
			answer += sumA[T - sum];
		}
	}

	cout << answer;
}