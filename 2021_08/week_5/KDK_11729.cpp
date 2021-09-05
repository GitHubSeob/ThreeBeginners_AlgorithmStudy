#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int N, int A, int B, int C)
{
	if (N == 1)
		cout << A << " " << C << '\n';
	else
	{
		Hanoi(N - 1, A, C, B);
		cout << A << " " << C << '\n';
		Hanoi(N - 1, B, A, C);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int k = (int)pow(2, N) - 1;
	cout << k << '\n';
	Hanoi(N, 1, 2, 3);

	return 0;
}
/*1. 최소 이동 횟수 규칙

→ 원판   횟수

1       1

2       3

3       7

4       15

5       31

→(2 ^ n) - 1

2. N개의 원판을 옮기는 방법

→ 장대1의 N - 1개 원판을 장대2로 옮김

→ 남은 장대1의 가장 큰 원판을 장대3으로 옮김

→ 장대2에 N - 1개의 원판이 남음

→ 장대2의 N - 2개의 원판을 장대1로 옮김

→ 남은 장대2의 가장 큰 원판을 장대3으로 옮김

→ 장대1에 N - 2개의 원판이 남음

→ 반복...
[출처][백준] 11729번 하노이 탑 이동 순서(C / C++) | 작성자 워뇨*/