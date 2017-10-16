#include "bits/stdc++.h"
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

/* -----  2017/10/16  Problem: nagoya_19_07 JOI2012 予選 2 / Link: http://joi2012yo.contest.atcoder.jp/tasks/joi2012yo_b  ----- */
/* ------問題------

JOI 国ではサッカーが人気であり，JOI リーグというリーグ戦が毎週行われている．
JOI リーグには N 個のチームが所属していて，1 から N までの番号がつけられている．すべての組み合わせの試合がちょうど一度ずつ行われる．つまり， N × (N - 1) / 2 試合が行われる．各試合の勝敗はそれぞれのチームの得点で決まる．勝ったチームの勝ち点は 3 点であり，負けたチームの勝ち点は 0 点である．引き分けの場合，両チームの勝ち点は 1 点である．順位は各チームの獲得した勝ち点の合計で決定し，得失点差は考えない．勝ち点の合計が等しいチームの順位は上位に揃える．
全ての試合の結果が与えられたとき，各チームの順位を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

愚直に書く。

----解説ここまで---- */

LL N;

LL ans = 0LL;
int cnt[102];
int rankin[102];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, (N*(N - 1)) / 2) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--;
		if (c == d)cnt[a]++, cnt[b]++;
		else {
			if (c < d)swap(a, b);
			cnt[a] += 3;
		}
	}
	vector<PLL>v;
	FOR(i, 0, N) {
		v.push_back(PLL(cnt[i], i));
	}
	v.push_back(PLL(-1, -1));
	RSORT(v);
	int s = 0;
	int r = 1;
	FOR(i, 0, N) {
		if (v[i].first == v[i + 1].first)continue;
		else {
			FOR(k, s, i + 1) {
				rankin[v[k].second] = r;
			}
			r+=(i+1-s);

			s = i + 1;

		}
	}
	if (s != N) {
		FOR(k, s, N) {
			rankin[v[k].second] = r;
		}
	}
	FOR(i, 0, N)
		cout << rankin[i] << endl;
	return 0;
}