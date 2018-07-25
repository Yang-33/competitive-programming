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

/* -----  2018/07/26  Problem: AOJ 0260 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0260  ----- */
/* ------問題------

ぼくはパイプつなぎ職人です。パイプをつなぐジョイントとパイプさえもらえれば、どんなパイプだってつないでみせます。ぼくは毎日、親方からパイプとジョイントを渡されて、それをつないで親方に渡します。でも、パイプの数が多すぎるときは、１日でそれを全部つなげることはできません。そんなときでも親方はにっこり笑って、ぼくに給料を渡してくれます。
ところで、あるとき変なことに気がつきました。全部のパイプをつなげられたときより、つなげられなかったときの方が給料が多いことがしょっちゅうあるんです。あんまり変なので、ある日、親方が来たときに、給料の計算方法が書いてあるメモをこっそり見ちゃいました。そしたら、なんと
"給料は「パイプの本数×パイプの長さの総和」で支払う。ただし、ジョイントでつなげて、ひとつながりになったものは、それを１本のパイプとみなす。"
って書いてありました。これで全部つなげた方が給料が安くなることがある理由がわかりました。たとえば下図のように、長さ 1 のパイプ 3 本と長さ 2 のジョイント 2 本を全部つなげると長さ 1+2+1+2+1 = 7 のパイプが 1 本できるので、1 × (7) = 7 です。でも、ジョイントを一つだけ使って長さ 1+2+1 = 4のパイプと長さ 1 のパイプの 2 本にすると2 × (4+1) = 10なので、全部つなげるよりいっぱい給料がもらえます。

親方がなんでこんな方法で給料を決めてるかわからないけど、これでぼくもどうすればもらえる給料を多くできるかわかりました！
それでは、パイプの本数が与えられたとき、もらえる給料の最大の金額を計算するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

一つジョイントをつなげるとして、一番大きいものを選べば長さはより長くして個数は1減るに留めることができる。
そうでないものが最適であるならば反例が出せるのでこれは正しい。

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;

// 変数jを今すぐやめろ
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		V<int>p(N), j(N);
		FOR(i, 0, N) {
			cin >> p[i];
		}

		FOR(i, 0, N - 1) {
			cin >> j[i];
		}
		sort(j.rbegin(), j.rend());
		LL sum = accumulate(ALL(p), 0LL);
		LL ans = sum*N;
		LL C = N;
		FOR(i, 0, N - 1) {
			sum += j[i];
			C--;
			ans = max(ans, (C)*sum);
		}

		cout << ans << endl;

	}
}