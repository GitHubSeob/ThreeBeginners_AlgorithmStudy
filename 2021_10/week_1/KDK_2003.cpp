#include <iostream>
#include <vector>
using namespace std;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;


	int arr[10001];
	int sum(0);
	int result(0);
	int start(0);
	int end(0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	while (end <= N) {
		if (sum >= M)
			sum -= arr[start++]; //sum >=M보다 크거나 같으면 앞 포인터 START값에서 하나 더하기
		else if (sum < M)
			sum += arr[end++];//작으면 뒤에 포인터 END 끝자리에서 하나 더하기
		if (sum == M)
			result++;
	}
	cout << result;
}
//2중포인터