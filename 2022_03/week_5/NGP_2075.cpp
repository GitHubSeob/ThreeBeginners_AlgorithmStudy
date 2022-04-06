/*
표에 채워진 수는 다르고
아랫칸이 위에칸보다는 크다.

메모리 초과! 그러면 크기보다 크면 pop을 하면 되지않을까?
흠 갑자기 5가 뜸 그러면 음수로 취해서 정렬해서 팝팝하면?
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    priority_queue<int> pq;

    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            pq.push(-tmp);
            if(pq.size()>n)
                pq.pop();
        }
    }

    cout << -pq.top();
}
