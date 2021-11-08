#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;
    queue<pair<int, int>> que;
    priority_queue <int> prio_que;

    for (int i = 0; i < priorities.size(); i++) {
        
        que.push(make_pair(i, priorities[i]));
       
        prio_que.push(priorities[i]);
    }
   
    while (!que.empty()) {
        int index = que.front().first;
        int value = que.front().second;
        que.pop();
        
        if (prio_que.top() == value) {
            prio_que.pop();
            count++;
            if (index == location) {
                answer = count;
                break;
            }
        }
        
        else
            que.push(make_pair(index, value));
    }
    return answer;
}