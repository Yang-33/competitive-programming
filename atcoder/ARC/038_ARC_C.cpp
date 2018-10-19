#include <bits/stdc++.h>
using namespace std;


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
#define DEBUG(x) 
#endif
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/19  Problem: ARC 038 C / Link: http://arc038.contest.atcoder.jp/tasks/arc038_c  ----- */
/* ------問題------

N 個の大きな茶碗が横 1 列に並んでいます。左から i(0≦i≦N−1) 番目の茶碗を茶碗 i と呼ぶことにします。茶碗 i(1≦i≦N−1) には整数 Ci が書かれており、中には Ai 個の豆が入っています。茶碗 0 には整数は書かれておらず、豆も入っていません。ゲーム好きな兄妹がこれらの茶碗と豆を使って以下のようなゲームをしようとしています。

プレイヤーは自分のターンに、茶碗 0 以外の茶碗に入っている豆 1 つ選んで取り出す。
茶碗 i から豆を取り出したときは、茶碗 i−Ci, 茶碗 i−Ci+1, ..., 茶碗 i−1 のいずれかの茶碗に豆を入れなければならない。
交互にターンを繰り返し、自分のターンに選べる豆がなくなったプレイヤーの負けとなる（もう一方のプレイヤーが勝ちとなる）。
2 人ともが勝ちを目指して最適な戦略をとったとき、先手と後手のどちらが勝つでしょうか？

-----問題ここまで----- */
/* -----解説等-----

100点解法は愚直にgrundy数を計算するだけで得点を得ることができる。
しかしO(N^2)かかってしまうため、これではTLEしてしまう。
104点取るためにはgrundy数をsetに突っ込む時間を速くする必要がある。
ある区間の未登場な最小非負整数がこの局面のgrundy数であるから、これを速く見つけたい。
ここで、grundy数がgであるような最大のindexを持っておけば、
あるpositionのgrundy数がGであるとは、index[0]からindex[G-1]がpos-1からpos-C[pos]にあることになる。
これはつまりindex[0]~index[G-1]の最小値がpos-C[pos]以上であるということになる。
あとはこれを二分探索すればよい。

セグ木の二分探索をしていきたい。minなので下っていくだけでできる。

最速をとった。

----解説ここまで---- */

template <size_t E, bool T = 1>
class FastScanner {
	char e[E | 1], *t, *a;
	const double A = strtod("NaN", nullptr);
	FILE*o;
	bool i() { size_t n = fread(e, 1, E, o); e[n] = 0; a = e + n; t = e; return n; }
	bool i(ptrdiff_t n) { size_t s = fread(e, 1, E, o); e[n += s] = 0; a = e + n; t = e; return s; }
public:
	FastScanner(FILE*o = stdin) :e{}, t(e), a(e + E), o(o)
	{i(); }
	bool scan(double&n) { if (!*t && !i()) { n = A; return 0; }char*s; n = strtod(t, &s); while (s == t)if (!i()) { n = A; return 0; }if (s >= a) { ptrdiff_t h = a - t; memcpy(e, t, h); if (i(h))n = strtod(e, &t); }return 1; }
	bool scan(char&n) { n = *t++; if (n)return 1; if (!i())return 0; n = *t++; return 1; }
	bool scan(char*n) { char*s = nullptr; for (;; ++t) { char h = *t; if (!h) { if (s) { ptrdiff_t r = t - s; memcpy(n, s, r); n += r; }if (!i()) { *n = 0; return s; }h = *e; if (s)s = e; }if (!isspace(h)) { if (!s) { s = t; } } else if (s) { ptrdiff_t r = t - s; memcpy(n, s, r); n[r] = 0; ++t; return 1; } } }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<I>::type*_2 = 0) { bool s = 0, h = 0; n = 0; for (;; ++t) { char r = *t; if (!r) { if (!i())return s; r = *t; }if (isdigit(r)) { s = 1; n = n * 10 + r - '0'; } else if (s) { ++t; break; } else if (r == '-') { h = 1; } }if (h)n = -n; return 1; }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<!I>::type*_2 = 0) { bool s = 0, h = 0; n = 0; for (;; ++t) { char r = *t; if (!r) { if (!i())return s; r = *t; }if (isdigit(r)) { s = 1; n = n * 10 + r - '0'; } else if (s) { break; } else if (r == '-') { h = 1; } }if (h)n = -n; return 1; }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<!std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<I>::type*_2 = 0) { bool s = 0; n = 0; for (;; ++t) { char h = *t; if (!h) { if (!i())return s; h = *t; }if (isdigit(h)) { s = 1; n = n * 10 + h - '0'; } else if (s) { ++t; return 1; } } }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<!std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<!I>::type*_2 = 0) { bool s = 0; n = 0; for (;; ++t) { char h = *t; if (!h) { if (!i())return s; h = *t; }if (isdigit(h)) { s = 1; n = n * 10 + h - '0'; } else if (s) { return 1; } } }
	template<class O, class...I>
	bool scan(O&&n, I&&...s) { return scan(n) && scan(s...); }
	bool scanln(char*n) { char*s = t, *h = n; for (;; ++t) { char r = *t; if (!r) { ptrdiff_t d = t - s; memcpy(h, s, d); h += d; if (!i()) { *h = 0; return h - n; }s = e; r = *e; }if (r == '\n') { ++t; ptrdiff_t d = t - s; memcpy(h, s, d); h[d] = 0; return 1; } } }
	template<class O, class...I>
	bool scanln(O&&n, I&&...s) { return scanln(n) && scanln(s...); }
	char peek() { if (!*t)i(); return*t; }
	bool ignore(char n) { for (;; ++t) { if (!*t && !i())return 0; if (*t - n)return 1; } }
	bool ignore() { for (;; ++t) { if (!*t && !i())return 0; if (!isspace(*t))return 1; } }
	bool advance() { if (!*t && !i())return 0; return*++t; }
	bool advance(ptrdiff_t n) { if (!*t && !i())return 0; for (ptrdiff_t s = a - t; s <= n;) { n -= s; if (!i())return 0; s = a - t; }t += n; return  *t; }
	template<class O>
	O next() { O n; scan(n); return n; }
	template<class O>
	FastScanner&operator>>(O&n) { scan(n); return*this; }
};
constexpr size_t BUF_SIZE = (1 << 17);
FastScanner<BUF_SIZE> CIN(stdin);
struct SegTreeG {
	int N;	int dat[1 << 18];
	SegTreeG(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		fill(dat, dat + 2*N-1, -1);
	}
	void update(int k, const int val) {
		k += N - 1;
		dat[k] = val;
		while (k) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	const int find(int k, int l, int r, const int X) {
		while (1) {
			if (l + 1 == r)return k - N + 1;
			if (dat[2 * k + 1] < X) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
	}

	const int find(const int X) {
		return find(0, 0, N, X);
	}


};
signed main() {

	int N;CIN.scan(N);
	SegTreeG seg(N + 10);
	seg.update(0, 0);
	// O(Nlog^2N)->O(NlogN)
	int ans = 0;
	int c, a;
	FOR(i, 1, N) {
		CIN.scan(c, a);
		int L = seg.find(i - c);
		int G = L;
		if (a& 1)ans ^= G;// add
		DEBUG(debug(L,ans));
		seg.update(G, i);
	}

	puts(ans ? "First" : "Second");

	return 0;
}