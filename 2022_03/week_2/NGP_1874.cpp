#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, tmp;
    stack<int> s;
    vector<char> v;
    cin >> n;

    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        while (j <= tmp)
        {
            s.push(j);
            v.push_back('+');
            j++;
        }

        if (s.top() == tmp)
        {
            s.pop();
            v.push_back('-');
        }
        else
        {
            j = -1;
            break;
        }
    }

    if (j == -1)
        cout << "NO" << "\n";
    else
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << "\n";
    }
}