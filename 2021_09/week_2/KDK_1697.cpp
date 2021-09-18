#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

bool visit[1000000] = { false };
using namespace std;

void bfs(int start, int m) {
    queue < pair<int, int>> q;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        int first1 = q.front().first; //start의 현재위치
        int second2 = q.front().second; //시간
        if (first1 == m) {
            cout << q.front().second;
            return; //시간값 출력 
        }
        q.pop();
        visit[first1] = true;
        if (!visit[first1 + 1] && first1 < 100000) {
            q.push(make_pair(first1 + 1, second2 + 1));
        }
        if (!visit[first1 - 1] && first1 > 0) {
            q.push(make_pair(first1 - 1, second2 + 1));
        }
        if (!visit[first1 * 2] && first1 <= 50000) {
            q.push(make_pair(first1 * 2, second2 + 1));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    bfs(n, m);
}