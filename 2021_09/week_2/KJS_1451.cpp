//문제풀이: https://githubseob.tistory.com/88

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>value;
int N, M;
long long answer;

void Div3(long long mul, vector<vector<bool>>visit) {
	int y = 0, x = 0;
	long long sum = 0;

	for (y = 0; y < N; ++y)
		for (x = 0; x < M; ++x)
			if (!visit[y][x])
				sum += value[y][x];

	answer = max(answer, mul * sum);
}

void Div2(long long mul, int s_y, int s_x, int e_y, int e_x, vector<vector<bool>>visit) {
	int y = 0, x = 0;
	long long sum = 0;
	for (y = s_y; y <= e_y; ++y)
		for (x = s_x; x <= e_x; ++x)
			if (!visit[y][x]) {
				sum += value[y][x];
				visit[y][x] = true;
			}

	Div3(mul * sum, visit);
}

void Div1(int s_y, int s_x, int e_y, int e_x, vector<vector<bool>>& visit) {
	int y = 0, x = 0;
	long long sum = 0;
	for (y = s_y; y <= e_y; ++y) {
		for (x = s_x; x <= e_x; ++x) {
			sum += value[y][x];
			visit[y][x] = true;
		}
	}
	if (e_y == N - 1 && e_x < M - 1) {
		for (y = 0; y < N - 1; ++y)
			Div2(sum, 0, e_x + 1, y, M - 1, visit);
		for (x = e_x + 1; x < M - 1; ++x)
			Div2(sum, 0, e_x + 1, N - 1, x, visit);
	}
	else if (e_x == M - 1 && e_y < N - 1) {
		for (x = 0; x < M - 1; ++x)
			Div2(sum, e_y + 1, 0, N - 1, x, visit);
		for (y = e_y + 1; y < N - 1; ++y)
			Div2(sum, e_y + 1, 0, y, M - 1, visit);
	}
	else {
		Div2(sum, 0, e_x + 1, e_y, M - 1, visit);
		Div2(sum, e_y + 1, 0, N - 1, e_x, visit);
	}
}

void Div() {
	int y = 0, x = 0;
	for (y = 0; y < N; ++y) {
		for (x = 0; x < M; ++x) {
			vector<vector<bool>>visit(N, vector<bool>(M, false));
			Div1(0, 0, y, x, visit);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	value = vector<vector<int>>(N, vector<int>(M, 0));

	int y = 0, x = 0;
	for (y = 0; y < N; ++y) {
		string num = "";
		cin >> num;
		for (x = 0; x < M; ++x) {
			value[y][x] = num[x] - '0';
		}
	}
	Div();

	cout << answer;
}