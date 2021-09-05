#include<iostream>

using namespace std;

int main() {
    int n, m, k, count = 0;
    cin >> n >> m >> k;

    while (1) {
        if (k <= (n - 2 + m - 1) && n >= 2 && m >= 1) {           //팀으로 남을 수 있는 숫자가 남아있고 k의 값이 1팀이라도 생성 될 수 있는것 보다 작다면.
            n -= 2;
            m -= 1;
            count++;
        }
        else break;
    }

    cout << count << endl;
    return 0;
}