#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T, n;
int DP[200002][2];
int sticker[200002][2];

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> sticker[i][0];
		for (int i = 0; i < n; i++)
			cin >> sticker[i][1];

		DP[0][0] = sticker[0][0];
		DP[0][1] = sticker[0][1];

		for (int i = 1; i < n; i++)
		{
			DP[i][0] = max(DP[i - 1][0], DP[i - 1][1] + sticker[i][0]); 
			DP[i][1] = max(DP[i - 1][1], DP[i - 1][0] + sticker[i][1]);
			/* 선택한 대각선의 값 vs 이전열에서 선택하지 않고
			그전 열에서 같은 행의 스티커를 선택한 경우 중 최대값을 고르면 된다.
			*/
		}

		cout << max(DP[n - 1][0], DP[n - 1][1]) << '\n';
		//1열과 2열중 어디에서 시작된값이 더 큰가?

	}

}