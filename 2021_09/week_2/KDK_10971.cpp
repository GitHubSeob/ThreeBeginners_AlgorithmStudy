#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int main()
{
   
    int result = 987654321;
    cin >> N;

    int cost[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> city(N);

    for (int i = 0; i < N; i++)
    {
        city[i] = i;
    }

    do
    {
        // 시작점이 0이 아니면 종료해도 상관없음
        if (city[0] != 0) break;

        bool ok = true;
        int cand = 0;
        for (int i = 0; i < N - 1; i++)
        {
            // 도시간의 비용이 0이면 이동할 수 없음
            if (cost[city[i]][city[i + 1]] == 0)
                ok = false;
            else
                cand += cost[city[i]][city[i + 1]];
        }
        if (ok && cost[city[N - 1]][city[0]] != 0)
        {
            cand += cost[city[N - 1]][city[0]];
            if (cand < result)
                result = cand;
        }
    }     while (next_permutation(city.begin(), city.end()));

    cout << result;
}