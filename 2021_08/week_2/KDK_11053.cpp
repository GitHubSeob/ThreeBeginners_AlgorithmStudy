#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{

	int n;
	int DP[1000];
	int a[1000];
	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}




	for (int i = 0; i < n; i++)
	{
		DP[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		sum = max(sum, DP[i]);
	}

	cout << sum << endl;
}