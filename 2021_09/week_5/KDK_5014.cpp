#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    for (int count = 0; count < F; count++) {
        if (S == G) {
            cout << count;
            return 0;
        }
        if (S + U > F && S - D < 1) break;
        if (S < G && S + U <= F) S += U;
        else if (!(S <= G && S - D < 1)) S -= D;
    }
    cout << "use the stairs";
}