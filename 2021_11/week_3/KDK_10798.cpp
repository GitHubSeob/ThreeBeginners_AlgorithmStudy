#include <iostream>
using namespace std;

char a[15], b[15], c[15], d[15], e[15] = { 0 };
int main(void) {
	cin >> a >> b >> c >> d >> e;

	for (int i = 0; i < 15; i++) {
		if (a[i] != NULL)
			cout << a[i];
		if (b[i] != NULL)
			cout << b[i];
		if (c[i] != NULL)
			cout << c[i];
		if (d[i] != NULL)
			cout << d[i];
		if (e[i] != NULL)
			cout << e[i];

	}

	cout << "\n";
	return 0;
}