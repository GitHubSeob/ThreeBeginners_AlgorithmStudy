#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int sum;
vector <int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	vector<bool> isPrime(N + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		if (isPrime[i]) {
			v.push_back(i);
		}
	}
	int sum(0);
	int result(0);
	int start(0);
	int end(0);
	while (end <= v.size()) {
		if (sum >= N) {
			if (sum == N)
				++result;
			sum -= v[start];
			++start;
		}
		else {
			sum += v[end];
			++end;
		}
	}
	cout << result;
}