#include <iostream> 
#include <string>
#include <queue>
#include <map>
#include<algorithm>
bool check[202][202];
using namespace std;
vector<int>v;
int a, b, c;
void bfs() {
	queue<pair<pair<int, int>, int> >q;
	q.push(make_pair(make_pair(0, 0), c)); //ÃÊ±âÈ­.
	while (!q.empty()) {
		int check1 = q.front().first.first;
		int check2 = q.front().first.second;
		int check3 = q.front().second;
		q.pop();

		if (check[check1][check2]) continue;
		check[check1][check2] = true;

		if (check1 == 0) v.push_back(check3);

		// a -> b
		if (check1 + check2 > b)
			q.push(make_pair(make_pair((check1 + check2) - b, b), check3));
		else
			q.push(make_pair(make_pair(0, check1 + check2), check3));

		// a -> c
		if (check1 + check3 > c)
			q.push(make_pair(make_pair((check1 + check3) - c, check2), c));
		else
			q.push(make_pair(make_pair(0, check2), check1 + check3));

		// b -> a
		if (check1 + check2 > a)
			q.push(make_pair(make_pair(a, (check1 + check2) - a), check3));
		else
			q.push(make_pair(make_pair(check1 + check2, 0), check3));

		// b -> c
		if (check2 + check3 > c)
			q.push(make_pair(make_pair(check1, (check2 + check3) - c), c));
		else
			q.push(make_pair(make_pair(check1, 0), check2 + check3));

		// c -> a
		if (check1 + check3 > a)
			q.push(make_pair(make_pair(a, check2), (check1 + check3) - a));
		else
			q.push(make_pair(make_pair(check1 + check3, check2), 0));

		// c -> b
		if (check2 + check3 > b)
			q.push(make_pair(make_pair(check1, b), (check2 + check3) - b));
		else
			q.push(make_pair(make_pair(check1, check2 + check3), 0));
	}
}
int main() {

	cin >> a >> b >> c;

	bfs();
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}