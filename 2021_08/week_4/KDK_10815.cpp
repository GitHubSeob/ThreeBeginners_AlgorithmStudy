#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int target;
        cin >> target;

        int left = 0, right = N - 1;
        bool searched = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < v[mid])
                right = mid - 1;
            else if (target == v[mid]) {
                searched = true;
                break;
            }
            else
                left = mid + 1;
        }

        if (!searched)
            cout << "0 ";
        else
            cout << "1 ";
    }

    cout << "\n";

    return 0;
}


