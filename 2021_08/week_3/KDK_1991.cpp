//#include <iostream>
//#include<vector> 
//using namespace std;
//int N;
//char P, L, R;
//int parent[26][2];
//typedef struct treeRecord {
//	char Id;
//	struct treeRecord* LChild;
//	struct treeRecord* RChild;
//}node;
//typedef node* Nptr;
//node nodes[27];
//void PreOrder(Nptr T)
//{
//	if (T != NULL) {
//		cout << T->Id;
//		PreOrder(T->LChild);
//		PreOrder(T->RChild);
//	}
//}
//
//void InOrder(Nptr T) {
//	if (T != NULL) {
//		cout << T->Id;
//		InOrder(T->LChild);
//		InOrder(T->RChild);
//	}
//}
//void PostOrder(Nptr T) {
//	if (T != NULL) {
//		cout << T->Id;
//		PostOrder(T->LChild);
//		PostOrder(T->RChild);
//	}
//}
//int main(void) {
//	int n;
//	cin >> n;
//	treeRecord M;
//	for (int i = 0; i < n; i++) {
//		cin >> M.Id;
//	}
//	PreOrder(M)
//}
//#include <iostream>
//using namespace std;
//
//struct node {
//    char LChild; // 왼쪽 자식
//    char RChild; // 오른쪽 자식
//};
//
//node arr[27];
//
//void preorder(char a) { // 전위 순회
//    if (a != '.') {
//        cout << a; 
//        preorder(arr[a].LChild);
//        preorder(arr[a].RChild);
//    }
//    else return; 
//}
//
//void inorder(char a) { // 중위 순회
//    if (a != '.') {
//        inorder(arr[a].LChild);
//        cout << a; 
//        inorder(arr[a].RChild);
//    }
//    else return; 
//}
//
//void postorder(char a) { // 후위 순회
//    if (a != '.') {
//        postorder(arr[a].LChild); 
//        postorder(arr[a].RChild); 
//        cout << a; 
//    }
//    else return; 
//}
//
//int main() {
//    int n;
//    char a, b, c;
//
//    cin >> n;
//    for (int i = 1; i < n + 1; i++) {
//        cin >> a >> b >> c;
//        arr[a].LChild = b; 
//        arr[a].RChild = c; 
//    }
//
//    preorder('A'); // 항상 A가 루트 노드
//    cout << "\n";
//    inorder('A');
//    cout << "\n";
//    postorder('A');
//    cout << "\n";
//}
