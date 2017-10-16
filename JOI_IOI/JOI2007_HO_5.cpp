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

/* -----  2017/10/16  Problem: nagoya_19_12 JOI2007本戦 5 / Link: http://joi2007ho.contest.atcoder.jp/tasks/joi2007ho_e  ----- */
/* ------問題------

モビールは動く芸術品として広く親しまれている．IOI 日本委員会では，JOI を
広報するためにモビールを作成することになった．JOI 広報用モビールは，棒，紐
（ひも），錘（おもり）の 3 種類の要素を用いて，次のように構成される．
• 棒の一方の端は青に，もう一方の端は赤に塗られている．
• 棒は両端以外の 1 箇所を支点として紐でつるされる．
• 支点から赤の端までの長さも支点から青の端までの長さも正整数である．
• 棒の両端には，紐で錘か他の棒をつるす．
• 錘は紐を用いてどれかの棒の一端につるされる．
• 錘には何もつるさない．
• 錘の重さは正整数である．
• 紐のうち 1 本だけは，片方の端をある棒をつるすためにその棒の支点に結ばれ，
もう一方の端は他のどの構成要素とも結ばれていない．他の紐は全て次のいず
れかを満たす．
– ある棒の端とある棒の支点を結ぶ．
– ある棒の端とある錘を結ぶ．
ただし，どの棒においても，バランスが取れている必要がある．棒と紐の重さは無
視できるほど軽いので，棒と紐の重さは全て 0 であるとみなして解答せよ．つまり，
それぞれの棒について，
　　　（その棒の赤の端より下につるされている錘の重さの総計）
   　　　×　（その棒の支点から赤の端までの長さ）
	  　＝　（その棒の青の端より下につるされている錘の重さの総計）
	   　　　× 　（その棒の支点から青の端までの長さ）
		  であるとき，その棒はバランスが取れているとせよ．

-----問題ここまで----- */
/* -----解説等-----

結局、根からDFSをしていけばいいことが分かる。
どの棒にもつながれていないものが根であるから、これをはじめに、各要素が釣り合うように計算をおこなっていけばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

VL p, q, r, b;
//計算したいモノ:両端に指定されているもの
LL calc(int id) {//startはtopから
	LL res = 0;
	LL Lw = (r[id] ? calc(r[id]) : 1);
	LL Rw = (b[id] ? calc(b[id]) : 1);
	res = lcm(p[id] * Lw, q[id] * Rw);
	return res / p[id] + res / q[id];
}
// p:q, r----b
int cnt[102];//でてきてないものは根
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	N++;
	p = VL(N, 0); q = VL(N, 0);	r = VL(N, 0); b = VL(N, 0);

	N--;

	FOR(i, 1, N + 1) {
		cin >> p[i] >> q[i] >> r[i] >> b[i];
		cnt[r[i]]++;
		cnt[b[i]]++;
	}

	FOR(i, 1, N+1) {
		if (cnt[i] == 0)ans = calc(i);
	}



	cout << ans << "\n";

	return 0;
}