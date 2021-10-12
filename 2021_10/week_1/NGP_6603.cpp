/*
오름차순으로 주어지니깐 굳이 미리 sort할 필요 없고.. 

그냥 모든 경우의수를 탐색하면 되는거니..
길이가 6을 충족한다면 출력을 하게 되고
만약 1 2 3 4 5 6 7 8 9 라면
1에서 시작할ㄸ 재귀로 다 숫자를 다 뽑아내고 다음으로 간다고 생각하면 편할것이다.

저번에 완전탐색 문제를 풀다가 생각난 prev_permutation(arr,arr+k)로 해도 나쁘지 않을것 같다.
*/


#include<iostream>

using namespace std;
int k;
int arr[13];
int ans[6];
void choose_num(int num1, int num2);


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	
	while (1) {
		cin >> k;
		if (k == 0)
			break;

		for(int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		choose_num(0, 0);
		cout << "\n";
	}
	return 0;
}

void choose_num(int tmp, int length) {
	if (length == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = tmp; i < k; i++) {
		ans[length] = arr[i];
		choose_num(i + 1, length + 1);
	}
}