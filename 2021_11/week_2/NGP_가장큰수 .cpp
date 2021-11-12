
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(b) + to_string(a);
    return str1 > str2;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    //테스트 11번에서 틀린 예시다. 0 0 0 0이 주어질때 0이 출력되는것을 잊지 말자.
    if (numbers[0] == 0) answer = "0";

    return answer;

}
