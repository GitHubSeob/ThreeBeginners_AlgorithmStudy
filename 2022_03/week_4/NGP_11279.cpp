/*
배열에 자연수 x값을 넣고 가장 큰 값을 출력하고 제거하기
우선순위 큐로 받아오게 되면 선언한 자료형 변수들은 내림차순에 따라 정렬하는 우선순위 큐를 선언하게 되는것.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, tmp;
    priority_queue<int> q;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (tmp == 0)
        {
            if (q.empty())
            {
                cout << "0" << "\n";
                continue;
            }
            cout << q.top() << "\n";
            q.pop();
        }
        else
        {
            q.push(tmp);
        }
    }
    return (0);
}