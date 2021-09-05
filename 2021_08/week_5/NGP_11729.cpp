#include<iostream>
#include<cmath>
//int arr[1100000][2] 보다 벡터로 쌍만들어서 하는게 걍 편할듯 ->그냥 값이 2^n-1인걸 알게된다면 둘다 필요없는듯.
using namespace std;
void hanoi(int n, int start, int mid, int end);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int k;
	cin >> k;
	int move = pow(2, k) - 1;
	cout << move << "\n";
	hanoi(k, 1, 2, 3);
}

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		cout << start << " "<<end<< "\n"; //그림에서 그렸듯이 원판이 한개일때 거길로감
	}
	else {
		hanoi(n - 1, start, end, mid); //기둥 2로
		cout << start << " " << end << "\n"; //옮길때마다 출력
		hanoi(n - 1, mid, start, end); //기둥 3으로
	}
}