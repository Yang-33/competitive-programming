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

/* -----  2017/09/16  Problem: 038_arc_c  / Link:   ----- */
/* ------問題------

N 個の大きな茶碗が横 1 列に並んでいます。左から i(0≦i≦N−1) 番目の茶碗を茶碗 i と呼ぶことにします。茶碗 i(1≦i≦N−1) には整数 Ci が書かれており、中には Ai 個の豆が入っています。茶碗 0 には整数は書かれておらず、豆も入っていません。ゲーム好きな兄妹がこれらの茶碗と豆を使って以下のようなゲームをしようとしています。
プレイヤーは自分のターンに、茶碗 0 以外の茶碗に入っている豆 1 つ選んで取り出す。
茶碗 i から豆を取り出したときは、茶碗 i−Ci, 茶碗 i−Ci+1, ..., 茶碗 i−1 のいずれかの茶碗に豆を入れなければならない。
交互にターンを繰り返し、自分のターンに選べる豆がなくなったプレイヤーの負けとなる（もう一方のプレイヤーが勝ちとなる）。
2 人ともが勝ちを目指して最適な戦略をとったとき、先手と後手のどちらが勝つでしょうか？

-----問題ここまで----- */
/* -----解説等-----

100点開放は愚直にgrundy数を計算するだけ。
しかしN^2かかってしまうため、これではTLEしてしまう。
104点取るためにはgrundy数をsetに突っ込む時間を速くすればよい。(ここがボトルネックなので)
ある区間の未登場な最小非負整数がこの局面のgrundy数であるから、これを速く見つけたい。
ここで、grundy数がgであるような最大のindexを持っておけばあるpositionのgrundy数がGであるとは、
index[0]からindex[G-1]がpos-1からpos-C[pos]にあることになる。
これはつまりindex[0]~index[G-1]の最小値がpos-C[pos]以上であるということになる。
あとはこれを二分探索すればよい。

むずかしいね

----解説ここまで---- */


struct SegTree {
	using type = int; 	type INIT_VAL = INT_MAX; type merge(type a, type b) { return min(a, b); } int N; vector<type> dat;
	SegTree(int _N) { N = 1;	while (N < _N)N *= 2; dat = vector<type>(N * 2 - 1, INIT_VAL); }
	void update(int k, type val) { k += N - 1; dat[k] = val;	while (k) { k = (k - 1) / 2; dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); } }
	type query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INIT_VAL; if (a <= l&&b >= r)return dat[k];
		type v1 = query(a, b, k * 2 + 1, l, (l + r) / 2); type v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);	return merge(v1, v2);
	}
	inline type query(int a, int b) { return query(a, b, 0, 0, N); }
};


LL N;
int a[100005];
int c[100005];
LL ans = 0LL;
int grundy[100005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 1, N) {
		cin >> c[i] >> a[i];
	}
	SegTree seg(N);

	FOR(i, 0, N) {
		seg.update(i, -1);
	}
	seg.update(0, 0);

	int g = 0;
	FOR(i, 1, N) {
		int k = i - c[i];

		int y = 0;
		FORR(j, 20, -1) {
			if (seg.query(0, y + (1 << j)) >= k) {
				y += 1 << j;
			}
		}
		grundy[i] = y;
		seg.update(y, i);

		if (a[i] % 2 == 1) {
			g ^= grundy[i];
		}
	}

	cout << ((g != 0) ? "First" : "Second") << "\n";

	return 0;
}