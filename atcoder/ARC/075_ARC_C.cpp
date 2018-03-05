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

/* -----  2018/03/04  Problem: 075_arc_c / Link: https://arc075.contest.atcoder.jp/tasks/arc075_c?lang=en ----- */
/* ------問題------

長さ N の整数列 a= {a1,a2,…,aN} と、整数 K が与えられます。
a の空でない連続する部分列 {al,al+1,…,ar} (1≤l≤r≤N) は N(N+1)⁄2 個存在します。これらのうち、算術平均が K 以上であるものは何個あるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

平衝二分木がほしいときはBITでだいたいできる

sum(a,L,R)/(L-R+1) >= K は要素の個数がからんで面倒だけど、
数列からKを除いたときは新しい数列の部分列の和が0以上になりますかという問題になる
累積和の引き算で任意の区間を出すやつでO(N^2)にできる
次に累積和の左側の区間に自身よりも小さいものを高速に発見したくなる。
平衝二分木かあと思わなくてもこれはBITと座標圧縮でできて、値を昇順のノードに対応させれば検索が高速にできる。

----解説ここまで---- */
template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};



LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		a[i] -= K;
	}
	VL sum(N + 1, 0);
	FOR(i, 0, N) {
		sum[i + 1] = sum[i] + a[i];
	}

	VL xs(sum);
	SORT(xs);
	UNIQ(xs);
	BIT<LL> bit(SZ(sum));
	FOR(i, 0, SZ(sum)) {
		int id = lower_bound(ALL(xs), sum[i]) - xs.begin();
		ans += bit.sum(id + 1);
		bit.add(id + 1, 1);
	}
	cout << ans << "\n";

	return 0;
}
