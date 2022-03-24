#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N, M, result;
string s;
map<string, bool> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; //갯수

	for (int i = 0; i <= N; i++) //5개 입력 해 놓기 
	{
		cin >> s;
		m[s] = true;
	}

	for (int i = 0; i <= M; i++)
	{
		cin >> s;
		if (m[s]) result++; //m[s] true 값과 일치하면 result up
	}

	cout << result << '\n';

}