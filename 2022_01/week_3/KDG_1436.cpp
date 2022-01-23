#include <iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int val = 666;
	int cnt = 0;
	while (1)
	{
		
		for (int i = val; i >= 666; i /= 10)
		{
			if (i % 1000 == 666)
			{
				cnt++;
				break;
			}
		}

		if (N == cnt)
			break;
		else
			val++;
	}

	cout << val;

	return 0;

}


