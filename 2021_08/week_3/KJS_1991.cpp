//문제풀이: https://githubseob.tistory.com/28

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>Arr(26, vector<int>(2, -1));

void Preorder(int start) {
	start -= 65;
	char Alp = (char)(start + 65);
	cout << Alp;
	if (Arr[start][0] != -1)
		Preorder(Arr[start][0]);
	if (Arr[start][1] != -1)
		Preorder(Arr[start][1]);
}

void Inorder(int start) {
	start -= 65;
	char Alp = (char)(start + 65);
	if (Arr[start][0] != -1)
		Inorder(Arr[start][0]);
	cout << Alp;
	if (Arr[start][1] != -1)
		Inorder(Arr[start][1]);

}

void Postorder(int start) {
	start -= 65;
	char Alp = (char)(start + 65);
	if (Arr[start][0] != -1)
		Postorder(Arr[start][0]);
	if (Arr[start][1] != -1)
		Postorder(Arr[start][1]);
	cout << Alp;
}

int main() {
	int N = 0;
	int i = 0;
	cin >> N;

	for (i = 0; i < N; ++i) {
		char Alp = ' ';
		char Alp1 = ' ';
		char Alp2 = ' ';
		cin >> Alp >> Alp1 >> Alp2;
		if (Alp1 != '.')
			Arr[(int)Alp - 65][0] = (int)Alp1;
		if (Alp2 != '.')
			Arr[(int)Alp - 65][1] = (int)Alp2;
	}
	Preorder(65);
	cout << "\n";
	Inorder(65);
	cout << "\n";
	Postorder(65);
}