#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    for (int i = 1; i < n; i++) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}
