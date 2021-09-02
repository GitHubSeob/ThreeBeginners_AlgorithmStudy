#include<iostream>
#include<algorithm>
using namespace std;
long long card[500002], need[500002];
void binarysearch(int n, int b);
int n, m;
int low, high, mid;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> need[i];
	}

	for (int i = 0; i < m; i++) {
		binarysearch(n, need[i]);
	}
}

void binarysearch(int n, int b) {
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (card[mid] == b) {
			cout << "1" << ' ';
			return;
		}
		else {
			if (card[mid] < b) {
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
	}
	cout << "0" << ' ';
}

/*
#include<iostream>
#include<algorithm>
using namespace std;
long long card[500000],need[500000];

int main() {
	int n,m;
	int low, high, mid;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> need[i];
	}

	for (int i = 0; i < m; i++) {
		low = 0;
		high = n-1;

		while (low <= high) {
			mid = (low + high) / 2;
			if (card[mid] == need[i]) {
				cout << "1" << ' ';
				break;
			}
			else {
				if (card[mid] < need[i]) {
					low = mid + 1;
				}
				else
					 = mid - 1;
			}
		}
		cout << "0" << ' ';
	}

}
*/