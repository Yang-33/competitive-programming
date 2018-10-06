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

/* -----  2018/10/06  Problem: ARC 042 D / Link: http://arc042.contest.atcoder.jp/tasks/arc042_d  ----- */
/* ------問題------

4 つの整数 X,P,A,B(1≦X<P<231,0≦A≦B<231) が与えられます。ただし、P は素数です。 Xi(A≦i≦B) を P で割った余りの最小値を求めてください。

この問題の入力は得点に影響しない入力例 1 を除いて、このC++プログラムを用いて生成しました。擬似乱数生成器の初期化に用いられるプログラムの第 1 引数は 1 以上 10,000 以下の整数を用いました。このファイルの i 行目 (1≦i≦10,000) は、入力生成プログラムの第 1 引数が i であるときの出力と一致します。すなわち、与えられるテストケースは入力例 1 を除いて、このファイルのいずれかの行と一致します。

-----問題ここまで----- */
/* -----解説等-----

乱数なので解も[A,B]が広ければ広いところに分布する。
~~また、乱数なので解も局所的に集中したりしなさそう~~ これは間違っている

B-Aが小さいときは調べれば良い。
また、B-Aが大きいときは解を小さい方から探索する。
具体的には離散対数問題は素数Pに対して、X^i≡y mod PをO(sqrt(P))のiについて解けるので、
これを調べれば良い。
解法の分割の間は、sqrt(2^32)だとおもったけどlogがつくのでアレになった

----解説ここまで---- */




const LL KKK = 1 << 24;


long long  powmod(long long  x, long long  n, long long  mod) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	/*FOR(_, 0, 10000)*/ {
		LL X, P, A, B; cin >> X >> P >> A >> B;
		//if (_ % 100 == 0)cerr << _ << endl;

		if ((B - A + 1) > KKK) { // rand
			LL ret = 0;
			LL f = powmod(X, A, P);
			VL E; E.push_back(f);
			for (int i = A + 1; i <= A + KKK - 1; i++) {
				f *= X; f %= P; E.push_back(f);
			}
			SORT(E); A += KKK; ret = E[0];

			LL T = powmod(X, KKK, P);
			while (A + KKK < B) {
				for (int i = 0; i < ret; i++) {
					LL Y = (i * powmod(f, P - 2, P)) % P;
					int pos1 = lower_bound(E.begin(), E.end(), Y) - E.begin();
					if (pos1 < SZ(E) && E[pos1] == Y) {
						ret = min(ret, 1LL * i);
					}
				}
				f *= T; f %= P; A += KKK;
			}
			for (int i = A; i <= B; i++) {
				f *= X; f %= P; ret = min(ret, f);
			}
			cout << ret << endl;
		}
		else {
			LL ans = P;
			LL val = powmod(X, A, P);
			FOR(i, 0, B - A + 1) {
				ans = min(ans, val);
				if (ans == 1)break;
				val *= X;
				val %= P;
			}
			cout << ans << endl;
		}
	}


	return 0;
}
