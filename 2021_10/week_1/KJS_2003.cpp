#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, S;//N개, 합S
    cin >> N >> S;
    vector <int> num(N);

    int i, j, k;

    for (i = 0; i < N; i++)//수열입력
        cin >> num[i];

    vector <int> comb;//선택할 배열

    int temp, result = 0;
    for (i = 1; i <= N; i++) {//선택할 개수
        comb.clear();

        for (j = 1; j <= i; j++)
            comb.push_back(1); //부분순열의 크기만큼 1
        for (k = N - j; k >= 0; k--)
            comb.push_back(0); //이외는 0

        do {
            temp = 0;//임시값 초기화
            for (int l = 0; l < N; l++) {
                if (comb[l] == 1)//해당 될 경우만 더하기
                    temp += num[l];
            }
            if (temp == S)//다 더한 값이 S라면
                result++;//증가
        } while (next_permutation(comb.begin(), comb.end(), greater<int>()));//선택할 개수 내림차순
    }
    cout << result;
}
