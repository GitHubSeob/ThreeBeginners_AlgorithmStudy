#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string str;
vector<pair<int, int>> twin;
stack<int> t;
vector<string> v;
bool yn[200] = {0,};
void dfs(int idx, int cnt);

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tmp;
    cin >> str;

    //결국 가장 최근에 온 (는 지금 오는 )과 매칭이 된다.
    for (int i = 0; i < str.size(); i++)
    {
        yn[i] = true;
        if (str[i] == '(')
        {
            t.push(i);
        }
        else if (str[i] == ')')
        {
            tmp = t.top();
            t.pop();
            twin.push_back({tmp, i});
            //매칭된 두개의 이 들어감.
        }
    }

    dfs(0, 0);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}

void dfs(int idx, int cnt)
{
    if (idx == (twin.size()))
    {
        if (cnt > 0)
        {
            string sen = "";
            for (int i = 0; i < str.size(); i++)
            {
                if (yn[i] == true)
                    sen += str[i];
            }
            v.push_back(sen);
        }
        return;
    }
    dfs(idx + 1, cnt);
    yn[twin[idx].first] = false;
    yn[twin[idx].second] = false;
    dfs(idx + 1, cnt + 1);
    yn[twin[idx].first] = true;
    yn[twin[idx].second] = true;
}
