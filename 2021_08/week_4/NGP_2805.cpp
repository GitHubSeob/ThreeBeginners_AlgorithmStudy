#include<iostream>
using namespace std;
int multi, n, tree[1000001];
long long high, low = 1, mid, m, length, ans = 0;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> tree[i];
        if (high <= tree[i])
            high = tree[i];
    }
    while (low <= high) {
        mid = (low + high) / 2;
        length = 0;
        for (int i = 1; i <= n; i++) {
            if (tree[i] > mid)
                length += (tree[i] - mid);
        }

        if (length >= m) {
            if (ans < mid)
                ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans;
}