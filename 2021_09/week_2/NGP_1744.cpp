#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, tmp, sum = 0, zero = 0;
    cin >> n;

    vector<int> minus;
    vector<int> plus;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;

        if (tmp < 0)
            minus.push_back(tmp);
        else if (tmp == 0)
            zero = 1;
        else if (tmp > 0)
            plus.push_back(tmp);
    }

    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), compare);


    if (minus.size() % 2 == 1 && minus.size() >= 1) {
        if (zero == 1)
            minus.push_back(0);
        else
            minus.push_back(1);
    }
    if (plus.size() % 2 == 1 && plus.size() >= 1) {
        plus.push_back(0);
    }


    for (tmp = 0; tmp < minus.size() - 1; tmp += 2) {
        sum += (minus[tmp] * minus[tmp + 1]);
    }
    for (tmp = 0; tmp < plus.size() - 1; tmp += 2) {
        if (plus[tmp] + plus[tmp + 1] > plus[tmp] * plus[tmp + 1])
            sum += (plus[tmp] + plus[tmp + 1]);
        else
            sum += (plus[tmp] * plus[tmp + 1]);
    }

    cout << sum;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){

	int n;
	cin >> n;
	vector<int> plus, minus, zero;
	for(int i=0; i<n; i++){
		int temp; cin >> temp;
		if(temp > 0) plus.push_back(temp);
		else minus.push_back(temp);
	}
	ll ans = 0;
	int p = plus.size(); int m = minus.size();
	int idx;
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	for(idx = p-1; idx > 0; idx -= 2){
		if(plus[idx] > 1 && plus[idx-1] > 1)
			ans += plus[idx] * plus[idx-1];
		else
			ans += plus[idx] + plus[idx-1];
	}

	if (p % 2 == 1) ans += plus[0];

	for(idx = 0; idx < m-1; idx += 2)
		ans += minus[idx] * minus[idx+1];

	if (m % 2 == 1)
		ans += minus[m-1];

	cout << ans;
	return 0;
}

*/
