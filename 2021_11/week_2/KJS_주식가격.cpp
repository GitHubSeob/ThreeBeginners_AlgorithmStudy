//문제풀이: https://githubseob.tistory.com/141

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int>answer;
    int idx(0);
    int idx2(0);
    for (idx = 0; idx + 1 < prices.size(); ++idx) {
        for (idx2 = idx + 1; idx2 < prices.size(); ++idx2) {
            if (prices[idx] > prices[idx2]) {
                answer.push_back(idx2 - idx);
                break;
            }
        }
        if (idx2 == prices.size())
            answer.push_back(idx2 - (idx + 1));
    }
    answer.push_back(0);
    return answer;
}