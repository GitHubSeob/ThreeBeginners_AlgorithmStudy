#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100002];
int correct[100001]; //루트가 1인 부모를 제외하고 다음 자식들부터 누가 부모인지 저장. 즉, 문제의 답.
bool visited[100002];

void dfs(int a); //a는 트리의 루트가 1이 될것 같음

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); // 시간 줄여주기 위해서 씀
    int n, a, b;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << correct[i] << "\n";
    }

    return 0;
}

void dfs(int a) {
    visited[a] = true;
    for (int i = 0; i < tree[a].size(); i++) {
        int node = tree[a][i];
        if (!visited[node]) {
            correct[node] = a;
            dfs(node);
        }
    }
}