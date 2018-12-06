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

/* -----  2018/12/06  Problem: ARC 008 D / Link: http://arc008.contest.atcoder.jp/tasks/arc008_d  ----- */
/* ------問題------

あなたのたこ焼き屋さんは試食イベントのおかげもあり、とても繁盛しました。
喜んだ高橋社長は全国展開するために、工場で冷凍たこ焼きの生産をすることを決めました。
高橋社長がたこ焼き生産のために買ってきた機械の 1 つにタコヤキオイシクナールという機械があります。
このタコヤキオイシクナールはトンネルの形をした N 個のボックスからできています。
それぞれのボックスはベルトコンベアで一直線に接続されており、i(1≦i≦N−1) 番目のボックスの出口が i+1 番目のボックスの入り口に繋がっています。
ボックスにはそれぞれ 2 つの実数 (a,b) が書かれており、美味しさ r のたこ焼きを入れると不思議なことに美味しさが a×r+b に変化します。
図 1 はタコヤキオイシクナールにたこ焼きを入れた図です。
(2,1) と書かれたボックスを美味しさ 1 のたこ焼きが通過すると美味しさは 2×1+1=3 に変化し、さらに次の (−1,2) と書かれたボックスを通過すると 3 から −1 へと美味しさが変化します。

図：美味しさ 1 のたこ焼きを 1 個、タコヤキオイシクナールに載せた場合の美味しさの変化
最初ボックスに書かれている数字は全て (1,0) になっておりたこ焼きは N 個のボックスを通過しても美味しさが変化しない状態でした。
そこで、あなたは美味しさ 1 のたこ焼きを 1 個ずつタコヤキオイシクナールに入れてみることにしました。
しかし、ボックスの数字を M 回いたずら好きの高橋社長が変更してしまいました。
美味しさが保障できないと出荷ができません。出来上がったたこ焼きの美味しさの最小値と最大値を求めなさい。
なお、タコヤキオイシクナールは同時に 1 個分のたこ焼きしか加工することができず、タコヤキオイシクナールが加工を行なっている間に高橋社長が任意のボックスの数字を変更することはありません。
つまり、高橋社長がボックスの数字を変更することができるのは、たこ焼きが出来上がってから次のたこ焼きをあなたがタコヤキオイシクナールのベルトコンベアに乗せるまでの間です。
また、その間に高橋社長が複数のボックスの数字を変更することはないものとする。

-----問題ここまで----- */
/* -----解説等-----

ax+bの合成。
これはモノイドであることがよく知られている。
nx = a1x+b1 → a2(nx)+b2としたとき、
xを後で入力できるようにしておく。
するとa2(a1x+b1)+b2より、a2a2 x + a2b1+b2なのでこれもAx+Bの形になっている。
よってモノイドであることが確認できた。あとはセグ木に乗せれば良い。

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
	using type = struct NN {
		double A, B;
		NN(double A = 1, double B = 0) :A(A), B(B) {}
	};
	static type id() { return NN(); }
	static type op(const type&l, const type&r) {
		return NN(l.A*r.A, l.B*r.A + r.B);
	}
	static type upd(const type&l, const type&r) {
		return r;
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	using tp = tuple<LL, double, double>;
	vector<tp>A(M);
	FOR(i, 0, M) {
		LL p; double a, b; cin >> p >> a >> b;
		A[i] = tp(p, a, b);
	}
	auto Acp = A;
	SORT(Acp);
	FOR(i, 0, M) {
		LL p; double a, b;
		tie(p, a, b) = A[i];
		int id = lower_bound(ALL(Acp), tp(p, -LINF, -LINF)) - Acp.begin();
		A[i] = tp(id, a, b);
	}
	SegmentTreeFastAry<Monoid>seg(M + 10);
	double Mn = 1;
	double Mx = 1;
	FOR(i, 0, M) {
		LL p; double a, b;
		tie(p, a, b) = A[i];
		seg.update(p, Monoid::NN(a, b));
		auto res = seg.query(0, M);
		double res2 = res.A + res.B;
		DD(de(res.A, res.B));
		Mn = min(Mn, res2);
		Mx = max(Mx, res2);
	}
	cout << fixed << setprecision(10);
	cout << Mn << endl;
	cout << Mx << endl;

	return 0;
}
