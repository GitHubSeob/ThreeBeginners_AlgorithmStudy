//문제풀이: https://githubseob.tistory.com/66

#include <iostream>
using namespace std;

void Make_Star(int N, int y, int x) {
    if (y % 3 == 1 && x % 3 == 1) cout << ' ';
    else if (y / N % 3 == 1 && x / N % 3 == 1) cout << ' ';
    else if (N >= 3) Make_Star(N / 3, y, x);
    else cout << '*';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    int y = 0, x = 0;
    cin >> N;

    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            Make_Star(N, y, x);
        }
        cout << '\n';
    }
}