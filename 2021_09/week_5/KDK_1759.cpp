#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> v;
    for (int i = 0; i < m; i++) {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    vector<int> u;
    for (int i = 0; i < n; i++) {
        u.push_back(0);
    }
    for (int i = 0; i < m - n; i++) {
        u.push_back(1);
    }

    do {
        int a = 0, b = 0;
        string s = "";
        for (int i = 0; i < m; i++) {
            if (u[i] == 0) {
                s += v[i];
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') a += 1;
                else b += 1;
            }
        }
        if (a >= 1 && b >= 2) cout << s << "\n";
    } while (next_permutation(u.begin(), u.end()));
}