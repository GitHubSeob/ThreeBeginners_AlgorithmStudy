/*
2차원 배열로 생각하면 만약에  첫번째 i와 두번째 j와 같다면 전의 값에서 +1을하면서 
dp의 형태로 저장하여 가장 긴 값을 계속 저장하게 된다면 되지 않을까?

*/

#include<iostream>
#include<string>

using namespace std;
int get_max(int a, int b) { if (a > b)return a; else return b; }
int dp[4001][4001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string one, two;

	cin >> one;
	cin >> two;
	int ans = 0;
	
	

	for (int i = 0; i < one.length(); i++) {
		for (int j = 0; j < two.length(); j++) {
			if (one[i] == two[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans = get_max(ans, dp[i + 1][j + 1]);
			}
		}
	}


	cout << ans;
}