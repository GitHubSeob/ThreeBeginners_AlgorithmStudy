//문제풀이: https://githubseob.tistory.com/165

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string input;
set<string>answer;

void DFS(int idx, vector<bool>remove, stack<pair<char, int>>bracket) {
	if (idx == input.size()) {
		string ans("");
		for (int idx2 = 0; idx2 < input.size(); ++idx2) {
			if (!remove[idx2])
				ans += input[idx2];
		}
		answer.insert(ans);
	}
	else if (input[idx] == '(') {
		bracket.push({ '(',idx });
		DFS(idx + 1, remove, bracket);
	}
	else if (input[idx] == ')') {
		int num = bracket.top().second;
		bracket.pop();
		DFS(idx + 1, remove, bracket);
		remove[num] = true;
		remove[idx] = true;
		DFS(idx + 1, remove, bracket);
	}
	else {
		DFS(idx + 1, remove, bracket);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> input;

	vector<bool>remove(input.size(), false);
	stack<pair<char, int>>bracket;

	DFS(0, remove, bracket);
	set<string>::iterator iter;

	iter = answer.begin();
	iter++;
	for (iter; iter != answer.end(); iter++)
		cout << *iter << '\n';
}