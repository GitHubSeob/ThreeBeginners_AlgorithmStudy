#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 10001;
bool prime_num[MAX];
int visited[MAX];
int num[4]; //자리수 나누기 위함

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int T, a, b;
    //소수 체크하기
    prime_num[0] = true;
    prime_num[1] = true;
    cin >> T;
    for (int i = 2; i < 10001; i++) {
        for (int j = 2; i * j < 10001; j++) {
            prime_num[i * j] = true;
        }
    }//소수 찾기

    while (T-- > 0) {
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));

        if (a == b) {
            cout << "0" << "\n";
        }//예제 3
        else
            bfs(a, b);

    }


    return 0;
}