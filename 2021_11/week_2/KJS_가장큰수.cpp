//문제풀이: https://githubseob.tistory.com/142

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string>snum;
    string answer = "";
    int idx(0);

    for (idx = 0; idx < numbers.size(); ++idx)
        snum.push_back(to_string(numbers[idx]));

    sort(snum.begin(), snum.end(), compare);

    for (idx = 0; idx < snum.size(); ++idx)
        answer += snum[idx];
    if (answer[0] == '0') return "0";
    return answer;
}