#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= '0' && S[i] <= '9') {
            S[i] = '0';
        }
    }
    S.erase(remove(S.begin(), S.end(), '0'), S.end());

    string ans;
    cin >> ans;

    if (S.find(ans) != string::npos) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}

