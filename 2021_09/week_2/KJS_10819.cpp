//문제풀이: https://githubseob.tistory.com/89

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N = 0;
	int idx = 0;
	cin >> N;
	vector<int>arr(N, 0);
	for (idx = 0; idx < N; ++idx)
		cin >> arr[idx];
	sort(arr.begin(), arr.end());

	int answer = 0;
	int sum = 0;
	do {
		sum = 0;
		for (idx = 0; idx < N-1; ++idx)
			sum += abs(arr[idx] - arr[idx + 1]);		
		answer = max(answer, sum);
	}while(next_permutation(arr.begin(), arr.end()));

	cout << answer;
}