/*
이문제는 그냥 모음이 한개이상 자음이 두개이상일때 재귀로 나타내면 편하다.
모든곳을 탐색하면서 정렬된 상태의 배열들을 출력만하면 되는것이라고 생각한다
만약 조건에서 모음이 한개라도 있다면 다음 포지션에서 자음을 진행하고 주루룩..
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int l, c;
char arr[16];
string str;
void dfs(int pos, string str, int con, int vow);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);

	dfs(0, "", 0, 0);

}

void dfs(int pos,string str,int con, int vow) {
	if (str.size() == l) {
		if (con >= 1 && vow >= 2)
			cout << str << "\n";
		return;
	}
	for (int i = pos; i < c; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			dfs(i + 1, str + arr[i], con + 1, vow);
		}
		else
			dfs(i + 1, str + arr[i], con, vow + 1);
	}
}
