//문제풀이: https://githubseob.tistory.com/133

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0);

	cin >> N;
	vector<long long>A(N, 0);
	vector<long long>B(N, 0);
	vector<long long>C(N, 0);
	vector<long long>D(N, 0);

	int idx1(0), idx2(0);
	for (idx1 = 0; idx1 < N; ++idx1)
		cin >> A[idx1] >> B[idx1] >> C[idx1] >> D[idx1];

	vector<long long>sumAB(N * N, 0);
	vector<long long>sumCD(N * N, 0);

	int idx3(0);
	for (idx1 = 0; idx1 < N; ++idx1)
		for (idx2 = 0; idx2 < N; ++idx2) {
			sumAB[idx3] = A[idx1] + B[idx2];
			idx3++;
		}

	idx3 = 0;
	for (idx1 = 0; idx1 < N; ++idx1)
		for (idx2 = 0; idx2 < N; ++idx2) {
			sumCD[idx3] = C[idx1] + D[idx2];
			idx3++;
		}

	sort(sumAB.begin(), sumAB.end());
	sort(sumCD.begin(), sumCD.end());

	long long answer(0);

	for (idx1 = 0; idx1 < sumAB.size(); ++idx1)
		answer += (upper_bound(sumCD.begin(), sumCD.end(), -sumAB[idx1]) -
			lower_bound(sumCD.begin(), sumCD.end(), -sumAB[idx1]));

	cout << answer;
}