#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    queue<int> q;

    for(int i=1; i<=n;i++){
        q.push(i);
    }

    while(!q.empty())
    {
        if(q.size() == 1){
            cout << q.front();
            q.pop();
            break;
        }
        int tmp;
        q.pop();
        tmp = q.front();
        q.push(tmp);
        q.pop();
    }

}