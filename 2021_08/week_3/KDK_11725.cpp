//#include <vector>
//#include <string>
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//bool chk[100001];
//vector<int> graph[100001]; // 사용 인덱스 : 1~100000
//
//int main() {
//	int n; // 노드의 개수
//	cin >> n;
//
//
//	for (int i = 0; i < n - 1; i++) {
//		int a, b;
//		cin >> a >> b;
//		graph[a].push_back(b);
//		graph[b].push_back(a);
//	}
//
//	// BFS 탐색
//	int* answer = new int[n + 1]; // 사용 인덱스 : 1~n
//
//	queue<int> q;
//	q.push(1);
//	chk[1] = true;
//
//	while (!q.empty()) {
//		int x = q.front();
//		q.pop();
//
//		for (int i = 0; i < graph[x].size(); i++) {
//			if (!chk[graph[x][i]]) {
//				q.push(graph[x][i]);
//				chk[graph[x][i]] = true;
//				answer[graph[x][i]] = x;
//			}
//		}
//	}
//
//	for (int i = 2; i <= n; i++) {
//		cout << answer[i] << '\n';
//	}
//}
