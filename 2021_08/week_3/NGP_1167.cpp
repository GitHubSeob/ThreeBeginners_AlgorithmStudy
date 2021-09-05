#include<iostream>
#include<vector>
using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
vector<vector<pair<int, int>>> number;
bool visited[100000];
void dfs(int a);

int diameter;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> c;
        while (c != -1) {
            cin >> b >> c;
            number[a].push_back({ b,c });

        }
    }

}

void dfs(int a) {
    if (visited[a] == true)
        return;

}