//문제풀이: https://githubseob.tistory.com/29

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0;
	int N = 0;
	int num1 = 0, num2 = 0;
	cin >> N;

	vector<vector<int>>tree(N + 1, vector<int>(0, 0));
	vector<int>parents(N + 1, 0);
	vector<bool>visit(N + 1, false);

	for (y = 1; y < N; ++y) {
		cin >> num1 >> num2;
		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}
	int num = 1;

	queue<int>q;
	q.push(1);

	while (!q.empty()) {
		visit[num] = true;
		num = q.front();
		q.pop();
		for (int cnt = 0; cnt < tree[num].size(); ++cnt) {
			if (!visit[tree[num][cnt]]) {
				parents[tree[num][cnt]] = num;
				q.push(tree[num][cnt]);
			}
		}
	}

	for (int i = 2; i <= N; ++i) {
		cout << parents[i] << "\n";
	}
}