//문제풀이: https://githubseob.tistory.com/91

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool>visit(100001, false);
int K;

void Move(int x, int sec) {
	queue<pair<int, int>> q;
	q.push({ x,sec });
	while (!q.empty()) {
		x = q.front().first;
		sec = q.front().second;
		q.pop();
		if (x == K) {
			cout << sec;
			return;
		}		
		else if (!visit[x]) {
			visit[x] = true;
			if (x * 2 <= 100000 && x < K)
				q.push({ x * 2,sec + 1 });
			if (x < K)
				q.push({ x + 1,sec + 1 });
			if (x > 0)
				q.push({ x - 1,sec + 1 });
		}
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N >> K;
	Move(N, 0);
}