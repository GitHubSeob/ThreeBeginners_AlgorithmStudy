//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include<cstring>
//using namespace std;
//long long arr[10001],cnt[10001];
//long long k, n, high, low = 1, result = 0;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	int N = 0, M = 0;
//
//	cin >> k >> n;
//
//
//		for (int i = 0; i < k; i++) {
//			cin >> arr[i];
//			low = min(low, arr[i]);
//			high = max(high, arr[i]);
//		}
//	
//	while (result = M) {
//		result = low;
//		for (int i = 0; i < k; i++) {
//			if (arr[i] >= low)
//				cnt[i] = arr[i] - low;
//		}
//		for (int i = 0; i < k;i++) {
//			result += cnt[i];
//		}
//
//		low = high + low / 2;
//	}
//	cout << result << endl;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//
//using namespace std;
//
//
//
//long long cnt = 0;
//long long k, n, high, low = 1, middle = 0, result = 0;
//
//
//int main() {
//	cin >> k >> n;
//	vector<int>arr;
//	for (int i = 0; i < k; i++) {
//		cin >> arr[i];
//		
//	}
//	
//	while (low <= high) {
//		result = 0;
//		middle = (low + high) / 2;                       //중앙값 만들기 1+high 에 합
//		for (int i = 0; i < n; i++)
//			if (arr[i] - middle > 0)
//				result += (arr[i] - middle);
//		if (result < n)
//			high = middle - 1;
//		else
//			low = middle + 1;
//	}                                                  //low 값이 high 값이 될떄까지 반복
//	        
//	cout << high << endl;
//
//	return 0;
//}