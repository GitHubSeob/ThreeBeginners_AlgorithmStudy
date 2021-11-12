#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> numbers;
int target;
int answer = 0;

int main() {
	int answer = 0;

	
	return answer;
}

void dfs(vector<int> numbers, int target, int sum, int count) {
	if (count == numbers.size()) {
		if (sum == target) answer++;
		return;
	}
	dfs(numbers, target, sum + numbers[count], count + 1);
	dfs(numbers, target, sum - numbers[count], count + 1);
}