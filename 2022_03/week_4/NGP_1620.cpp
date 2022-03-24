/*
1) map이란
map은 각 노드가 key와 value가 쌍으로 이루어진 트리이고 중복을 허용하지 않는다.
map은 first,second가 있는 쌍인 객체로 저장이 되는데 first - key로 second - value로 저장이 되는것이 특징이다.
레드블랙트리로 구성되어있고 내부 구현은 검색, 삽입,삭제 O(logn)이다.

2) unorderd_map이란
map 보다 더 빠른 탐색을 위한 자료구조 이고 중복된 데이터를 허용하지 않고 더 좋은 하지만 key가 유사한 데이터가 많을시에는 해시충돌로 인해 성능이 떨어질수도 있다는 단점이 있다.
-empty(), size(), operator[], find(key), count(key), insert({key,value}), erase(key), clear(), operator= 가 대표적인 기능.
사용을 할때는 unordered_map이라는 라이브러리 첨가

동균이꺼 봤는데 
#include <ctype.h>
로해서 isalpha(s[0])이런식으로 하면 알수도 있음.
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    unordered_map<string, int> patoi;
    unordered_map<int, string> pitoa;
    string str;
    int tmp;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        patoi.insert(make_pair(str, i));
        pitoa.insert(make_pair(i, str));
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> str;
        if ('0' <= str[0] && str[0] <= '9')
        {
            tmp = stoi(str);
            cout << pitoa[tmp] << "\n";
        }
        else if ('A' <= str[0])
        {
            cout << patoi[str] << "\n";
        }
    }
}
