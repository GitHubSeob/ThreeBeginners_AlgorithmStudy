//문제풀이: https://githubseob.tistory.com/159

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0);
	cin >> N;

	string input("");
	cin >> input;

	vector<string>arr_input(input.size(), "");
	vector<double>num(N, 0);

	for (idx = 0; idx < N; ++idx)
		cin >> num[idx];

	for (idx = 0; idx < N; ++idx) {
		for (int idx2(0); idx2 < input.size(); ++idx2) {
			if (input[idx2] >= 'A' && input[idx2] <= 'Z') {
				if (idx + 'A' == input[idx2])
					arr_input[idx2] = to_string(num[idx]);
			}
			else arr_input[idx2] = input[idx2];
		}
	}
	double number(0);
	while (arr_input.size() >= 3) {
		for (idx = 0; idx + 2 < arr_input.size(); ++idx) {
			if (arr_input[idx] != "+" && arr_input[idx] != "-" && arr_input[idx] != "*" && arr_input[idx] != "/") {
				if (arr_input[idx + 1] != "+" && arr_input[idx + 1] != "-" && arr_input[idx + 1] != "*" && arr_input[idx + 1] != "/") {
					if (arr_input[idx + 2] == "+")
						number = stod(arr_input[idx]) + stod(arr_input[idx + 1]);

					else if (arr_input[idx + 2] == "-")
						number = stod(arr_input[idx]) - stod(arr_input[idx + 1]);

					else if (arr_input[idx + 2] == "*")
						number = stod(arr_input[idx]) * stod(arr_input[idx + 1]);

					else if (arr_input[idx + 2] == "/")
						number = stod(arr_input[idx]) / stod(arr_input[idx + 1]);

					else continue;

					arr_input[idx] = to_string(number);
					arr_input.erase(arr_input.begin() + idx + 1);
					arr_input.erase(arr_input.begin() + idx + 1);
					idx = -1;
				}
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stod(arr_input[0]);
}