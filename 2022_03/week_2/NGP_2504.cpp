#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    stack<char> s;
    int tf,ans = 0,tmp =1;
    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(')
        {
            tmp *=2;
            s.push('(');
        }
        else if(str[i] == '[')
        {
            tmp *= 3;
            s.push('[');
        }
        else if(str[i] == ')')
        {
            if(s.empty())
            {
                cout<<"0";
                return 0;
            }
            if(s.top() != '(')
            {
                cout<<"0";
                return 0;
            }
            //위에 까지 모든 틀린 조건을 차단 후 바로 전값이 (가 나온다면 더하는 것
            else 
            {
                if(str[i-1]=='(') 
                    ans+= tmp;
                s.pop();
                tmp /= 2;
            }
        }
        else if (str[i] == ']')
        {
            if (s.empty())
            {
                cout << "0";
                return 0;
            }
            if (s.top() != '[')
            {
                cout << "0";
                return 0;
            }
            else
            {
                if (str[i - 1] == '[')
                    ans += tmp;
                s.pop();
                tmp /= 3;
            }
        }
    }
    if(!s.empty())
        cout<<"0";
    else
        cout<<ans;
}