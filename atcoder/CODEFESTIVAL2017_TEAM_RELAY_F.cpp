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

/* -----  2017/12/04  Problem: codefestival2017_team_relay F / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_f  ----- */
/* ------問題------

東西方向に伸びる細長い森に N 匹のけものが生息しています。以下では、森の西端から p メートルの地点を地点 p と呼びます。西から i 匹目にいるけもの (1≤i≤N) は地点 xi におり、捕獲すると si 円で売れます。
あなたは整数 L, R (L≤R) を選び、地点 L から地点 R までの両端を含む範囲、[L,R] に網を放ちます。すると、その範囲内のけものがすべて捕獲されます。ただし、網に R−L 円のコストがかかり、あなたの利益は (捕獲されたすべてのけもの i に対する si の合計)−(R−L) 円となります。
網を一度だけ放つとき、得られる最大の利益はいくらでしょうか？

-----問題ここまで----- */
/* -----解説等-----

Sのある場所について累積和を取ると、区間を定める問題に落ちる。
したがってcum[R]-cum[L]を最大化すればよい。これを愚直にやるとO(N^2)だが、
ある点を選択して右側の区間を選択する、と考えればセグ木が使えて、O(NlogN)とかになる。

----解説ここまで---- */

template<typename type>
struct SegTree {
	type INIT_VAL = -1e17; // 影響のない値
	inline type merge(type a, type b) { //台数構造
		return max(a, b); //merge部分
	}
	int N;	vector<type> dat;

	SegTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<type>(N * 2 - 1, INIT_VAL);
	}
	SegTree(vector<type> &a, int _N) {//なにかしらで初期化できるならする。(クエリが後でも処理できるときなど)
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<type>(N * 2 - 1, INIT_VAL);
		for (int i = 0; i < _N; ++i)dat[i + N - 1] = a[i];
		build();
	}
	~SegTree() { vector<type>().swap(dat); }

	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }

	void update(int k, type val) {
		k += N - 1;
		dat[k] = val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); // merge
		}
	}
	// 区間[a,b)の評価
	type query(int a, int b, int k, int l, int r) {
		//if (r == -1)r = N;
		if (r <= a || b <= l)return INIT_VAL; // 区間が被らない 
		if (a <= l&&b >= r)return dat[k]; // 値を返す
		type v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		type v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(v1, v2); //merge
	}

	inline type query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};



LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	SegTree<LL> seg(N + 10);
	VL x(N, 0); VL s(N, 0);
	VL cum(N + 1, 0);
	FOR(i, 0, N) {
		cin >> x[i] >> s[i];
		cum[i + 1] = cum[i] + s[i] - (i > 0 ? x[i] - x[i - 1] : 0);
		//debug(cum[i+1]);
		ans = max(ans, s[i]);
		seg.update(i, cum[i + 1]);
	}
	FOR(i, 0, N) {
		LL ret = seg.query(i, N) - (cum[i + 1]) + (s[i]);
		//debug(ret);
		ans = max(ans, ret);
	}

	cout << ans << "\n";

	return 0;
}
