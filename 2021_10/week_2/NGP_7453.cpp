/*
그 저번문제 1208에서 생각한 논리를 착안했다
만약에 4000개라면 4000^4=>굉장히 큰 숫자를 초래하게 된다.
이럴바에는 그냥 왼쪽a,b들이랑 오른쪽 c,d들끼리 합을 구해놓고 정리를해서 값을 한다면
(4000^2)*(4000^2)이므로 더 줄어들지 않을까 싶다.
그리고 ab의 작은값부터 시작하고 cd의 큰값부터 시작을 하게 설정하면 더 빠르게 진행할듯?

그래서 합이 0일경우에는 abnum을 플러스한다.
거기서 만약에 같은 숫자일경우는 계속 플플플 해서 다음값을 찾는다.
이거는 ab한후 cd도 그렇게 해서 abtmp*cdtmp를 ans값에 계속 더해준다.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
long long arr[4000][4];
long long ans = 0;
vector<int> ab, cd;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(arr[i][0] + arr[j][1]);
			cd.push_back(arr[i][2] + arr[j][3]);
		}
	}
	
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	

	int abnum = 0;
	int cdnum = n * n - 1;
	int sumsize = n * n;

	while (abnum < sumsize && cdnum >= 0) {
		int sum = ab[abnum] + cd[cdnum];

		if (sum == 0) {
			int abnext = ab[abnum++];
			int cdnext = cd[cdnum--];
			long long abtmp = 1; //만약 4000개가 다 같은것 같은것들 때문에 long long
			long long cdtmp = 1;

			while (ab[abnum] == abnext && abnum < sumsize) {
				abtmp++;
				abnum++;
			}
			while (cd[cdnum] == cdnext && cdnum >= 0) {
				cdtmp++;
				cdnum--;
			}
			ans += (abtmp * cdtmp);
		}
		else if (sum > 0) {
			cdnum--;
		}
		else { 
			abnum++;
		}
	}

	cout << ans;


}