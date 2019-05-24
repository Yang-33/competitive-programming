#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/22  Problem: ARC 017 D / Link: http://arc017.contest.atcoder.jp/tasks/arc017_d  ----- */
/* ------問題------

私はとあるクッキー工場に勤めている。
この工場では「ARCたんクッキー」というかわいいクッキーを作っている。
この工場には N 個のARCたんクッキー製造機があり、製造機には 1 から N まで番号がついている。製造機ごとに異なるフレーバーが設定されているため、異なる製造機から作られたクッキー同士は区別される。また製造機ごとに一度に生成するクッキーの量が設定されている。製造機は指定された製造数のクッキーを一度に全て生成する。
この度、私が勤めている工場では、M 日間、工場見学ツアーを実施することになった。それぞれの日には次のいずれかの作業が実行される。
見学ツアーを実施する。ツアーではそれぞれの日ごとに定められた、ある連続した番号の製造機をちょうど 1 回ずつ稼働させ、それらの製造機が生成したクッキー全てをお土産としてツアー参加者に配る予定である。
メンテナンスを実施し、それぞれの日ごとに定められた、ある連続した番号の製造機の製造数を一定数増減させる。
工場はとても広く迷子になりやすいので、それぞれのツアー実施日内ではツアー客の定員を固定することになっている。
ここの工場長は割り切れないことを好まず、どの製造機から作られたクッキーもその日参加した全てのツアー客に同数ずつ配らなければ気が済まない。また、ARCたんクッキーの一部を配らない、砕くなどかわいそうなことはしてはならない。つまり、作ったクッキーは全てツアー客に平等に配らなければならない。一方でこの工場の宣伝のため、このような条件を満たしつつできるだけ多くのツアー客を受け入れたいと考えている。
立案者である私は、それぞれのツアー実施日において、1 回あたりのツアーに参加できるツアー客の最大値を求めることになった。しかしながら私は新しいフレーバー開発に忙しい。そこであなたに是非ともこの問題を解いてもらいたい。

-----問題ここまで----- */
/* -----解説等-----

区間add/区間gcdQueryの捌き方をかんがえる。
addする間にgcdを計算するのは結構厳しそう。


[やるべきこと]
差分を取る
不変量に着目する
うくにきあ

----解説ここまで---- */

template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = Monoid::upd(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return Monoid::id(); nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i] << " "; cerr << "\n"; }
};

struct Monoid {
	using type = LL;
	static type id() { return 0; }
	static type op(const type&l, const type&r) {
		return __gcd(l, r);
	}
	static type upd(const type&l, const type&r) {
		return l + r;
	}
};
template<class T>
struct RaBIT {
	int n; vector<T> bit0, bit1;
	RaBIT(int sz) :n(sz), bit0(n + 1, 0), bit1(n + 1, 0) {}

	T subsum(vector<T>& bit, int i) {
		T s = 0; while (i > 0) { (s += bit[i]); i -= i & -i; }return s;
	}
	void add(vector<T>& bit, int i, T x) {
		while (i <= n) { (bit[i] += x); i += i & -i; }
	}
	void rangeadd(int a, int b, T x) {
		a++; add(bit0, a, -(x * (a - 1))); add(bit1, a, x); add(bit0, b + 1, x * b); add(bit1, b + 1, -x);
	}
	T query(int a, int b) {
		a++; return ((subsum(bit1, b) * b + subsum(bit0, b)) - (subsum(bit1, a - 1) * (a - 1) + subsum(bit0, a - 1)));
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	SegmentTreeFastAry<Monoid> seg(N);
	RaBIT<LL>segsum(N);
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	segsum.rangeadd(0, 1, a[0]);
	FOR(i, 1, N) {
		seg.update(i, a[i] - a[i - 1]);
		segsum.rangeadd(i, i + 1, a[i]);
	}
	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int t, l, r; cin >> t >> l >> r;
		l--, r--;
		if (t == 0) {
			auto Front = segsum.query(l, l + 1);
			auto gcsq = seg.query(l + 1, r + 1);
			cout << abs(__gcd(Front, gcsq)) << endl;
		}
		else {
			segsum.rangeadd(l, r + 1, t);
			// [l..r]
			// [0[1,2,..,N-1]
			//   [10,21,..,]
			seg.update(l, t);
			seg.update(r + 1, -t);

		}
	}

	return 0;
}
