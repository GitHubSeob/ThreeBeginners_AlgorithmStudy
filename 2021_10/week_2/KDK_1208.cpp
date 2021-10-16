#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#define endl '\n'
typedef long long ll;

using namespace std;

int n, s;
vector<int> a;

void func(int l, int r, int sum, vector<int>& arr) {

    if (l == r) {
        arr.push_back(sum);
        return;
    }

    func(l + 1, r, sum, arr);
    sum += a[l];
    func(l + 1, r, sum, arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> l, r;
    func(0, n / 2, 0, l);
    func(n / 2, n, 0, r);

    sort(r.begin(), r.end());
    ll ans = 0;
    for (int i = 0; i < l.size(); i++) {
        ans += upper_bound(r.begin(), r.end(), s - l[i]) - lower_bound(r.begin(), r.end(), s - l[i]);
    }
    if (s == 0) ans--;
    cout << ans << endl;


    return 0;
}