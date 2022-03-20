//문제풀이: https://githubseob.tistory.com/168

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0), idx(0);
	string input("");

	cin >> N >> M;

	unordered_map<string, int>pokemonS;
	unordered_map<int, string>pokemonI;

	for (idx = 1; idx <= N; ++idx) {
		cin >> input;
		pokemonS.insert({ input,idx });
		pokemonI.insert({ idx, input });
	}

	while (M--) {
		cin >> input;
		if (input[0] >= '0' && input[0] <= '9')
			cout << pokemonI[stoi(input)];

		else cout << pokemonS[input];
		cout << '\n';
	}
}