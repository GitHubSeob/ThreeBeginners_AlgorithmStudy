#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>
using namespace std;

int main() {


	int A = 0;
	int B = 0;
	int i = 0;

	scanf_s("%d %d", &A, &B);

	vector<int>C(A + B, 0);

	for (int idx = 0; idx < A + B; ++idx)
		scanf_s("%d", &C[idx]);

	sort(C.begin(), C.end());

	for (i = 0; i < C.size(); ++i)
		printf("%d ", C[i]);

}