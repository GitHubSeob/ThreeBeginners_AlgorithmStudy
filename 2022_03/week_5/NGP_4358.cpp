/*
저번에 진행했던 소수점 출력을 하는 precision(n)을 진행해서 소수점을 출력하게 되면 될듯 싶다.
그리고 map을 활용해서 string을 받으면 +1이 되게 해서 저장후 다 끝나면 나눠서 진행하면 출력값이 나오게 될듯 싶다.

getline(string) -> 공백이 포함된 문자열을 입력받기위해 \n을 구분자로 하기 위해

보통 일반적으로 쓰는 for문이 아닌
*ranged-based for loops and the auto keyword
 for(auto number : fibonacci)
    cout<< number;
이런식으로 예를 들어 auto가 피보나치 배열요소와 같은 자료형을 가지고 auto키워드를 사용하여 c++이 자료형을 추록하도록 한다.
굳이 자료형을 선언하지않고 그냥 auto로 하는것두!

^Z입력 즉, 그만 입력할때까지 하는거.
*/
#include <iostream>
#include <map>
#include <string> //getline

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    map<string, float> percent;
    int size = 0;
    string str;

    while (getline(cin, str))
    {
        if (percent.find(str) != percent.end())
            percent[str] += 1;
        else
            percent[str] = 1;
        size++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto tmp = percent.begin(); tmp != percent.end(); tmp++)
    {
        string str = tmp->first;
        double num = tmp->second;
        num = (num / size) * 100;
        cout << str << " " << num << "\n";
    }
}

/*
while (1)
{
    cin >> str;

    if (str == "\n")
        break;
    else
    {
        if (percent.find(str) != percent.end())
            percent[str] += 1;
        else
            percent[str] = 1;
        size++;
    }
}
*/