//문제풀이: https://githubseob.tistory.com/139

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book) {
    int idx(0), idx2(0);
    sort(phone_book.begin(), phone_book.end());
    for (idx = 0; idx < phone_book.size() - 1; ++idx)
        if (phone_book[idx] == phone_book[idx + 1].substr(0, phone_book[idx].size()))
            return false;
    return true;
}