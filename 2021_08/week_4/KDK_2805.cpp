#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

long long cnt = 0;
long long k, n, high, low = 1, middle = 0, result = 0;
int main() {

	cin >> k >> n;
	vector<int>arr;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	while (low <= high) {
		result = 0;
		middle = (low + high) / 2;
		for (int i = 0; i < n; i++)
			if (arr[i] - middle > 0)
				result += (arr[i] - middle);
		if (result < n)
			high = middle - 1;
		else
			low = middle + 1;
	}       
	cout << high << endl;
	return 0;
}
