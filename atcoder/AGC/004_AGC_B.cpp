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

/* -----  2018/02/23  Problem: 004_agc_b / Link: https://agc004.contest.atcoder.jp/tasks/agc004_b?lang=en  ----- */
/* ------問題------

高橋君は異世界に住んでいます。 この世界には N 色のスライムがいます。 最初、高橋君はどの色のスライムも飼っていません。 高橋君の目標は、全色のスライムを一緒に飼うことです。
高橋君は次の 2 種類の操作を行えます。
今飼っていないスライムの色 i (1≤i≤N) をひとつ選ぶ。 色 i のスライムを捕まえて飼う。 この操作には ai 秒掛かる。
魔法を唱える。 すると、今飼っている各スライムについて、色 i (1≤i≤N−1) のスライムは色 i+1 へ変色する。 ただし、色 N のスライムは色 1 へ変色する。 この操作には x 秒掛かる。
高橋君が全色のスライムを一緒に飼うためには、最短で合計何秒掛かるかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

K回シフト動作を行うとすると、色iを得るためにはi-k~iのスライムのうち最小のものを獲れば良い。
k,iは探索するとして最小値を取る動作はsegmenttreeとかで高速にできるので解ける。

----解説ここまで---- */

template<typename type>
struct SegTree {
	type INIT_VAL = INT_MAX;
	inline type merge(type a, type b) {
		return min(a, b);
	}
	int N;	vector<type> dat;

	SegTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<type>(N * 2 - 1, INIT_VAL);
	}
	~SegTree() { vector<type>().swap(dat); }

	void update(int k, type val) {
		k += N - 1;
		dat[k] = val;
		while (k) {
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	type query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INIT_VAL;
		if (a <= l&&b >= r)return dat[k];
		type v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		type v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(v1, v2);
	}

	inline type query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};

LL N, X;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> X;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SegTree<LL>seg(2 * N);
	FOR(i, 0, N) {
		seg.update(i, a[i]);
		seg.update(N + i, a[i]);
	}

	ans = LINF;
	FOR(k, 0, N) {
		LL ret = X*k;
		FOR(i, 0, N) {
			ret += seg.query(i - k + N, i + N + 1);
		}
		ans = min(ans, ret);
	}

	cout << ans << "\n";

	return 0;
}
