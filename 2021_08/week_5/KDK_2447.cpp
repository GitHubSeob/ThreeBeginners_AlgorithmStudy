#include <iostream>
using namespace std;

void func(int x, int y, int N)
{
	if (x % 3 == 1 && y % 3 == 1)
		cout << " ";
	else if (N / 3 == 1)
		cout << "*";
	else
		func(x / 3, y / 3, N / 3);
}

int main()
{
	int N;
	cin >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
			func(x, y, N);

		cout << '\n';
	}

	return 0;
}