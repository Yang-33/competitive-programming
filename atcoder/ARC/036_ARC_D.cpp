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

/* -----  2018/10/24  Problem: ARC 036 D / Link: http://arc036.contest.atcoder.jp/tasks/arc036_d  ----- */
/* ------問題------

高橋くんはマラソン大会の主催者で、今度開くマラソン大会の計画案を練っています。 高橋くんの住む街には東西と南北に伸びるそれぞれ 106 本の道があり、南北に伸びる道のうち西から x 番目の道と、東西に伸びる道のうち南から y 番目の道が交わる交差点を (x,y) と表します。
マラソンコースの作りを簡単にするため、道は東か北の方向へのみ進めるようにしました。 高橋くんはマラソンコースで参加者のタイム計測に使える場所として、N 個のチェックポイント (pi,qi) を決めました。
高橋くんの街では、参加者はマラソン大会で一人ひとりが違った経路を取りたがるため、コースの異なる経路の数が重要です。 タイム計測の必要から、チェックポイント u からチェックポイント v(u<v) までマラソンコースを設定したとき、u≦i≦v となるチェックポイント i 全てを参加者は通る必要があります。
そこで、高橋くんは以下の Q 個のクエリに答える必要があります。
kj 番目のチェックポイントの場所を (aj,bj) に変更する。
チェックポイント l1j からチェックポイント r1j までの異なる経路の総数と、チェックポイント l2j からチェックポイント r2j までの異なる経路の総数のうち、どちらが大きいかを判定する。ただし、経路の数のうち多い方は、少ない方の 2 倍以上はあることが保証される。
高橋くんを助けるためのプログラムを書いてください。

-----問題ここまで----- */
/* -----解説等-----

2倍とか使ってないので誤差とかがダメそう
できた。
組合せが変わると積が変わる。
これの大小のみわかれば良い。実際にx!の積をもつのは計算機的にはダメなので、
対数として持つ。
あとは区間総積がわかればよいので、segtreeにのせればよい。

----解説ここまで---- */

template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
	int init(int n) { int sz = 1; while (sz < n) sz <<= 1; return sz; }
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(init(n)), node(2 * ARY_SIZE, Monoid::id()) {}
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = Monoid::upd(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return nd(); nd vl = nd(), vr = nd();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " "; cerr << "\n"; }
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	struct MonoidD {
		using type = long double;
		static type id() { return (long double)0; }
		static type op(const type&l, const type&r) {
			DD(de("merge:", l, r));
			return l + r;
		}
		static type upd(const type&l, const type&r) {
			DD(de("update:", l, r));
			return r;
		}
	};
	const int sz = 2e6 + 6;
	vector<long double>LogFactorial(sz, 0);
	FOR(i, 2, sz) {
		LogFactorial[i] = LogFactorial[i - 1] + logf(i);
	}
	DD(
		Detail(LogFactorial, 40);
	);
	SegmentTreeFastAry<MonoidD> seg(N);
	VI p(N), q(N);
	FOR(i, 0, N) {
		cin >> p[i] >> q[i];
	}
	// 積->和として考えていることに注意すること
	auto comb = [&LogFactorial](int x, int y) {
		return LogFactorial[x + y] -( LogFactorial[x] + LogFactorial[y]);
	};
	// 0=[0:1] 1=[1:2]
	FOR(i, 1, N) {
		int dx = p[i] - p[i - 1];
		int dy = q[i] - q[i - 1];
		DD(
			de(i, dx, dy, comb(dx, dy));
		);
		seg.update(i - 1, comb(dx, dy));
	}

	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int t; cin >> t;
		//DD(seg.debugshow());
		if (t == 1) {
			int k, a, b; cin >> k >> a >> b;
			k--;
			p[k] = a;
			q[k] = b;
			if (k > 0) {// pre
				int dx = p[k] - p[k - 1];
				int dy = q[k] - q[k - 1];
				seg.update(k - 1, comb(dx, dy));
			}
			if (k < N - 1) {// nx
				k++;
				int dx = p[k] - p[k - 1];
				int dy = q[k] - q[k - 1];
				seg.update(k - 1, comb(dx, dy));
			}

		}
		else {
			int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
			l1--, r1--, l2--, r2--;
			DD(de(l1, r1, l2, r2));
			long double A = seg.query(l1, r1);
			long double B = seg.query(l2, r2);
			DD(de(A, B);)
				cout << (A > B ? "FIRST" : "SECOND") << endl;
		}
	}

	return 0;
}
