#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    int count = 0;
    vector<pair<int, int> > v;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    } //내림 차순으로 정렬

    sort(v.begin(), v.end());

    int temp = 0;

    for (int i = 0; i < num; i++) {
        int start = v[i].second;
        int end = v[i].first;

        if (start >= temp) {
            temp = end;
            count++;
        }
    }

    cout << count << '\n';
}