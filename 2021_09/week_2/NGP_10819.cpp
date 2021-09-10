#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[8];
int n, ans = 0, sum = 0;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	do {
		sum = 0;
		for (int i = 0; i < n-1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
			ans = max(ans, sum);
		}
	} while (next_permutation(arr, arr + n));


	cout << ans;
}



/*
next_permutation은 더 큰 순열을로 재배열을 할 수 있으면 반복하여 구해내는 구조이므로 앞에 이미 큰 원소들이 배치되어 있으면 반복하지 않게 됩니다.
만약 데이터가 내림차순으로 정렬이되어 있다면 next_permutation 대신 prev_permutation을 사용하면 된다.

do{
출력하고자 하는 부분
}while(next_permutation(arr, arr+arrNum));

→ do while문을 쓰는 이유: next_permutation구문을 만나는 순간부터! 순차적으로 배열의 순열을 바꾸게 됨

ex) a,b,c,d의 배열의 4p3의 순열 출력.
#include<iostream>

using namespace std;
void permutation(char data[], int depth, int n, int r);
int main()
{
    char arr[] = { 'a', 'b', 'c', 'd' };
    permutation(arr, 0, 4, 3); // 4P3
    return 0;
}

void permutation(char data[], int depth, int n, int r)
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
            cout << data[i] << " ";
        cout << endl;

        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(data[depth], data[i]);   // 스왑
        permutation(data, depth + 1, n, r);  // ⭐재귀
        swap(data[depth], data[i]);  // 다시 원래 위치로 되돌리기
    }
}



*/
