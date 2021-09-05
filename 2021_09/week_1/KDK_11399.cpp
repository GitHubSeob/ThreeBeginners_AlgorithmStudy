#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    int ans = 0;
    vector<int>v;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int m;
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    int temp = 0;
    int temp2 = 0;
    int count[1001] = { 0 };
    for (int i = 0; i < num; i++) {
        count[i] = v.at(i) + temp;
        temp = count[i];
    }
    for (int i = 0; i < num; i++) {
        ans += count[i];
    }

    cout << ans << '\n';
}