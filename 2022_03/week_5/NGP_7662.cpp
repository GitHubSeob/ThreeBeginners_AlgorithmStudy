/*
우선순위 덱같은거 있으면 편할듯ㅋㅋ
입력값이 만약에 D들이라면 전에 풀었던 문제에서 구상했던것처럼 그냥 그때만 정렬을 해서 최댓값 최솟값을 해주면 되지 않을까?

내생각 풀이법
1)
우선순위 덱을 내가 구현해보는건 어떨까 싶다.
오름차순 내림차순 두개를 구현하고 하는것도 괜찮을듯?

2)덱을 구현해서 필요할때마다 정렬을 하면될듯?

2로해야겠다 귀찮다 시간초과네 에라이 1번으로 하자
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, n, num;
    bool visited[1000001];
    char di;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        priority_queue<pair<int, int>> down;                                                //내림차순
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> up; //오름차순
        for (int j = 0; j < n; j++)
        {
            cin >> di >> num;
            if (di == 'I')
            {
                up.push({num, j});
                down.push({num, j});
                visited[j] = true;
            }
            else if (di == 'D')
            {
                if (num == 1)
                {
                    while (!down.empty() && !visited[down.top().second])
                    {
                        down.pop();
                    }
                    if (!down.empty())
                    {
                        visited[down.top().second] = false;
                        down.pop();
                    }
                }
                else if (num == -1)
                {
                    while (!up.empty() && !visited[up.top().second])
                    {
                        up.pop();
                    }
                    if (!up.empty())
                    {
                        visited[up.top().second] = false;
                        up.pop();
                    }
                }
            }
        }

        while (!down.empty() && !visited[down.top().second])
            down.pop();
        while (!up.empty() && !visited[up.top().second])
            up.pop();

        if (down.empty() && up.empty())
            cout << "EMPTY" << "\n";
        else
            cout << down.top().first << " " << up.top().first << "\n";
    }
}

/*
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, n, num;
    char di;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        deque<int> dq;
        for (int j = 0; j < n; j++)
        {
            cin >> di;
            if (di == 'I')
            {
                cin >> num;
                dq.push_back(num);
                sort(dq.begin(), dq.end());
            }
            else if (di == 'D')
            {
                cin >> num;
                if (!dq.empty())
                {
                    if (num == 1)
                        dq.pop_back();
                    else if (num == -1)
                        dq.pop_front();
                }
            }
        }
        if (dq.empty())
            cout << "EMPTY" << "\n";
        else
            cout << dq.back() << " " << dq.front() << "\n";
    }
    return (0);
}
*/