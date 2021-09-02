#include<iostream>
#include<algorithm>
using namespace std;
int get_max(int a, int b) { return a > b ? a : b; }
int home[200001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, c;
    long long  low = 1, high = 0, mid, dis = 0, point;
    int ans = 0;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> home[i];
        high = get_max(high, home[i]);
    }
    sort(home, home + n+1); //1부터 시작인데 SORT(N+1) +1을 안해서 5번이나 틀리다니.
    
    while (low <= high) {
        mid = (low + high) / 2;
        int cnt = 1;
        point = home[1];

        //포인트를 기준으로 빼서 공유를 설치하는데 만약에 2분탐색보다 거리가 멀면 cnt++를 해준다.
        for (int i = 2; i <= n; i++) {
            dis = home[i] - point;
            if (mid <= dis) {
                cnt++;
                point = home[i];
            }
        }

        //숫자가 많거나 같다면 low=mid+1
        if (cnt >= c) {
            ans = mid;
            low = mid + 1;
        }//적다면 high=mid-1
        else {
            high = mid - 1;
        }

    }
    cout << ans;
}