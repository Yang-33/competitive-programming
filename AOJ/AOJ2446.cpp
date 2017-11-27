#include <bits/stdc++.h>
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

/* -----  2017/11/27  Problem: nu31_c / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446  ----- */
/* ------問題------

n個の整数a1, a2, …, anとn個の整数p1, p2, …, pn、整数mが与えられる。
k番目の整数akをpk[%]の確率で選ぶ、という操作を各k(1 ≤ k ≤ n)について行い、0個以上n個以下の整数を選び出す。
1以上m以下の整数の中で、選ばれた整数の少なくとも1つで割り切れるものの個数の期待値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

愚直な立式を行うと2^nの要素に対して包除原理で計算を行いたいため、2^nだけ計算を行う必要がある。
このときだいたいは同じ部分を使いまわしていることに気がつくと、これは実質bitDPのようになる。
集合をbitで表したときに、右側のbitについて包除原理をもちいて一つ要素の少ないものが存在すればこれを取り除く。
をしていく。
kbit目では、k-1については計算を終了しているため値をもってくるだけでよい(ここがDP要素、はい使いまわしのプロ)
これは高速メビウス変換だの高速ゼータ変換などと呼ばれているらしい。
どちらも各fを求めたい際にfの部分gについて計算可能であれば、集合の計算をn2^nで計算が可能になる。
どちらも重ね合わせを取り除いたり加える際に値を使いまわしている点では同様の計算を行っている。

----解説ここまで---- */

using int_128 = __int128;
LL N,M;

/*最大公約数を求める関数(再帰版ユーグリッドの互除法)*/
int_128 gcd(int_128 a, int_128 b) { return b ? gcd(b, a%b) : a; }

/*最小公倍数を求める関数。最小公倍数の性質( a×b÷[aとbの最大公約数] )を利用。*/
int_128 lcm(int_128 a, int_128 b) { return a / gcd(a, b) * b; }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VL a(N);
	vector<double>p(N);

	FOR(i, 0, N)
		cin >> a[i];
	FOR(i, 0, N) {
		cin >> p[i];
		p[i] /= 100.0;
	}
	vector<int_128>fm(1 << N, 0);
	FOR(i, 0, 1 << N) {
		int_128 lc = 1;
		FOR(j, 0, N) {
			if (i&(1 << j))lc = lcm(lc, a[j]);
		}
		fm[i] = (int_128)M / lc;
		//cout << (LL)fm[i] << endl;
	}


	FOR(i, 0, N)FOR(j, 0, 1 << N)if (j&(1 << i))fm[j] -= fm[j ^ (1 << i)];
	long double ans = 0.0;
	FOR(i, 0, 1 << N) {
		long double P = 1.0;
		FOR(j, 0, N) {
			if (i&(1 << j))P *= p[j];
			else P *= (1 - p[j]);
		}

		//cout << (LL)fm[i] << endl;
		ans += (M-(fm[i]>0?fm[i]:-fm[i]))*P;
	}

	cout<<fixed<<setprecision(10) << ans << "\n";

	return 0;
}
