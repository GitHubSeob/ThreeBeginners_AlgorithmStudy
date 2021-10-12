/*
원리는 간단하다.
모든 수를 탐색하는 방법을 채택했다. (부르트~~)
첫원소일때 두번째 원소들이상의 조합들을 모두 합을 구해서 큐에 저장한다.
두번째일때도 세번째 이상의 원소들과의 조합들로 큐에 저장
->여기서 중복이 되면 안되므로 잘짜야함.
그렇게 끝까지 진행한 후 find 라는 함수에서 q를 하나씩 비워나가면서 숫자가 있는지 확인.
하지만 처음에 0이라면 0이 push되므로 0일경우에는 ans-1을 진행 아닐경우에는 ans 출력
*/

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, s, ans = 0;
int arr[20];
void add(int tmp, int num);
void find(int num);
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	add(0,0);
	find(0);

	return 0;
}

void add(int tmp,int num) {
	q.push(num);

	for (int i = tmp; i < n; i++) {
		add(i+1,num+arr[i]);
	}
}

void find(int num) {
	while (!q.empty()) {
		if (q.front() == s)
			ans++;
		q.pop();
	}
	if (s == 0)
		cout << ans - 1;
	else
		cout << ans;
}