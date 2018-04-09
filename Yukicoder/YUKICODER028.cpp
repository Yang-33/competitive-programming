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

/* -----  2018/04/09  Problem: yukicoder 028  / Link: http://yukicoder.me/problems/no/028  ----- */
/* ------問題------

X0=seed
Xn=1+(X2n−1+Xn−1×12345) % 100000009    (1≤n≤N)
ただし % は剰余演算とする

上の定義から作られる N+1 個の要素を持つ数列 X の中から K 個数字を選びそれらを掛け合わせ T とおく。
T を B 進数に変換した時末尾の0の数が最小となる T では末尾の0の数はいくつになるか答えよ。

例えば
B=18、T が10進数で「612」なら T は18進数で「1g0」なので末尾の0の数は1個
B=3、T が10進数で「36」なら T は3進数で「1100」なので末尾の0の数は2個

-----問題ここまで----- */
/* -----解説等-----

最終的に選択した積の要素にBの個数が最小になるようになっていればよい。
したがってB = 2^b[2] * 3^b[3] *5^b[5] * ...のうち、Tを作成した際にできるTb[i]
を比較して、すべての素因数からmin(Tb[i]/b[i]) となるようにすればよい。
これがよいことの証明を背理法っぽく示す
ある素因数を一つ決めてこれを最小にしようとする。
そうでないものが最適であったとする。
このとき、どれかの素因数が最小となっているため、これは反していて全部の素因数について探索すればよいことになる。

非自明っぽいけど、たまに見かける系のやつだった。

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q;  cin >> Q;
	const LL mod = 100000009;
	FOR(q, 0, Q) {

		LL seed, N, K, B;
		cin >> seed >> N >> K >> B;
		LL BB = B;
		VI b(B + 1, 0);
		for (int i = 2; i*i <= BB; i++) {
			while (B%i == 0) {
				b[i]++;
				B /= i;
			}
		}
		if (B != 1) {
			b[B]++;
		}
		VL x(N + 1);
		x[0] = seed;
		FOR(i, 1, N + 1) {
			x[i] = 1 + (x[i - 1] * x[i - 1] + x[i - 1] * 12345) % mod;
		}

		B = BB;
		VVI bx(B + 1, VI(N + 1, 0));
		//VVI xb(N + 1, VI(B + 1, 0));
		FOR(i, 0, N + 1) {
			for (int j = 2; j <= B; j++) {
				if (b[j])while (x[i] % j == 0) {
					bx[j][i]++;
					x[i] /= j;
				}
			}
		}

		int ans = INF;
		FOR(i, 2, B + 1) {
			if (b[i]) {
				int Base = b[i];
				sort(bx[i].begin(), bx[i].end());
				int ret = 0;
				FOR(k, 0, K) {
					ret += bx[i][k];
				}
				ans = min(ans, ret / Base);
			}
		}

		cout << ans << "\n";

	}

	return 0;
}
