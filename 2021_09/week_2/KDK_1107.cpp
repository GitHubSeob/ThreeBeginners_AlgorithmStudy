#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int number;
    int delet;
    int T;
    int start = 100;


    vector <int> v = { 10,0 };
    vector <int> v2;
    for(int i=0;i<10;i++)
        v.push_back(i);

    cin >> N;
    cin >> number;
    for (int i = 0; i < number; i++) {
        cin >> delet;
       
    }
    while (N > 0) {
        T = N % 10;
        v2.push_back(T);
        N /= 10;
    }
    int result = 0;
    int result = abs(N - 100);
    for (int i = 0; i < v2.size(); i++) {
         
    }
}
