#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    int tmp;
    queue<int> q;

    // int arr[5001];
    // cin >> n >> k;
    // for (int i = 1; i <= n; i++)
    //     arr[i] = i;
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);
    cout << "<";

    while (q.size() - 1 != 0)
    {
        for (int i = 1; i < k; i++)
        {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    q.pop();
}
