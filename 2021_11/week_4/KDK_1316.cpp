#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int n(0);
	int ans(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char word[100];
		cin >> word;
		if (strlen(word) <= 2)
		{
			ans++;
		}

		else
		{
			int count = 0;
			for (int j = 2; j < strlen(word); j++)
			{
				for (int k = 0; k < j - 1; k++)
				{
					if (word[k] == word[j] && word[k + 1] == word[j]) //기준글자[j]가 그전전[k] 그전[k+1]단어와 같으면 패스
					{
						continue;
					}
					else if (word[k] == word[j]) //그전전글자와는 같은데,그전단어와 새로운 단어가 다를경우.aba와 같은경우
					{
						count++;
					}
				}
			}
			if (count == 0)
			{
				ans++;
			}
		}
	}

	cout << ans << endl;
	
}
