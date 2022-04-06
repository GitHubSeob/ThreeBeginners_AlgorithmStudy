/*
절댓값 기준으로 받게 되는데 만약 값이 같게 된다면 음수를 출력하게 되면 된다.
우선순위 큐로 구현을 하는데 음수와 양수를 따로 받아서 만약에 입력 받은 값이 0이라면 그때 출력을 하게 되는데 값을 비교해서 작은값을 출력하게 된다.
절댓값이 같다면 위와같이 음수를 출력하게 되면 된다.
top을 그냥 출력하게 되면 되고 우선순위로 받으면 간단한 문제일듯?

priority_queue<자료형, 구현체, 비교연산자>
비교 연산자에는 less와 greater로 있는데 less는 큰순서대로 -> 우선순위 큐라서 상관 x greater은 작은순서
죽 그러면 우리가 양수에 대해서는 작은순서대로 구현을 하려면
priority_queue<int, vector<int>, greater<int>> pq1; -> 작은순서대로
priority_queue<int, vector<int>, less<int>> pq2; -> 큰순서대로
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> p; //양수
    priority_queue<int> m;                            //음수

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x == 0)
        {
            if (p.empty() && m.empty())
            {
                cout << "0" << "\n";
            }
            else if (!p.empty() && m.empty())
            {
                cout<<p.top()<<"\n";
                p.pop();
            }
            else if (p.empty() && !m.empty())
            {
                cout<<m.top()<<"\n";
                m.pop();
            }
            else
            {
                if(p.top()< -m.top())
                {
                    cout<<p.top()<<"\n";
                    p.pop();
                }
                else
                {
                    cout<<m.top()<<"\n";
                    m.pop();
                }
            }
        }
        else
        {
            if (x > 0)
                p.push(x);
            else
                m.push(x);
        }
    }
}