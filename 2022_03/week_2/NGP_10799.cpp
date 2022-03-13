#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int ans = 0;
    string str;
    cin >> str;

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            //닫는거일때 바로 전에 '('라면  -> 자르는친구.
            //바로전이 '('가 아니라면 -> 파이프 생성.
            s.pop();
            if (str[i - 1] == '(')
                ans += s.size();
            else
                // 파이프를 두번 자르면 3개가 나오게 된다 고로 미리 잘리기전 1개를 항상 추가해준다.
                ans++;
        }
    }
    cout << ans;
}