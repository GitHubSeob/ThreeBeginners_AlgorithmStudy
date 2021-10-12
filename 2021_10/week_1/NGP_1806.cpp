/*
즉, 최소값을 구하면 되는것이기 때문에 생각보다 간단했다.
while문을 이용해서 왼쪽부터 시작을해 값이 작으면 오른쪽의 배열을 +1을 해줌으로써 합을 늘린다
이 상황에서 만약 s의 값을 합이 넘기게된다면 왼쪽값을 한칸 전진시켜 합을 구해준다.
즉, 모든 s의 값을 넘기는 상황에 최소값을 계속 구해주게 된다.
*/

#include<iostream>
#include<algorithm>
using namespace std;
int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int left = 0, right = 0;
	int sum = arr[0];
	int len = n + 1;


	while (left <= right && right < n) {
		if (sum < s) {
			right += 1;
			sum += arr[right];
		}
		else if (sum >= s) {
			len = min(len, right - left + 1);
			sum -= arr[left];
			left += 1;
		}
	}

	if (len == n + 1)
		cout << '0';
	else
		cout << len;

	return 0;
}

