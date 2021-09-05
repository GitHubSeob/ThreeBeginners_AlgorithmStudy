#include<iostream>
#include<stdio.h>
using namespace std;

int quadtree[64][64];


void func(int x, int y, int size) {
	int check = quadtree[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (check == 0 && quadtree[i][j] == 1) {
				check = 2;
				cout << "(";
			}
			else if (check == 1 && quadtree[i][j] == 0) {
				check = 2;
				cout << "(";
			}
			if (check == 2) {
				func(x, y, size / 2); // size/2는 정중앙을 나타낸다. 정중앙 기준으로  2사분면
				func(x, y + size / 2, size / 2); //  1사분면
				func(x + size / 2, y, size / 2); // 3사분면
				func(x + size / 2, y + size / 2, size / 2); // 4사분면
				cout << ")";
				return;
			}
		}

	}
	if (check == 0)
		cout << 0;
	else
		cout << 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &quadtree[i][j]);
	}
	func(0, 0, n);

	return 0;
}
