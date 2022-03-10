#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        stack<int> s;
        string str;
        cin >> str;
        int ans = 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                s.push(str[i]);
            else if (!s.empty() && str[i] == ')')
                s.pop();
            else if (s.empty() && str[i] == ')')
            {
                ans = 0;
                break;
            }
        }
        if (ans == 1 && s.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}