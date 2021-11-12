#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {

	vector<string>nums;
	for (int i = 0; i < numbers.size(); i++)
		nums.push_back(to_string(numbers[i])); //각 원소를 문자열로 변환
	sort(nums.begin(), nums.end(), compare); //compare로 정렬
	string answer = "";
	for (int i = 0; i < nums.size(); i++)
		answer += nums[i]; //문자열 합치기
	if (answer[0] == '0') return "0"; //답이 0인 경우
	return answer;
}


