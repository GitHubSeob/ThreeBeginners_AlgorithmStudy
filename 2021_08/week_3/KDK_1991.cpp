#include <iostream>
using namespace std;

struct node {
    char LChild; // 왼쪽 자식
    char RChild; // 오른쪽 자식
};

node arr[27];

void preorder(char a) { // 전위 순회
    if (a != '.') {
        cout << a; 
        preorder(arr[a].LChild);
        preorder(arr[a].RChild);
    }
    else return; 
}

void inorder(char a) { // 중위 순회
    if (a != '.') {
        inorder(arr[a].LChild);
        cout << a; 
        inorder(arr[a].RChild);
    }
    else return; 
}

void postorder(char a) { // 후위 순회
    if (a != '.') {
        postorder(arr[a].LChild); 
        postorder(arr[a].RChild); 
        cout << a; 
    }
    else return; 
}

int main() {
    int n;
    char a, b, c;

    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> a >> b >> c;
        arr[a].LChild = b; 
        arr[a].RChild = c; 
    }

    preorder('A'); // 항상 A가 루트 노드
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
}
