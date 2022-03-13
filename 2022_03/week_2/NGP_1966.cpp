#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, n, m, tmp;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int ans = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;


        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            q.push({j, tmp});
            pq.push(tmp);
        }
        
        while (!q.empty())
        {
            int index = q.front().first;
            int priority = q.front().second;
            q.pop();
            //큐를 가중치 순서로 정렬 ->우선순위 큐 라는 개념을 활용.
            //원래는 배열을 추가해서 크기순으로 정렬한다 그리고 첫인덱스의 값과 같으면 ans++을 하고 그에 맞춰 인덱스++해서 진행하려 했지만 
            //우선순위라는 편안한 만들어진게 있어서 그렇게 구현(수정)

            if(pq.top() == priority)
            {
                pq.pop();
                ans++;
                if(index == m)
                {
                    cout<<ans<<"\n";
                    break;
                }
            }
            else
            {
                q.push({index,priority});
            }
        }
    }
}
