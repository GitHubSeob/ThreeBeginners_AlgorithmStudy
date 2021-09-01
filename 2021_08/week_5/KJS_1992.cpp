//문제풀이: https://githubseob.tistory.com/58

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>quad;

void Divide(int y, int x, int size) {
	if (size == 1)
		cout << quad[y][x];
	else {
		int prev_y = y;
		int prev_x = x;
		int max_value = 0;
		int min_value = 0;
		for (y; y < prev_y + size; ++y) {
			int prev_min = min_value;
			int prev_max = max_value;
			max_value = *max_element(quad[y].begin() + x, quad[y].begin() + x + size);
			min_value = *min_element(quad[y].begin() + x, quad[y].begin() + x + size);

			if (y != prev_y && (max_value != min_value || max_value != prev_max || min_value != prev_min)) {
				cout << "(";
				Divide(prev_y, prev_x, size / 2);
				Divide(prev_y, prev_x + size / 2, size / 2);
				Divide(prev_y + size / 2, prev_x, size / 2);
				Divide(prev_y + size / 2, prev_x + size / 2, size / 2);
				cout << ")";
				break;
			}
		}
		if (y == prev_y + size)
			cout << quad[y - 1][x];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	quad = vector<vector<int>>(N, vector<int>(N, 0));
	int y = 0, x = 0;

	for (y = 0; y < N; ++y) {
		string num = "";
		cin >> num;
		for (x = 0; x < N; ++x)
			quad[y][x] = num[x] - '0';
	}
	Divide(0, 0, N);
}