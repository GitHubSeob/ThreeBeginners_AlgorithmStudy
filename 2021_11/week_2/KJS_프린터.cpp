//문제풀이: https://githubseob.tistory.com/140

#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>>print;
    int idx(0);
    vector<int>value(priorities.size(), 0);
    for (idx = 0; idx < priorities.size(); ++idx) {
        print.push_back({ priorities[idx], idx });
        value[idx] = priorities[idx];
    }

    sort(value.begin(), value.end(), greater<>());
    int count(1);
    int value_f(0);
    int value_s(0);
    int value_cnt(0);
    while (!print.empty()) {
        if (print.front().first == value[value_cnt]) {
            if (print.front().second == location)
                return count;
            print.pop_front();
            value_cnt++;
            count++;
        }
        else {
            value_f = print.front().first;
            value_s = print.front().second;
            print.push_back({ value_f, value_s });
            print.pop_front();
        }
    }
}