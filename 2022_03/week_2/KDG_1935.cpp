#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	//변수 갯 수
	string stack;
	cin >> stack;
	//string 문자배열을 입력받음
	vector<int> number(n);
	vector<double>result;

	char temp;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	} //변수값을 n의 크기만큼 입력받음

	for (int i = 0; i < stack.size(); i++) {
		temp = stack[i];
		
		if (temp >= 'A' && temp <= 'Z') {
			result.push_back(number[temp - 'A']);
		}//입력받은값이 알파뱃 대문자라면 number의 변수값에 대응해서 result 함수에 넣는다.
		else {
			double a, b;
			b = result.back();
			result.pop_back();
			a = result.back();
			result.pop_back();

			switch (temp) {
			case '+':
				result.push_back(a + b);
				break;
			case '-':
				result.push_back(a - b);
				break;
			case '*':
				result.push_back(a * b);
				break;
			case '/':
				result.push_back(a / b);
				break;
			}
		}
	}
	cout << setprecision(2) << fixed << result.back(); //소수 두번째까지

}