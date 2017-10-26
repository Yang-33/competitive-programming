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

/* -----  2017/10/26  Problem: AOJ 0552  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0552&lang=jp ----- */
/* ------問題------

JOI 市では,とある大規模な博覧会を開催することになった.
今回の博覧会には 2 つのテーマがあり,JOI 市にある N 個の展示施設でそれぞれ, 2 つのテーマのうちどちらか一方に沿った展示を行う予定である.
施設の位置は平面座標 (x, y) で表される.位置 (x, y) にある施設から (x′ , y′) にある施設まで移動するためには,
|x － x′| + |y － y′| だけの時間がかかる (整数 a に対して, |a| で a の絶対値を表す).同一テーマ内での統一感を出すため,
および一方のテーマのみに関心を持つ人に不便を感じさせないために,同一のテーマで展示を行っている 2 つの施設の間の移動時間がなるべく短くなるようにテーマを割りふりたい.
すべての展示施設に同じテーマを割りふらない限り, どのようにテーマを割りふってもよい.
同一のテーマで展示を行っている 2 つの施設の間の移動時間の最大値を M とする. N 個の展示施設の位置が与えられたとき, M の最小値を求めるプログラムを作成せよ.

-----問題ここまで----- */
/* -----解説等-----

マンハッタンチャンス！
そのままではチェックにどうしてもO(N^2)かかってしまうが、
マンハッタン距離を軸に平行に取り出すために変換をおこなえば、
組合せでできるmaxの辺をマンハッタン距離にすればいいだけになり、
これはO(N)で検査できる。
軸に平行な要素のmaxなので各軸でそれぞれ独立にできる。
dで二分探索をするところは、
片側に寄せなければならないときに、矛盾が起きていないかも確認しなければならない。(maxをとるので)
マンハッタン距離のちょっとした応用凄い

----解説ここまで---- */
// 距離d以内で二分できるか
bool f(const LL d, const LL Umax, const LL Umin, const LL Vmax, const LL Vmin, const vector<PII>&u, const vector<PII>&v) {
	int N = SZ(v);
	VL dist(N, 0);
	VL rangeu(N, 0), rangev(N, 0);
	//独立にできる
	FOR(i, 0, N) {// u
		if (abs(Umax - u[i].first) > d&&abs(u[i].first - Umin) > d)return false;
		if (abs(Umax - u[i].first) > d)
			rangeu[u[i].second] = 1;
		if (abs(Umin - u[i].first) > d)
			rangeu[u[i].second] = 2;
	}

	FOR(i, 0, N) {// v
		if (abs(Vmax - v[i].first) > d&&abs(v[i].first - Vmin) > d)return false;
		if (abs(Vmax - v[i].first) > d)
			rangev[v[i].second] = 1;
		if (abs(Vmin - v[i].first) > d)
			rangev[v[i].second] = 2;
	}
	// 0 であればこれはどちらにも属せる
	// 1,2 であればこれは片側にしか属せない
	// 1,1 or 2,2 のときは何を表しているか
	// cross かつ not cross なものは存在してはいけない(矛盾になる)

	int left = N;
	int cross = 0;
	FOR(i, 0, N) {
		if (rangeu[i] == 0 || rangev[i] == 0)left--;
		else if (rangeu[i] == rangev[i])cross++;
	}

	if (cross == 0 || left == cross)return true;
	else return false;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL N;
	LL ans = 0LL;
	cin >> N;
	vector<PII> u(N), v(N);
	FOR(i, 0, N) {
		int x, y; cin >> x >> y;
		u[i] = PII(x - y, i);
		v[i] = PII(x + y, i);
	}
	SORT(u);
	SORT(v);
	LL Umax = u.back().first;
	LL Umin = u.front().first;
	LL Vmax = v.back().first;
	LL Vmin = v.front().first;

	LL l = 0; LL r = 1e6;
	while (r - l > 1) {// (l,r]
		LL mid = (l + r) / 2;
		if (f(mid, Umax, Umin, Vmax, Vmin, u, v)) { r = mid; }
		else { l = mid; }
	}
	ans = r;
	cout << ans << "\n";

	return 0;
}
