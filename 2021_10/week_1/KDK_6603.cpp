#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1234;
    while (cin >> n && n != 0) {   //0이 아닐때까지 집어 넣는다.
        vector<int> num(n);

        for (int i = 0; i < n; i++)
            cin >> num[i];
        //숫자 배열의 입력
        vector<bool> comb(n, false);

        for (int i = 0; i < 6; i++)
            comb[i] = true;
        //6개의  숫자 배열만 true 로 

        do {
            for (int i = 0; i < n; i++)
                if (comb[i]) //6개만 실행한다.
                    cout << num[i] << ' ';
            cout << '\n';
        } while (prev_permutation(comb.begin(), comb.end()));
        cout << '\n';
    }
    return 0;
}