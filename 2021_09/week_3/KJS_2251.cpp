//문제풀이: https://githubseob.tistory.com/115

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<vector<int>>visit;
set<int>answer;
int max_A, max_B, max_C;

void BFS(int A, int B, int C) {
	int n_A = min(max_A, A + C);
	int n_B = B;
	int n_C = C + A - n_A;
	vector<int>temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}

	n_B = min(max_B, B + C);
	n_A = A;
	n_C = C + B - n_B;
	temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}

	n_A = min(max_A, A + B);
	n_B = B + A - n_A;
	n_C = C;
	temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}

	n_C = min(max_C, C + B);
	n_A = A;
	n_B = C + B - n_C;
	temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}

	n_B = min(max_B, B + A);
	n_A = A + B - n_B;
	n_C = C;
	temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}

	n_C = min(max_C, C + A);
	n_A = A + C - n_C;
	n_B = B;
	temp = { n_A,n_B,n_C };
	if (visit.find(temp) == visit.end()) {
		visit.insert(temp);
		if (n_A == 0)
			answer.insert(n_C);
		BFS(n_A, n_B, n_C);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int>::iterator iter;
	cin >> max_A >> max_B >> max_C;
	vector<int>temp = { max_A,max_B,max_C };
	answer.insert(max_C);
	visit.insert(temp);
	BFS(0, 0, max_C);
	for (iter = answer.begin(); iter != answer.end(); ++iter)
		cout << *iter << ' ';
}