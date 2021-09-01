//문제풀이: https://githubseob.tistory.com/68

#include <iostream>
#include <vector>
using namespace std;

vector<long long>Arr;
vector<long long>temp;

long long cnt = 0;
void Merge(int start, int end) {
	if (start == end) return;
	int mid =(start + end) / 2;
	int i = start, j = mid + 1, now = start;
	while (now <= end) {
		if (i > mid)
			temp[now] = Arr[j++];
		else if (j > end)
			temp[now] = Arr[i++];
		else if (Arr[i] <= Arr[j])
			temp[now] = Arr[i++];
		else if (Arr[i] > Arr[j]) {
			if (Arr[mid] > Arr[j]) cnt += ((long long)mid - i + 1);
			temp[now] = Arr[j++];
		}
		now++;
	}
	for (now = start; now <= end; ++now)
		Arr[now] = temp[now];
}

void MergeSort(int start, int end) {
	if (start >= end) return;
	else {
		int mid = (start + end) / 2;
		MergeSort(start, mid);
		MergeSort(mid + 1, end);
		Merge(start, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int idx = 0;
	cin >> N;

	Arr = vector<long long>(N, 0);
	temp = vector<long long>(N, 0);
	for (idx = 0; idx < N; ++idx)
		cin >> Arr[idx];
	MergeSort(0, N - 1);
	cout << cnt;
}