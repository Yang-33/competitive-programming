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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/23  Problem: AOJ 0520 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0520  ----- */
/* ------問題------

モビールは動く芸術品として広く親しまれている.IOI 日本委員会では,JOI を広報するためにモビールを作成することになった.JOI 広報用モビールは,棒,紐(ひも),錘(おもり)の 3 種類の要素を用いて,次のように構成される.
棒の一方の端は青に,もう一方の端は赤に塗られている.
棒は両端以外の 1 箇所を支点として紐でつるされる.
支点から赤の端までの長さも支点から青の端までの長さも正整数である.
棒の両端には,紐で錘か他の棒をつるす.
錘は紐を用いてどれかの棒の一端につるされる.
錘には何もつるさない.
錘の重さは正整数である.
紐のうち 1 本だけは,片方の端をある棒をつるすためにその棒の支点に結ばれ, もう一方の端は他のどの構成要素とも結ばれていない.他の紐は全て次のいず れかを満たす.
ある棒の端とある棒の支点を結ぶ.
ある棒の端とある錘を結ぶ.
ただし,どの棒においても,バランスが取れている必要がある.棒と紐の重さは無視できるほど軽いので,棒と紐の重さは全て 0 であるとみなして解答せよ.つまり,それぞれの棒について,

(その棒の赤の端より下につるされている錘の重さの総計) × (その棒の支点から赤の端までの長さ) = (その棒の青の端より下につるされている錘の重さの総計) × (その棒の支点から青の端までの長さ)

であるとき,その棒はバランスが取れているとせよ.

-----問題ここまで----- */
/* -----解説等-----

再帰的にバランスを取っていけば良い。
重さの比に対してみたす最小の重りは、下の重さが決定されていれば一意に決定できる。

----解説ここまで---- */


using LL = long long; template<class T> using V = vector<T>;

struct info {
	LL p, q, r, b;
	info(int P, int Q, int R, int B) :p(P), q(Q), r(R), b(B) {}
	info() {}
};// 構造体によって面倒になる例
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

LL f(int cent, const V<info>&infos) {// 1 index 再帰的にバランスをとるしかなさそう
	LL WLcm = 0;
	LL LM = (infos[cent].r ? f(infos[cent].r, infos) : 1);
	LL RM = (infos[cent].b ? f(infos[cent].b, infos) : 1);
	WLcm = lcm(infos[cent].p * LM, infos[cent].q* RM);
	return WLcm / infos[cent].p + WLcm / infos[cent].q;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		V<info>infos(N + 1);
		V<bool>has(N + 1);
		FOR(i, 1, N + 1) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			infos[i] = info(a, b, c, d);
			has[c] = has[d] = 1;
		}
		LL ans = 0;
		int kim = 0;
		FOR(i, 1, N + 1) {
			if (!has[i])ans = f(i, infos), kim++;
			assert(kim < 2);
		}
		cout << ans << endl;
	}

	return 0;
}
