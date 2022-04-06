/*
일단은 괄호 혹은 연산자들과 // 변수들을 구분하는것이 포인트라고 생각한다.
처음에 변수들이 나오게 된다면 ans + 변수 이렇게 하면 될듯 싶다.
그리고 '('일때를 먼저 체크하고 사칙연산에서는 '*'과'/'가 우선적으로 되기 때문에 이것을 먼저 고려해야할듯 싶다.
그리고 ')'가 나오게 된다면 (가 나올때까지 전부다 pop을 하는 형태로 가는것?
결국 누구가 누구의 짝이냐가 이 문제의 핵심인듯 싶다.
*랑 /는 탑에 얘네들이 올때까지 그리고+랑 -는 (가 올때까지 )도 (가 올때까지 +,-는 push // )는 팝
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string str, ans;
    cin >> str;
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        if (65 <= str[i] && str[i] <= 90)
        {
            ans += str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top()=='/'))
            {
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == ')')
        {
            while (!s.empty() && (s.top() != '('))
            {
                ans += s.top();
                s.pop();
            }
            if(str[i] == ')')
                s.pop();
            else
                s.push(str[i]);
        }
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout << ans;
}