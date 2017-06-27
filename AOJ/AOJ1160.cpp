#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,s,e) for(int (i) = (s); (i) < (e); (i)++)
#define debug(x) cout  << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

/* -----  2017/06/27  Problem: ICPC国内予選2009E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

hiziriさんが書いた。
全探索で色付けをして盤面のマスの連結数を求めればよい。

----解説ここまで---- */

int land(vector<vector<int>>& m, int ih, int jw, int h, int w) {
	if (m[ih][jw] == 1) {
		m[ih][jw] = 0;



		if (ih > 0 && jw > 0) land(m, ih - 1, jw - 1, h, w);
		if (ih > 0) land(m, ih - 1, jw, h, w);
		if (ih > 0 && jw + 1 < w) land(m, ih - 1, jw + 1, h, w);
		if (jw > 0) land(m, ih, jw - 1, h, w);
		if (jw + 1 < w) land(m, ih, jw + 1, h, w);
		if (ih + 1 < h && jw > 0) land(m, ih + 1, jw - 1, h, w);
		if (ih + 1 < h) land(m, ih + 1, jw, h, w);
		if (ih + 1 < h && jw + 1 < w) land(m, ih + 1, jw + 1, h, w);

		return 1;
	}

	return 0;
}

const int INF = 1e9;
const ll LINF = 1e16;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		int w, h;
		cin >> w;
		cin >> h;

		if (w == 0 && h == 0)break;

		int ctr = 0;

		vector<vector<int>> Map(h, vector<int>(w));

		FOR(i, 0, h) {
			FOR(j, 0, w) {
				cin >> Map[i][j];
			}
		}

		FOR(i, 0, h) {
			FOR(j, 0, w) {
				ctr += land(Map, i, j, h, w);
			}
		}

		cout << ctr << endl;
	}
	return 0;
}