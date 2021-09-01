//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//
//using namespace std;
//
//long long arr[10001];
//
//long long cnt = 0;
//long long k, n, high, low = 1, middle = 0, result = 0;
//
//
//int main() {
//	cin >> k >> n;
//
//	for (int i = 0; i < k; i++) {
//		cin >> arr[i];
//		high = max(high, arr[i]);
//	}
//	while (low <= high) {
//		result = 0;
//		middle = (low + high) / 2;                       //중앙값 만들기 1+high 에 합
//
//		for (int i = 0; i < k; i++)
//			result += arr[i] / middle;                   //입력받은 값을 중앙값으로 내린다.
//
//		if (result >= n) {                              //만약 결과 값이 랜서의 갯수보다 높다면
//			low = middle + 1;                          //가장 낮은 값은 중앙값과 같다
//			if (middle > cnt) {                        // cnt 값이 미들보다 크면 (0보다 크면?)
//				cnt = middle;                         //카운트를 업!
//			}
//		}
//		else {
//			high = middle - 1;                       //그외의 경우라면 중앙값이 최고값이 된다.
//		}
//
//	}                                                  //low 값이 high 값이 될떄까지 반복
//	        
//	cout << cnt << endl;
//
//	return 0;
//}