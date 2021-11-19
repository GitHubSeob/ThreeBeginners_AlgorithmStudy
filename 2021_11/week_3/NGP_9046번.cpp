#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;
	//이게 문제였다. 입력값이 받아지지 않아서 굉장히 골치가 아팠다. 
	//cin.ignore(읽어들일 문자 개수, 종료할때 입력할 문자) -> 보고 알게됨. 잊지말자
	cin.ignore();

	for (int tmp = 0; tmp < t; tmp++) {
		
		string s;
		getline(cin, s);
		pair<int, char> alpha[26] = { {0,' '} };

		//빈칸을 받을수 있음 그러나 엔터 전까지는 계속 받아야함
		//abcde/fghij/klmno/pqrst/uvwxy/z ->26개
		//그냥 하는것보다 pair로 묶어서 나중에 가장 많은 숫자가 어떤 문자인지 check ->처음에 이렇게 안해서 애먹음
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ')continue;
			alpha[s[i] - 'a'] = { alpha[s[i]-'a'].first + 1, s[i] };
		}
		sort(alpha, alpha + 26, cmp);

		if (alpha[0].first == alpha[1].first) {
			cout << "?" << "\n";
		}
		else {
			cout << alpha[0].second << "\n";
		}
	}

}
