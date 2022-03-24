/*
내가 앞으로 해야할것
-> map이랑 친해지기. vector로 find로 하는것이 아니고 map을 datastructure푸는 파트에서는 더더욱 친해져서 앞으로도 적극 활용하기
-> map과 unorderedmap에 대해서 차이점을 명확히 알기
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    string str;
    map<string, int> sc;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        sc[str] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (sc[str] == 1)
            ans++;
    }
    cout << ans;
}