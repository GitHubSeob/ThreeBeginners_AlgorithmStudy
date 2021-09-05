#include<iostream>
#include<string.h>
using namespace std;
int arr[2500][2500];
int n;
bool issame(int y, int x, int n);
void howmuch(int y, int x, int n);
int ans[3];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	memset(ans, 0, sizeof(ans));
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	howmuch(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}

}
bool issame(int y, int x, int size) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[y][x] != arr[i][j])
				return false;
		}
	}
	return true;
}

void howmuch(int y, int x, int size) {
	if (issame(y, x, size)==true) {
		ans[arr[y][x] + 1]++;
		return;
	}

	int ns = size / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			howmuch(y + i * ns, x + j * ns, ns);
		}
	}
}