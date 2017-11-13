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

/* -----  2017/11/14  Problem: AOJ 2431 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2431  ----- */
/* ------問題------

太郎君は引っ越しをすることになりました。
太郎君はたくさんの荷物を持っているので、荷物の運搬を引っ越し業者に頼むことにしました。
荷物はいろいろな重さの物があるので、わかりやすいように軽い方から順番に並べて置いてもらうように頼みましたが、引っ越し業者の人はばらばらの順番で荷物を置いていってしまいました。
そこで太郎君は荷物を並べ替えようとしましたが、荷物は重いので運ぶのには体力が必要です。
それぞれの荷物は今ある場所から他の荷物の間や荷物の端など好きな場所に運ぶことができますが、ある荷物を運ぶにはその荷物の重さと同じだけ体力を使います。
太郎君はあまり体力がないので、できるだけ体力を使わずに荷物を軽い方から順番に並べる方法を考えることにしました。

-----問題ここまで----- */
/* -----解説等-----

最も長く増加していてかつその値が大きい列は動かさない方がよいことが分かる。
これをDPしたい気持ちになる。
これは置いた値の選択がその時々によって変わるため最後まで分からないが最後には決定できることからわかる。
dp[i]:= 値iについてこれまでの最長増加部分列
としてDPをする。これはiまでの全ての区間からのmaxがほしいのでsegtreeなどで高速化できる。

最初は10^5なのでできるとおもったが、これは先読みで座標圧縮できるのでどうでもよい。

----解説ここまで---- */


template<typename type>
struct SegTree {
	type INIT_VAL = 0; // 影響のない値
	inline type merge(type a, type b) { //台数構造
		return max(a, b); //merge部分
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
		dat[k] = merge(dat[k],val);
		while (k) {
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	// 区間[a,b)の評価
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



LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	SegTree<LL> seg(100005);
	FOR(i, 0, N) {
		cin >> a[i];
		seg.update(a[i], seg.query(0, a[i]) + a[i]);
		
	}
	ans = N*(N + 1) / 2LL - seg.query(0, 100005);

	cout << ans << "\n";

	return 0;
}
