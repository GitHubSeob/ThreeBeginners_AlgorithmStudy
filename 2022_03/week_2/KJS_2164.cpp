//문제풀이: https://githubseob.tistory.com/155

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int>card;
	int N(0),idx(0);
	cin >> N;
	for (idx = 1; idx <= N; ++idx)
		card.push(idx);
	
	while (card.size() > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
	}

	cout << card.front();
}