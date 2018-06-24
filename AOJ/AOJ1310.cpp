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

/* -----  2018/06/21  Problem: AOJ 1310 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1310  ----- */
/* ------問題------

列aの生成規則がある。これによってできた列を1つの文字列とみなす。
これの部分列をとったとき、Qの倍数であるものの個数は。
N<=10^5,Max(a)=9

-----問題ここまで----- */
/* -----解説等-----

できた列の右側から順に、R(x):右からの選択でxをえらんだとき、[x:N]までの値(mod Q)
とする。
すると問題は以下のように言い換えることができる。
L,Rを選択して、R(L)-R(R) ≡ 0(mod Q)をみたすものの個数を数えよ。
これはLRカウントの典型なのでmapとかBITを使うと簡単にできる。(以前の区間の数え上げをlogでできればよい)

サンプルが悲しくて、これを試すとサンプルは合う。しかしWAなので次を考える。
- 10^x*a[i] mod Q の値は正しいか。
えーQ=2,5でアウトであることが明らかにわかるので、これを場合分けする。(この問いに気づくのに時間がかかる)
これは前から見たときのprefixのみみればよい

----解説ここまで---- */


void solve(int N, int S, int W, int P) {

	int g = S;
	VI a(N);
	FOR(i, 0, N) {
		a[i] = (g / 7) % 10;
		if (g % 2 == 0)g = g / 2;
		else g = (g / 2) ^ W;
	}

	/*cout << "a : ";
	FOR(i, 0, N) {
	cout << a[i] << " ";
	}cout << endl;*/

	int ans = 0;
	VL cumR(N + 1);
	cumR[N] = 0;
	LL ten = 1;
	//a = VI(N, 1); 0じゃない
	FORR(i, N - 1, -1) {
		//debug(a[i]);
		cumR[i] = ((ten)*a[i] % P) % P + cumR[i + 1];
		cumR[i] %= P;
		ten *= 10;
		ten %= P;
	}
	/*cout << "cumR : ";
	FOR(i, 0, N + 1) {
	cout << cumR[i] << " ";
	}cout << endl;*/

	if (P == 2) {
		int x = 0;
		FOR(i, 0, N) {
			if (a[i] != 0)x++;
			if (a[i] % 2 == 0) {
				ans += x;
			}
			//debug(x);
		}
	}
	else if (P == 5) {
		int x = 0;
		FOR(i, 0, N) {
			if (a[i] != 0)x++;
			if (a[i] % 5 == 0) {
				ans += x;
			}
			//debug(x);
		}
	}
	else 
	{
		map<LL, LL>cnt;
		FOR(i, 0, N) {
			if (a[i] != 0) {
				cnt[cumR[i]]++;
			}
			ans += cnt[cumR[i + 1]];
		}
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, S, W, Q;
	while (cin >> N >> S >> W >> Q) {
		if (N == 0)break;
		solve(N, S, W, Q);
	}

	return 0;
}