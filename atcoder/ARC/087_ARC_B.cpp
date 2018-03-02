#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/03/02  Problem: 087_arc_b / Link: https://abc082.contest.atcoder.jp/tasks/arc087_b?lang=en  ----- */
/* ------問題------

二次元平面の原点にロボットが置かれています。 最初、ロボットは x 軸の正の向きを向いています。
このロボットに命令列 s が与えられます。 s は次の 2 文字のみからなり、先頭から末尾まで順に実行されます。

F : 今向いている向きに長さ 1 だけ移動する。
T : 時計回りまたは反時計回りの好きな方向に 90 度だけ向きを変える。
ロボットの目標は、命令列をすべて実行し終わった後に座標 (x,y) にいることです。 この目標が達成可能か判定してください。

-----問題ここまで----- */
/* -----解説等-----

列を成分ごとに分解するとこれは典型DP
dp(i,j):=i個終えたときに値jが存在する
負の値も存在するけどこれは下駄をはかせればよい。
自分の入力生成が間違ってそう…

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int x, y;
	cin >> x >> y;
	VI xs(SZ(s)), ys(SZ(s));
	int xp = 0, yp = 0;
	int mode = 0;
	FOR(i, 0, SZ(s)) {

		if (mode == 0) {// x
			if (s[i] == 'T') { mode = 1; xp++; continue; }
			else {
				xs[xp]++;
			}
		}
		else {//y
			if (s[i] == 'T') { mode = 0; yp++; continue; }
			else {
				ys[yp]++;
			}

		}
	}
	if (mode == 0) {// x
		{ mode = 1; xp++; }
	}
	else {//y
		{ mode = 0; yp++; }
	}

	//FOR(i, 0, xp) {
	//	cout << xs[i] << " ";
	//}cout << endl;
	//FOR(i, 0, yp) {
	//	cout << ys[i] << " ";
	//}cout << endl;

	// dp
	vector<vector<bool>> dpx(8000, vector<bool>(20000));
	vector<vector<bool>> dpy(8000, vector<bool>(20000));
	dpx[0][xs[0] + 10000] = 1;
	dpy[0][ys[0] + 10000] = 1;
	dpy[0][-ys[0] + 10000] = 1;

	FOR(i, 0, xp) {
		FOR(j, 0, 20000) {//10000 base
			if (dpx[i][j]) {
				dpx[i + 1][j - xs[i + 1]] = 1;
				dpx[i + 1][j + xs[i + 1]] = 1;
			}
		}
	}
	FOR(i, 0, yp) {
		FOR(j, 0, 20000) {//10000 base
			if (dpy[i][j]) {
				dpy[i + 1][j - ys[i + 1]] = 1;
				dpy[i + 1][j + ys[i + 1]] = 1;
			}
		}
	}
	if (dpx[xp][10000 + x] && dpy[yp][10000 + y]) {
		cout << "Yes" << endl;
	}
	else cout << "No" << "\n";

	return 0;
}
