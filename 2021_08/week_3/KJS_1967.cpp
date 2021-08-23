//문제풀이: https://githubseob.tistory.com/27

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V;
vector<pair<int, int>>tree[10001];
vector<bool>visit;
int max_dist;

void Move(int start, int distance) {
	visit[start] = true;
	for (int cnt = 0; cnt < tree[start].size(); ++cnt) {
		int next_node = tree[start][cnt].first;
		int next_dist = distance + tree[start][cnt].second;
		if (!visit[next_node] && tree[next_node].size() != 0) {
			visit[next_node] = true;
			max_dist = max(max_dist, next_dist);
			Move(next_node, next_dist);			
		}		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0;
	int current_node = 0;
	int linked_node = 0;
	int num = 0;

	cin >> V;

	for (y = 1; y < V; ++y) {
		cin >> current_node;
		cin >> linked_node;
		cin >> num;
		tree[current_node].push_back({ linked_node, num });
		tree[linked_node].push_back({ current_node, num });
	}

	visit = vector<bool>(V + 1, 0);
	for (y = 1; y <= V; ++y) {
		if (tree[y].size() == 1) {
			fill(visit.begin(), visit.end(), 0);
			Move(y, 0);
			tree[y].resize(0);
		}
	}
	cout << max_dist;
}