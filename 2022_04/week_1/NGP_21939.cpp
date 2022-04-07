/*
문제번호 난이도
recommend x -> x가1인경우 가장 어려운거 -1인경우 가장 쉬운번호
add P L     -> 난이도가L인 문제번호 P를 추가
solved P    -> 문제P 제거

벡터를 이용해서 recommend 1/-1은 우선순위 큐가 가장 좋을듯 쉽듯 하다.
하지만 문제 p를 제거하는것이 문제이다.
우선순위 큐로 푸는데 저번 처럼 오름차순 내림차순을 두개 저장하야할듯싶다.
정렬은 난이도 순서로 해야할듯

문제를 제거하게 되면 별도의 배열을 이용하여 기록을 해준다.
그럼으로써 우리가 우선순위 큐를 이용해서 못찾는 대참사를 피해준다.
그게 뭔소리냐 즉, 만약 내가 선언한 배열의 문제값이 뭐 특정값이 된다면 그 값은 그냥 무시하고 pop을 하면 되는것이다.
계속 봤지만 뭔가 키워드가 부족할거같아서 검색을하여 잠시 쓱 봤다. 
다른 풀이들을 구경해보니 multiset을 이용하여 푸는데 이부분에 대해서 모르니 set라이브러리에 대해서 확실하게 공부한후에 내껄로 만들자
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, p, l; // p:문제번호 l:문제 난이도
    cin >> n;
    priority_queue<pair<int, int>> MAX;                                                  //내림차순
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MIN; //오름차순
    int arr[100001]={0,};

    for (int i = 0; i < n; i++)
    {
        cin >> p >> l;
        MAX.push({l,p});
        MIN.push({l,p});
        arr[p]=l;
    }

    cin >> m;
    int num1, num2;
    string str;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (str == "add")
        {
            cin >> num1 >> num2;
            MAX.push({num2,num1});
            MIN.push({num2,num1});
            arr[num1]=num2;
        }
        else if (str == "solved")
        {
            cin >> num1;
            arr[num1]=0;
        }
        else if (str == "recommend")
        {
            cin >> num1;
            if (num1 == 1)
            {
                while(MAX.top().first != arr[MAX.top().second])
                    MAX.pop();
                cout<<MAX.top().second<<"\n";
            }
            else if (num1 == -1)
            {
                while(MIN.top().first != arr[MIN.top().second])
                    MIN.pop();
                cout<<MIN.top().second<<"\n";
            }
        }
    }
}

/*
//진섭이 풀이 보고 공부하기
#include <iostream>
#include <set>
#include <map>
using namespace std;

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second)
			return a.first > b.first;

		else
			return a.second > b.second;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	int idx(0);

	map<int, int>m;
	multiset<pair<int, int>, cmp>problem;	
	multiset<pair<int, int>, cmp>::iterator iter;

	int number(0), level(0);
	string cmd("");

	cin >> N;

	for (idx = 0; idx < N; ++idx) {
		cin >> number >> level;
		problem.insert({ number, level });
		m.insert({ number, level });
	}
	
	cin >> M;

	for (idx = 0; idx < M; ++idx) {
		cin >> cmd;
		if (cmd == "recommend") {
			cin >> number;
			if (number == 1) {
				iter = problem.begin();
				cout << iter->first;
			}
			else {
				iter = --problem.end();
				cout << iter->first;
			}
			cout << '\n';
		}
		else if (cmd == "add") {
			cin >> number >> level;
			problem.insert({ number, level });
			m.insert({ number,level });
		}
		else {
			cin >> number;
			level = m[number];			
			problem.erase({number, level});
			m.erase(number);
		}
	}	
}
*/