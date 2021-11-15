#include<iostream>
using namespace std;

int main() {
	int number;
	int sum = 0;
	char a;

	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> a;
		sum += a - 48; //혹은 '0'으로도 빼기 가능? ㅇㅇ
	}
	cout << sum << endl;
}