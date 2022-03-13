#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, tmp;
    string str;
    cin >> n;
    cin >> str;
    vector<int> v;
    stack<double> s;
    double s1, s2, ans;

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            s1 = s.top();
            s.pop();
            s2 = s.top();
            s.pop();
            if (str[i] == '+')
                s.push(s2 + s1);
            else if (str[i] == '-')
                s.push(s2 - s1);
            else if (str[i] == '/')
                s.push(s2 / s1);
            else
                s.push(s2 * s1);
        }
        else
            s.push(v[str[i] - 65]);
    }
    ans = s.top();
    //printf("%.2f", &ans); -> 물론 이렇게 c를 활용 가능 그치만 c++한번 사용하면
    cout<<fixed;
    cout.precision(2);
    cout<<ans<<"\n";
}

/*
const double dNum = 1234.56789;

// 1
cout << dNum << endl;

// 2
cout.precision(5);
cout << dNum << endl;

// 3
cout << fixed;
cout.precision(6);
cout << dNum << endl;

// 4
cout.unsetf(ios::fixed);
cout << dNum << endl;

// 5
cout.setf(ios::fixed);
cout.precision(5);
cout << dNum << endl;
cs


[출력 결과]

1234.57

1234.6

1234.567890

1234.57

1234.56789



1) 아무런 설정 없이 출력했을 때, 전체 자릿수가 6으로 고정되는 것을 알 수 있다.

C++ 역시 출력할 때 자동으로 반올림되는 것을 알 수 있다.



2) 자릿수를 조정하는 함수이다.

precision(5) = 전체 자릿수를 5로 조절했기 때문에 1234.6이 출력된 것을 알 수 있다.



3) "cout << fixed"라는 표현은 소숫점 아래 값을 고정하는 표현이다.

즉, cout << fixed 이후에 precision(6)을 입력하면 소숫점 아래를 6으로 고정한다.



4), 5)

"cout << fixed"라는 표현은 cout.setf(ios::fixed); 로 사용할 수도 있다.

setf와 반대되는 표현이 unsetf이다. (설정 해제)

3번에서 소수점 아래 자릿수를 6으로 고정했고

4번에서 이 설정을 해제하고

5번에서 소수점 아래 자릿수를 5로 고정했다.

*/