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

/* -----  2018/11/07  Problem: ARC 027 D / Link: http://arc027.contest.atcoder.jp/tasks/arc027_d  ----- */
/* ------問題------

跡鼓駄 (あとこだ) 町には ARC 珈琲店があり、競技プログラミング喫茶店として知られている。
高橋君は ARC 珈琲店でアルバイトをしている。
高橋君は ARC 珈琲店に行く際にいつも精進通りという道を通る。精進通りは、高橋君の家と ARC 珈琲店とを結んでいる。
精進通りは N 個の石で構成されている石畳の道である。石には、高橋君の家がある側から順に 1 から N まで番号がつけられている。
高橋君は足腰を鍛えるため、D 日間精進通りでトレーニングをすることにした。

i 日目のトレーニングは、以下の要領で行われる。
トレーニング中、石 x にいる場合、石 x からは石 x+1, x+2, … , x+hx に跳んで移動することができる。hx はトレーニングの日によらず一定である。
トレーニング開始時点では石 si にいる。
トレーニングでは、石 si からジャンプを繰り返して石 ti に移動する。途中で石 ti より大きな番号の石に跳べたとしても、ti より大きな番号の石に移動してはならない。
トレーニングは石 ti に到達した時点で終了する。
高橋君は、石 si から石 ti までジャンプで移動する組み合わせが全部で何通りあるのかが気になった。ジャンプで移動する組み合わせというのは、ジャンプで移動する際に使用する石の組み合わせの総数である。高橋君はすべての組み合わせについて自力で跳んで確かめるつもりである。

同僚の青木君は、高橋君を止めるために、石 si から石 ti までジャンプで移動する方法が全部で何通りあるのかを前もって調べ、結果を高橋君に伝えることにした。
それぞれの日について、石 si から石 ti までジャンプで移動する方法が全部で何通りあるのかを求めるプログラムを作成せよ。　なお、 2 つの移動方法が異なるとは、途中で通った石の組み合わせが異なることである。

-----問題ここまで----- */
/* -----解説等-----

基本的には遷移行列をセグメント木でまとめれば良い。
ただしメモリが激烈に厳しいので、VVI を使わず、arrayやLL->intにして頑張る。arrayが初期化なしなので少し困った。
また、遷移行列は周りのhから影響されるので注意して書く。
行列のクエリは、s->tとした時行列をt=>sの向きに掛ける必要があるので、merge関数で反転させる必要がある。
えーこれ通るの結構厳しいなあ

[解法を見た]
O(N^2)の平方分割。
あっ…これは解けないとダメですね…

----解説ここまで---- */

//const int sz = 1005;
const int sz = 600005;
template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	int ARY_SIZE;
	vector<nd>node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n) { node.resize(2*ARY_SIZE, Monoid::id()); }
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = Monoid::upd(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	void build() { ARY_SIZE--; for (int i = ARY_SIZE - 1; i >= 0; i--) node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	inline nd query(int l, int r) {
		if (l >= r) return Monoid::id(); nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	void set(int i, const nd val) { i += ARY_SIZE; node[i] = Monoid::upd(node[i], val); }
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i] << " "; cerr << "\n"; }
};
using mint = int;// modint<MOD>;
using Mat = array<array<mint, 10>, 10>;
Mat INI;
Mat mul(const Mat &A, const Mat &B) {
	Mat C = INI;
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (1LL*A[i][k]) * (B[k][j])%MOD)%MOD;
				}
			}
		}
	}
	return C;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI h(N); FOR(i, 0, N)cin >> h[i];
	Mat ee;
	FOR(i, 0, 10) {
		FOR(j, 0, 10)ee[i][j] = 0;
	}
	INI = ee;
	FOR(i, 0, 10)ee[i][i] = 1;
	static const Mat E = ee; 
	struct Monoid {
		using type = Mat;
		static type id() { return E; }
		static type op(const type&l, const type&r) {
			return mul(r, l); // !
		}
		static type upd(const type&l, const type&r) {
			return r;
		}
	};
	SegmentTreeFastAry<Monoid> seg(N);
	Mat notH;
	FOR(i, 0, 10)FOR(j, 0, 10)notH[i][j] = 0;
	FOR(i, 1, 10) {
		notH[i][i - 1] = 1;
	}
	FOR(i, 0, N - 1) {
		Mat x = notH;
		FOR(j, 1, 11) {// pre hから、i+1へ移動可能か
			if (i + 1 - j >= 0 && j <= h[i + 1 - j]) {
				x[0][j - 1] = 1;
			}
		}
		seg.set(i, x);
	}

	seg.build();
	int Q; cin >> Q;

	FOR(i, 0, Q) {
		int s, t; cin >> s >> t;
		cout << seg.query(s, t)[0][0] << endl;;
	}

	return 0;
}