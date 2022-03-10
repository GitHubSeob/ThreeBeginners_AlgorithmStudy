#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N, K;
    cin >> N;
    cin >> K;

    queue<int> que;
    queue<int> result;

    for (int i = 1; i <= N; i++) {
        que.push(i);
    }

    int a = 1;
    int t = 1;

    cout << "<";
    while (1) {
        if (t == N) {
            cout << que.front();
            break;
        }
        if (a == K) {
            cout << que.front();
            cout << ", ";
            que.pop();
            a = 1;
            t++;
        }
        else {
            que.push(que.front());
            que.pop();
            a++;
        }
    }
    que.pop();
    cout << ">";


    return 0;
}

