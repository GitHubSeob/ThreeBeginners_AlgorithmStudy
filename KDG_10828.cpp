#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, input;
    cin >> n;

    stack<int> s;

    string command;
    while (n--) {
        cin >> command;
        if (command == "push") {
            cin >> input;
            s.push(input);
        }
        else if (command == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (command == "size") cout << s.size() << '\n';
        else if (command == "empty") cout << s.empty() << '\n';
        else if (command == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
    return 0;
}
