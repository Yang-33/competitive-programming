#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/12  Problem: AOJ 1136  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1136&lang=jp ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

(x,y)->(y,-x)

----解説ここまで---- */

ll N;
ll m[55];
int x[55][15];
int y[55][15];


void reg(int s, int t) {//正規化0
	FOR(i, s, t) {
		int cx = x[i][0];
		int cy = y[i][0];
		FOR(j, 0, m[i]) {
			x[i][j] -= cx;
			y[i][j] -= cy;
		}
	}
}

void reg2(int s, int t) {//正規化m[i]-1
	FOR(i, s, t) {
		int cx = x[i][m[i] - 1];
		int cy = y[i][m[i] - 1];
		FOR(j, 0, m[i]) {
			x[i][j] -= cx;
			y[i][j] -= cy;
		}
	}
}

bool check(int s, int t) {
	bool f = 0;
	if (m[s] == m[t]) {
		FOR(k, 0, 4) {
			f = 1;
			FOR(i, 0, m[s]) {
				int sx = x[s][i];
				int sy = y[s][i];

				int tx = x[t][i];
				int ty = y[t][i];

				int tm;
				FOR(kk, 0, k + 1) {
					tm = tx;
					tx = ty;
					ty = -tm;
				}
			//	cout << "x: " << tx << " ty: " << ty << endl;

				if (!(tx == sx&&ty == sy)) f = 0;
				
			}
			if (f)return 1;
		}
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for (;;) {
		cin >> N;
		if (N == 0)break;

		FOR(i, 0, N + 1) {
			cin >> m[i];
			FOR(j, 0, m[i]) {
				cin >> x[i][j] >> y[i][j];
			}
		}

		set<int >s;
		reg(0, N + 1);

		FOR(i, 1, N + 1) {
			if (check(0, i))
				s.insert(i);
		}

		reg2(1, N + 1);
		FOR(i, 1, N + 1) {
			if (check(0, i)) {
				s.insert(i);
			}
		}
		for (auto it = s.begin(); it != s.end(); it++) {
			cout << *it << endl;
		}
		cout << "+++++" << endl;
	}
	return 0;
}
