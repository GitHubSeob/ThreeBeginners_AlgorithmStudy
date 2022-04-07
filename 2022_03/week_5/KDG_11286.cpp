#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair <int, int> min;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; 
    //오름차순 정렬을 위해 greater, 이런식으로 정렬하면 최소값은 가장 왼쪽 원소, 첫번째 원소가 같다면 두번째 원소가 다음으로 작은원소
    while (n--) {
        int x;
        cin >> x;
        if (x==0) { //x가 0?
            if (!pq.empty()) { 
                min = pq.top(); //최소값은 우선순위 queue로 정렬
                cout << pq.top().second << '\n'; // 값출력 
                pq.pop(); // 제거
            }
            else cout << 0 << '\n'; //비어있으면 0출력
        }
        else pq.push({ abs(x),x }); //절대값 x와 x를 넣는다.
    }
}