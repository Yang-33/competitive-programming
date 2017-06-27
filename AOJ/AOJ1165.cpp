#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int (i) = (s) ;(i) < (e) ;(i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC国内予選2010 A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp  ----- */
/* ------問題------

ある条件によて作成される盤面を覆う最小の長方形の面積

-----問題ここまで----- */
/* -----解説等-----

盤面を形成してから、上下左右の最大最小の値を考えればよい。

----解説ここまで---- */

int masu[600][600];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void init() {
	FOR(i, 0, 600)FOR(j, 0, 600)masu[i][j] = 0;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (1) {
		init();
		map<int, pii>mp;
		int N;
		cin >> N;
		if (N == 0)break;
		mp[0] = pii(300, 300);
		masu[300][300] = 1;
		FOR(i, 0, N-1) {
			int num; int dir;
			cin >> num >> dir;
			pii s = mp[num];
			int y = s.first + dy[dir];
			int x = s.second + dx[dir];
			masu[y][x] = 1;
			mp[i + 1] = pii(y, x);
		}
		int xM = 0,xm=INF;
		FOR(i, 0, 600) {
			FOR(j, 0, 600) {
				if (masu[i][j]) {
					xM = max(xM, j);
					xm = min(xm, j);
				}
			}
		}

		int yM = 0, ym = INF;

		FOR(i, 0, 600) {
			FOR(j, 0, 600) {
				if (masu[i][j]) {
					yM = max(yM, i);
					ym = min(ym, i);
				}
			}
		}

		cout << xM-xm+1 << " " << yM-ym+1 << endl;
	}
	return 0;
}