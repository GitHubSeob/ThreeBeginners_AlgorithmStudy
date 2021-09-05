#include<iostream>
using namespace std;
void repeat(int size, int y, int x);

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			repeat(n, i, j);
		}
		cout << "\n";
	}

}

void repeat(int size, int y, int x) {
	if ((y / size) % 3 == 1 && (x / size) % 3 == 1) {
		cout << ' ';
	}
	else if (size / 3 == 0) {
		cout << "*";
	}
	else {
		repeat(size/3,y,x);
	}
}

