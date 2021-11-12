//효율성에서 모두 실패
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            if (phone_book[i] == phone_book[j].substr(0, phone_book[i].size()))
                answer = false;
        }
    }

    return answer;
}


/*
다른 사람들의 코드를 참조했다.
string이기 때문에 정렬을 진행할 경우 사전순으로 정렬이 된다는 것이다.
사전순으로 정렬이 되므로 인접 원소만 비교를 하면 된다는 것이다.
*/


#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            answer = false;
    }

    return answer;
}