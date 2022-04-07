#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;
int N, M;

multiset<pair<int, int>>ms;
map<int, int>mm;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int p(0), l(0);
	for (int i = 0; i < M; i++) {
		cin >> p >> l;
		ms.insert({ l,p }); //문제번호와 난이도
		mm[p] = l; //난이도에 문제번호를 묶어서 만듬
	}
	cin >> M;

	for (int i = 0; i < M; i++) {
		string commend;
		cin >> commend;
		if (commend == "add") {
			int p, l;
			cin >> p >> l;
			ms.insert({ l,p });//add는 추가
		}
		else if (commend == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				cout << prev(ms.end())->second << '\n';
			}
			else {
				cout << ms.begin()->second << '\n';//x가 1일경우  가장 어려운 문제  문제 번호
			}
		}
		else if (commend == "solved") {
			int p;
			cin >> p;
			ms.erase({ mm[p],p });
		}
	}
}