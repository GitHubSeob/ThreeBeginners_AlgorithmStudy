#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void bfs(int x, int y, int z);
vector<int> ans;
bool visited[200][200];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	//memset(visited, 0, sizeof(visited)); -> 전역변수는 애초에 bool 함수들을 false로 초기화하니 앞으로 이것도 필요할때만 적자.

	bfs(a, b, c);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}


void bfs(int x, int y, int z) {
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(0, 0),z));

	while (!q.empty()) {
		int first = q.front().first.first;
		int second = q.front().first.second;
		int third = q.front().second;
		q.pop();

		//1963에서 참조했던 continue를 쓰는게 편하는걸 배웠으면 활용.
		if (visited[first][second]==true)continue;
		visited[first][second] = true;

		if (first == 0) 
			ans.push_back(third);
		
		//저번 시간 진섭이가 bfs시간 줄이기로 조건을 먼저 걸고 시행하는것이 더 빠른다는 것을 생각해서 구성해보자.
		//1)a->b 2)b->a 3)a->c 4)c->a 5)b->c 6)c->b인 여섯가지 상황을 합이 클때와 작을때로 구분해서 12가지를 적으면 될듯싶다.
		
		//1)
		if (first + second > y)
			q.push(make_pair(make_pair(first + second - y, y), third));
		else
			q.push(make_pair(make_pair(0, first + second), third));

		//2)
		if (first + second > x)
			q.push(make_pair(make_pair(x, first + second - x), third));
		else
			q.push(make_pair(make_pair(first + second, 0), third));

		//3)
		if (first + third > z)
			q.push(make_pair(make_pair(first + third - z, second), z));
		else
			q.push(make_pair(make_pair(0, second), first + third));

		//4)
		if (first + third > x)
			q.push(make_pair(make_pair(x, second), first + third - x));
		else
			q.push(make_pair(make_pair(first + third, second), 0));

		//5)
		if (second + third > z)
			q.push(make_pair(make_pair(first, second + third - z), z));
		else
			q.push(make_pair(make_pair(first, 0), second + third));

		//6)
		if (second + third > y)
			q.push(make_pair(make_pair(first, y), second + third - y));
		else
			q.push(make_pair(make_pair(first, second + third), 0));

	}
}
