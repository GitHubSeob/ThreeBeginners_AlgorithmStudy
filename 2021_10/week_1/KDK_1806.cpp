#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, S;
int sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;


	int arr[100001];
	int result(100001);
	int start(0);
	int end(0);
	int temp(0);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (end <= N) {
		if (sum >= S) {
			temp = end - start;
			result = min(result, temp);
			sum -= arr[start++];//sum >=M보다 크거나 같으면 앞 포인터 START값에서 하나 더하기
		}
		else if (sum < S)
			sum += arr[end++];//작으면 뒤에 포인터 END 끝자리에서 하나 더하기
	}
	if (result == 100001) cout << 0;
	else cout << result;
}