#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    //앞뒤 모두 사용을 위해서 큐가 아니라 덱을 사용해야함!
    //벡터로 선언해서 앞지우고 뒤에 추가 뒤 지우고 앞에 추가하면서 벡터의 맨앞 원소를 출력하는거로도 한번 풀어보자 어차피 같을듯.
    //*아니면 만약에 숫자가 덱의 크기보다 크다면 주어진숫자 % 덱의 크기 = a 를해서 a만큼만 움직이는게 더 효율적일듯?
    deque<pair<int,int>> dq;
    int n,tmp;
    cin >> n;
    for(int i=1; i<=n;i++){
        cin>>tmp;
        dq.push_back({i,tmp});
    }
    while(!dq.empty())
    {
        int move = dq.front().second;
        cout<<dq.front().first<<" ";
        dq.pop_front();
        if(move >0)
        {
            for(int i = 0; i< move -1 ;i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (move < 0)
        {
            for(int i = 0;i < -move;i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}