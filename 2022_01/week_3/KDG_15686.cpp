#include<iostream>
#include<algorithm>
#include<vector>
#include <math.h>
using namespace std;
#define max 50000;
vector <pair<int, int>>chicken, home, v1;
int city[51][51];
int N, M;
bool viseted[13];
int result = max;

int dist() {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int hx = home[i].first;
		int hy = home[i].second;
		int mind = max;

		for (int j = 0; j < v1.size(); j++) {
			int cx = v1[j].first;
			int cy = v1[j].second;
			int d = abs(hx - cx) + abs(hy - cy);
			mind = min(mind, d);
		}
		sum += mind;
	}
	return sum;
}
void visit(int idx,int cnt) {
	
	if (cnt == M) {
		result = min(result, dist());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (viseted[i])
			continue;
		viseted[i] = true;
		v1.push_back(chicken[i]);
		visit(i, cnt + 1);
		viseted[i] = false;
		v1.pop_back();
	}
}
void Solve() {
	visit(0, 0);
	cout << result;
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			else if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
		}
	}
	Solve();

}