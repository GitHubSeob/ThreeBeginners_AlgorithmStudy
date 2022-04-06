/*
즉 자기가 쏜 레이저가 누구한테 맞냐는 문제인듯 싶다.
지금 내가 쐇을때 왼쪽에 나보다 큰 친구가 있어서 정리를 하면 될듯 싶다.
를 했는데 60퍼대 에서 시간초과가 뜬다. 그런다면 나는 어떻게 할수 있을까?
그전까지 있던 타워들중에서 가장 큰값이 있다면 그 왼쪽에 있는것들은 측정할 필요가 없다. -> max를 둬서 max까지 해서 안된다면 그거는 0
if (tmp > max)
{
    max = tmp;
    turn = i;
}
를 넣어서 시간을 줄여보자. 그래도 61퍼 초과.. 에라이
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    int n;
    stack<pair<int,int>> s;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        int turn = i;

        if(!s.empty())
        {
            while(s.top().second<tmp)
            {
                s.pop();
                if(s.empty())
                    break;
            }
        }
        if(s.empty())
            cout << "0 ";
        else
            cout<<s.top().first<<" ";
        s.push({turn, tmp});
    }
}



/*
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> ans;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, tmp;
    //cin>>n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int zero = 1;
        int max = 0;
        int turn = 0;
        //cin >> tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
        for (int j = v.size() - 2; j >= turn; j--)
        {
            if (tmp < v[j])
            {
                zero = 0;
                ans.push_back(j + 1);
                break;
            }
        }
        if (zero == 1)
            ans.push_back(0);
        if (tmp >= max)
        {
            max = tmp;
            turn = i;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ",ans[i]);
    }
}
*/