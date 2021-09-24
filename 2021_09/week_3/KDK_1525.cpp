using namespace std;
#include <stdio.h>
#include <iostream> 
#include <string>
#include <queue>
#include <map>


int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
map<int, int> v;

int bfs(int first) {
	queue<int> q;

	//시작 상태(이동전)
	q.push(first);
	v[first] = 0;

	while (!q.empty()) {


		int now = q.front();
		q.pop();

		//bfs이므로 최초 리턴 값이 최소방문카운트 값이다.
		if (now == 123456789) {
			//map원소에 배열처럼 접근 가능!
			return v[now];
		}

		//현재 map의 정수형태를 문자열로 변환하여 9의 좌표 찾아내기
		string now_str = to_string(now);
		int now_index = now_str.find('9');
		int r = now_index / 3;
		int c = now_index % 3;


		//4방향 탐색
		for (int d = 0; d < 4; d++) {
			//새로운 좌표 구하기
			int nr = r + dx[d];
			int nc = c + dy[d];
			int new_index = nr * 3 + nc;


			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 3)continue;

			//새로운 좌표에 따른 새로운 map구하기
			//이전 9좌표 <-> 새로운 9좌표
			string new_str = now_str;
			char tmp = new_str[new_index];
			new_str[new_index] = new_str[now_index];
			new_str[now_index] = tmp;


			int new_int = atoi(new_str.c_str());
			//못찾았으면=방문안했으면
			if (v.find(new_int) == v.end()) {
				//방문하기
				v[new_int] = v[now] + 1;
				q.push(new_int);
			}



		}
	}
	return -1;
}

int main() {


	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int first = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 0)tmp = 9;
			first = (first * 10) + tmp; //자리수를 하나 올리고 1의 자리에 해당 숫자가 올라가게
			//123456789의 형태가 되도록함
			//1 = > 12 = > 123= > 1234

		}
	}
	cout << bfs(first);





	return 0;

}
