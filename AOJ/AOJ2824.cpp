#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/07/12  Problem: AOJ 2824  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2824  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

本番ではひじりさんが解いた。
地点Lについてだけ着目し、乾いていくごとに湿り気が残っていれば答えのカウンタを１増やしていけばよい。

----解説ここまで---- */

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	int T, D, L;

	while (cin >> T && cin >> D && cin >> L) {
		if (T == 0 && D == 0 && L == 0) return 0;

		int sum = 0;
		int wet = 0;
		int time = 0;
		int wave;

		for(int i = 0; i < T; i++) {
			cin >> wave;

			if (wet == 0) {
				sum += time;
				time = 0;
			}
			else if (wet > 0){
				time++;
				wet--;
			}

			if (wave >= L) { // wave reached
				wet = D;
			}
		}
		sum += time;

		cout << sum << endl;
	}
}