//문제풀이: https://githubseob.tistory.com/114

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>>visit;
vector<int>answer = { 1,2,3,4,5,6,7,8,0 };

void CanPush(queue<pair<vector<int>, int>>& q, vector<int>puzzle, int num1, int num2, int cnt) {
	swap(puzzle[num1], puzzle[num2]);
	if (puzzle == answer) {
		cout << cnt + 1;
		exit(0);
	}
	else if (visit.find(puzzle) == visit.end()) {
		visit.insert(puzzle);
		q.push({ puzzle,cnt + 1 });
	}
}

void BFS(vector<int>input) {
	queue<pair<vector<int>, int>>q;
	q.push({ input,0 });
	visit.insert(input);
	vector<int>puzzle;
	int cnt = 0;
	while (!q.empty()) {
		puzzle = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (puzzle[0] == 0) {
			CanPush(q, puzzle, 1, 0, cnt);
			CanPush(q, puzzle, 3, 0, cnt);
		}
		else if (puzzle[1] == 0) {
			CanPush(q, puzzle, 0, 1, cnt);
			CanPush(q, puzzle, 4, 1, cnt);
			CanPush(q, puzzle, 2, 1, cnt);
		}
		else if (puzzle[2] == 0) {
			CanPush(q, puzzle, 1, 2, cnt);
			CanPush(q, puzzle, 5, 2, cnt);
		}
		else if (puzzle[3] == 0) {
			CanPush(q, puzzle, 0, 3, cnt);
			CanPush(q, puzzle, 4, 3, cnt);
			CanPush(q, puzzle, 6, 3, cnt);
		}
		else if (puzzle[4] == 0) {
			CanPush(q, puzzle, 1, 4, cnt);
			CanPush(q, puzzle, 3, 4, cnt);
			CanPush(q, puzzle, 5, 4, cnt);
			CanPush(q, puzzle, 7, 4, cnt);
		}
		else if (puzzle[5] == 0) {
			CanPush(q, puzzle, 2, 5, cnt);
			CanPush(q, puzzle, 4, 5, cnt);
			CanPush(q, puzzle, 8, 5, cnt);
		}
		else if (puzzle[6] == 0) {
			CanPush(q, puzzle, 3, 6, cnt);
			CanPush(q, puzzle, 7, 6, cnt);
		}
		else if (puzzle[7] == 0) {
			CanPush(q, puzzle, 4, 7, cnt);
			CanPush(q, puzzle, 6, 7, cnt);
			CanPush(q, puzzle, 8, 7, cnt);
		}
		else if (puzzle[8] == 0) {
			CanPush(q, puzzle, 5, 8, cnt);
			CanPush(q, puzzle, 7, 8, cnt);
		}
	}
	cout << "-1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int idx = 0;
	vector<int>puzzle(9, 0);
	for (idx = 0; idx < 9; ++idx)
		cin >> puzzle[idx];
	if (puzzle == answer) cout << "0";
	else BFS(puzzle);
}