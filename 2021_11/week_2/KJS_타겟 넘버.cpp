//문제풀이: https://githubseob.tistory.com/138

#include <string>
#include <vector>

using namespace std;
int answer;

void dfs(int sum, int num, vector<int>numbers, int target) {
    if (num == numbers.size() && sum == target) answer++;
    if (num < numbers.size()) {
        dfs(sum + numbers[num], num + 1, numbers, target);
        dfs(sum - numbers[num], num + 1, numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int num(0);
    int sum(0);
    dfs(0, 0, numbers, target);
    return answer;
}