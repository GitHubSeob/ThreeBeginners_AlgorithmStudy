//문제풀이: https://githubseob.tistory.com/57

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>paper;
vector<int>cnt(3, 0);

void Divide(int y, int x,int size) {
	if (size == 1)
		cnt[paper[y][x] + 1]++;
	else {
		int prev_y = y;
		int prev_x = x;
		int max_value = 0;
		int min_value = 0;
		for (y; y < prev_y + size; ++y) {
			int prev_min = min_value;
			int prev_max = max_value;
			max_value = *max_element(paper[y].begin() + x, paper[y].begin() + x + size);
			min_value = *min_element(paper[y].begin() + x, paper[y].begin() + x + size);

			if (y != prev_y && (max_value != min_value || max_value != prev_max || min_value != prev_min)) {
				Divide(prev_y, prev_x, size / 3);
				Divide(prev_y + size / 3, prev_x, size / 3);
				Divide(prev_y + 2 * size / 3, prev_x, size / 3);

				Divide(prev_y, prev_x + size / 3, size / 3);
				Divide(prev_y + size / 3, prev_x + size / 3, size / 3);
				Divide(prev_y + 2 * size / 3, prev_x + size / 3, size / 3);

				Divide(prev_y, prev_x + 2 * size / 3, size / 3);
				Divide(prev_y + size / 3, prev_x + 2 * size / 3, size / 3);
				Divide(prev_y + 2 * size / 3, prev_x + 2 * size / 3, size / 3);
				break;
			}
		}
		if (y == prev_y + size)
			cnt[paper[prev_y][prev_x] + 1]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	paper = vector<vector<int>>(N, vector<int>(N, 0));
	int y = 0, x = 0;

	for (y = 0; y < N; ++y)
		for (x = 0; x < N; ++x)
			cin >> paper[y][x];

	Divide(0, 0, N);
	for (int idx = 0; idx < 3; idx++)
		cout << cnt[idx] << "\n";
}