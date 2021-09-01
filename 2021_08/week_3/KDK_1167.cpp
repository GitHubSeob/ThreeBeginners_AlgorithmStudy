#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;
int v, n, a, cost;

vector<pair<int, int>>tree[100002];
bool visit[100002] = { false, };
int dist = 0;
int parent = 0;

void dfs(int root, int cost) {
	if (visit[root])
		return;

	visit[root] = true;

	if (dist < cost)
	{
		dist = cost;
		parent = root;
	}

	for (int i = 0; i < tree[root].size(); i++)
		dfs(tree[root][i].first, cost + tree[root][i].second);


}

int main() {

	cin >> v;

	for (int i = 0; i < v; i++) {
		cin >> n; //Á¤Á¡
		while (1) {
			cin >> a; //Á¤Á¡
			if (a == -1)
				break;
			cin >> cost; // °£¼±ÀÇ cost

			tree[n].push_back({ a,cost });
		}
	}


	dfs(1, 0);

	memset(visit, false, sizeof(visit));

	dist = 0;

	dfs(parent, 0);

	cout << dist << endl;

	return 0;
}
