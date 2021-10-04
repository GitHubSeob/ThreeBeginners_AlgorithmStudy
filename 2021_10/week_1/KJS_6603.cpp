//문제풀이: https://githubseob.tistory.com/125

#include <iostream>
#include <vector>
using namespace std;

int num;
vector<int>answer(6, 0);
vector<int>lotto;

void DFS(int idx, int cnt) {
	int idx2(0);
	if (cnt == 6) {
		for (idx2 = 0; idx2 < 6; ++idx2)
			cout << answer[idx2] << ' ';
		cout << '\n';
		return;
	}
	if (idx + 1 < num) {
		answer[cnt] = lotto[idx + 1];
		DFS(idx + 1, cnt + 1);
		DFS(idx + 1, cnt);
	}
}

int main() {
	int idx(0);
	while (1) {
		cin >> num;
		if (num == 0) break;
		lotto = vector<int>(num, 0);

		for (idx = 0; idx < num; ++idx)
			cin >> lotto[idx];

		answer[0] = lotto[0];
		DFS(0, 1);
		DFS(0, 0);
		cout << '\n';
	}
}