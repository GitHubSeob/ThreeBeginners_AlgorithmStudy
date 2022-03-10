#include <iostream>
#include <deque>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> q;
    int n;

    cin >> n;

    while (n--)
    {
        string str;
        cin >> str;

        if (str == "push_front")
        {
            int X;
            cin >> X;
            q.push_front(X);
        }

        else if (str == "push_back")
        {
            int X;
            cin >> X;
            q.push_back(X);
        }

        else if (str == "pop_front")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
            else
                cout << "-1\n";
        }

        else if (str == "pop_back")
        {
            if (!q.empty())
            {
                cout << q.back() << "\n";
                q.pop_back();
            }
            else
                cout << "-1\n";
        }

        else if (str == "size")
        {
            cout << q.size() << "\n";
        }

        else if (str == "empty")
        {
            cout << q.empty() << "\n";
        }

        else if (str == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
            }
            else
                cout << "-1\n";
        }

        else if (str == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << "\n";
            }
            else
                cout << "-1\n";
        }
    }
    return 0;
}