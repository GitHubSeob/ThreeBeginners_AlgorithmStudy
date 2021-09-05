#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
    if (a > b) return true;
    else return false;
}
int main(void) {
    string s;
    cin >> s;
    int len = s.size();
    int arr[100001];
    int sum = 0;
    for (int i = 0; i < len; i++) {
        arr[i] = s[i] - '0';
        sum += arr[i];
    }
    sort(s.begin(), s.end(), cmp);
    if (s[len - 1] == '0' && sum % 3 == 0) {
        cout << s << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}