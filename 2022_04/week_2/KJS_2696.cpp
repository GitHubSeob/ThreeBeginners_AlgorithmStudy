//문제풀이: https://githubseob.tistory.com/178

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), M(0);
	int idx(0), idx2(0), num(0);
	cin >> T;

	while (T--) {
		cin >> M;
		multiset<int>ms;
		multiset<int>::iterator iter;
		vector<int>answer;

		for (idx = 0; idx < M; ++idx) {
			cin >> num;
			ms.insert(num);
			iter = ms.begin();
			if (idx % 2 == 0) {
				for (idx2 = 0; idx2 < ms.size() / 2; ++idx2) {
					iter++;
				}
				answer.push_back(*iter);
			}
		}
		cout << answer.size() << '\n';
		for (idx = 0; idx < answer.size(); ++idx) {
			cout << answer[idx] << ' ';
		}
		cout << '\n';
	}

}