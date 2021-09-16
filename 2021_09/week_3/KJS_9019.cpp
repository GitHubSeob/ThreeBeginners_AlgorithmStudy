//문제풀이: https://githubseob.tistory.com/112

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int Left(int num) {
	if (num < 1000)
		return num * 10;
	else {
		num *= 10;
		num += (num / 10000);
		return num % 10000;
	}
}

int Right(int num) {
	if (num < 1000) {
		int n_num = num % 10;
		num /= 10;
		num += (n_num * 1000);
	}
	else {
		int n_num = num / 10;
		num = (num % 10) * 1000;
		return n_num + num;
	}
}

void BFS(int num1, int num2, vector<bool>visit) {
	int D = 0, S = 0, L = 0, R = 0;
	int n_num = 0;
	string DSLR = "";
	visit[num1] = true;
	queue<pair<int, string>>q;
	q.push({ num1, "" });
	while (!q.empty()) {
		n_num = q.front().first;
		DSLR = q.front().second;
		q.pop();

		D = (2 * n_num) % 10000;
		S = n_num - 1;
		if (S < 0) S = 9999;
		L = Left(n_num);
		R = Right(n_num);

		if (D == num2) {
			cout << DSLR + 'D' << '\n';
			return;
		}
		else if (S == num2) {
			cout << DSLR + 'S' << '\n';
			return;
		}
		else if (L == num2) {
			cout << DSLR + 'L' << '\n';
			return;
		}
		else if (R == num2) {
			cout << DSLR + 'R' << '\n';
			return;
		}
		if (!visit[D]) {
			visit[D] = true;
			q.push({ D, DSLR + 'D' });
		}
		if (!visit[S]) {
			visit[S] = true;
			q.push({ S, DSLR + 'S' });
		}
		if (!visit[L]) {
			visit[L] = true;
			q.push({ L, DSLR + 'L' });
		}
		if (!visit[R]) {
			visit[R] = true;
			q.push({ R, DSLR + 'R' });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	cin >> T;
	vector<bool>visit(10000, false);
	while (T--) {
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		if (num1 == num2) cout << "\n";
		BFS(num1, num2, visit);
	}
}