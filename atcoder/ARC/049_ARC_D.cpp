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

/* -----  2018/11/12  Problem: ARC 049 D / Link: http://arc049.contest.atcoder.jp/tasks/arc049_d  ----- */
/* ------問題------

高橋君は旅行先で、「すわっぷしまーす」という不思議な完全二分木を観光しました。
「すわっぷしまーす」は、高さが N+1 で葉の個数が 2N の完全二分木です。そして、葉には左から順に 1,2,3,…,2N と数が書かれています。
また、葉以外の頂点について、上から i 段目 (1≦i≦N)、左から j 番目 (1≦j≦2i−1) ならば位置 2i−1+(j−1) となるように位置というものを定義します。
さらに、swap(x) というものを定義します。これは、位置 x となる頂点を求め、左右の部分木を入れ替えるという動作です。
「すわっぷしまーす」は、以下の 2 種類のクエリを処理できます。
タイプ1: k(1≦k≦2N) が与えられるので、左から k 番目の葉に書かれた数を求める。
タイプ2: a,b(1≦a≦b≦2N−1) が与えられるので、swap(a),swap(a+1),swap(a+2),…,swap(b) と、この順番で実行する。
高橋君は、旅行から帰った後、自分でも「すわっぷしまーす」を作りたくなりました。しかしなかなか難しいので、あなたが代わりに作ることになりました。
具体的には、N と、Q 個のクエリが与えられるので、それを処理できるような「すわっぷしまーす」を作ってください。

-----問題ここまで----- */
/* -----解説等-----

遅延セグ木を深さごとにいい感じにswapするようにする
そのために、深さkをswapするような命令をlogN=高さ回に分割する。
ちょうど受け止めてもらえるようにするために、頂点を2^{N-i}倍長くしてクエリ長を調節すると嬉しい感じになる。
結構ゴニョったけどちゃんと式を書くと良さそう。

----解説ここまで---- */

typedef long long ll;
struct LazySegTree {

	int N;
	vector<int> dat;
	vector<int> lazy;
	vector<int> L;
	vector<int> R;
	const int NIL = 0;
	inline int merge(int a, int b) { return min(a, b); }
	const int INIT_VAL = INT_MAX;
	//--------------setting--------------//

	LazySegTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<int>(N * 2 - 1, INIT_VAL);
		lazy = vector<int>(N * 2 - 1, NIL);
		L = vector<int>(N * 2 - 1);
		R = vector<int>(N * 2 - 1);
		FOR(i, 0, 2 * N - 1) {
			L[i] = 2 * i + 1;
			R[i] = 2 * i + 2;
		}
		FOR(i, 0, N) {
			dat[i + N - 1] = i;
		}
		DD(de(N));
	}

	void lazy_push(ll k, ll queryL, ll queryR, int dep) {
		if (lazy[k] == NIL)return;
		if (lazy[k] & 1 << dep) {
			lazy[k] ^= 1 << dep;
			swap(L[k], R[k]);
		}
		if (k < N - 1) {
			lazy[L[k]] ^= lazy[k];
			lazy[R[k]] ^= lazy[k];
		}
		lazy[k] = NIL;
	}

	inline void lazy_update(ll queryL, ll queryR, ll val, ll k, ll nodeL, ll nodeR, int dep) {
		lazy_push(k, nodeL, nodeR, dep);
		if (nodeR <= queryL || queryR <= nodeL) { return; }
		if (queryL <= nodeL && nodeR <= queryR) {
			DD(de(val, dep, queryL, queryR));
			lazy[k] ^= 1 << val;
			lazy_push(k, nodeL, nodeR, dep);
			return;
		}
		ll nodeM = (nodeL + nodeR) / 2;
		lazy_update(queryL, queryR, val, L[k], nodeL, nodeM, dep + 1);
		lazy_update(queryL, queryR, val, R[k], nodeM, nodeR, dep + 1);
	}
	inline void lazy_update(int a, int b, int val, int dep) {
		lazy_update(a, b, val, 0, 0, N, dep);
	}
	inline ll query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR, int dep) {
		if (nodeR <= queryL || queryR <= nodeL) { return INT_MAX; }
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; }
		lazy_push(k, nodeL, nodeR, dep);
		ll nodeM = (nodeL + nodeR) / 2;
		ll vl = query(queryL, queryR, L[k], nodeL, nodeM, dep + 1);
		ll vr = query(queryL, queryR, R[k], nodeM, nodeR, dep + 1);
		return merge(vr, vl);
	}
	inline int query(int a, int b) {
		return query(a, b, 0, 0, N, 0);
	}
};

int main() {
#define int long long 
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;
	LazySegTree seg(1 << N);
	FOR(_, 0, Q) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			a--;
			cout << seg.query(a, a + 1) + 1 << endl;
		}
		else {
			a--; // 0-index [a,b)をswap
			FOR(i, 0, N) {
				int ithL = 1 << i;
				int ithR = ithL * 2;
				ithL--; ithR--;
				DD(de(ithL,ithR));
				ithL = max(ithL, a);
				ithR = min(ithR, b);
				DD(de(ithL, ithR));
				ithL -= 1 << i; ithL++;
				ithR -= 1 << i; ithR++;
				DD(de(ithL, ithR));
				ithL *= 1 << (N - i);
				ithR *= 1 << (N - i);
				DD(de(i, ithL, ithR,a,b));
				if (ithL < ithR) {
					seg.lazy_update(ithL, ithR, i, 0);
				}

			}
		}
	}

	return 0;
}
