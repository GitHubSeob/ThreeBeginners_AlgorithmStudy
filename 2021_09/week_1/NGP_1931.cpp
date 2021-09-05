#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> time;

bool compare(const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; } //벡터 두번째 원소 비교.

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, start, stop, ans=1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> stop;
		time.push_back(make_pair(start, stop));
	}

	//시작 -> 종료로 정렬을 하면 종료 시간이 가장 빠른것중에 시작이 가장빠른순으로 정렬 되는거 인정? 응 인정~
	sort(time.begin(), time.end());
	sort(time.begin(), time.end(), compare);

	//정렬을 했으므로 가장 먼저 끝나는 시간은 time[0].second();
	int end = time[0].second;

	//미리 종료->시작기준으로 정렬을 했으므로 시작시간이 가장 빠른것이 시작시간보다 크다면 뭐 그게 맞겠죠? 네~ 맞습니다.
	for (int i = 1; i < n; i++) {
		if (time[i].first >= end) {
			end = time[i].second;
			ans++;
		}
	}
	cout << ans;
}

/*
기본적으로 vector<pair<int, int» 는 sort 함수 사용 시 first 값을 기준으로 정렬됩니다.

compare 함수를 정의하여 pair의 두 번째를 기준으로 정렬하게 바꾸는 방법
bool compare(const pair<int, int>&a, const pair<int, int>&b){
	return a.second < b.second;
}
위처럼 함수를 재정의한 이후,


vector<pair<int, int> vecs;
sort(vecs.begin(), vecs.end(), compare);
라고 sort 함수의 세 번째 인자에 정의한 함수명을 넣어서 사용하면 됩니다.
*/