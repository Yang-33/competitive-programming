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

/* -----  2018/09/30  Problem: yukicoder 308  / Link: http://yukicoder.me/problems/no/308  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

小さいときはwの昇順にシュミレーションをすればよい。
大きい時を考える。

w=3以上の絵を書きまくる。具体的には14ぐらいまで。すると、8と14は結構強いが、それ以外は塞がれていることがわかる。
さらに8,14について考えると、左端の一点がゴールのときだけは、ゴールできない場合があることが分かり、それは自分の上が素数のときとなっていることがわかる。
8,14で共通する場合が存在するかを考えると、N=56k+1を考えることになるが、
N-8 = 56k-7 = 7(8k-1)より、素数ではない。
したがって、n%8==1∧prime?(n-8)のとき、14,そうでないときは8となる。

素数判定はミラーラビンをやればよいが、int128で2乗すると入らないぐらいの値なのでオーバーフローしないような実装をする。
僕は無理だったので拝借した。
オーバーフローなあ…

----解説ここまで---- */

using LLL = __int128;
__int128 parse(string &s) {
	__int128 ret = 0;
	for (int i = 0; i < (int)s.length(); i++)
		if (isdigit(s[i]))
			ret = 10 * ret + s[i] - '0';
	if (s[0] == '-')ret = -ret;
	return ret;
}
std::istream &operator>>(std::istream &is, __int128 &value) {
	string s; cin >> s;
	value = parse(s);
	return is;
}

vector<int> make_prime(LL N) {
	vector<int> prime(N + 1, 1);
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= N; j += i)
				prime[j] = 0;
		}
	}
	return prime;
}
LLL mul(const LLL a, const LLL b, const LLL mod) {
	if (b == 0) { return 0; }
	if (b % 2 == 1) {
		return (mul(a, b - 1, mod) + a) % mod;
	}
	else {
		const LLL pp = mul(a, b / 2, mod);
		return (pp + pp) % mod;
	}
}
LLL power(const LLL a, const LLL n, const LLL mod) {
	if (n == 0) { return 1; }
	if (n % 2 == 1) {
		return mul(power(a, n - 1, mod), a, mod);
	}
	else {
		const LLL aa = power(a, n / 2, mod);
		return mul(aa, aa, mod);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LLL N;
	cin >> N;
	int ans = 0;
	if (N <= 1000) {
		VI is_prime = make_prime(N + 1);
		for (int w = 3; ; w++) {
			VI masu(N + 1, 0);
			masu[1] = 1;
			queue<int>q;
			q.push(1);
#define IN(a,b,c) (a<=b&&b<c)
			vector<int> ds({ -w,w,-1,1 });
			while (!q.empty()) {
				int pos = q.front(); q.pop();
				FOR(k, 0, 4) {
					if (k == 3 && pos%w == 0)continue;
					if (k == 2 && pos%w == 1)continue;
					int nx = pos + ds[k];
					if (IN(1, nx, N + 1) && !masu[nx] && !is_prime[nx]) {
						masu[nx] = 1;
						q.push(nx);
					}
				}
			}
			if (masu[N]) { ans = w; break; }
		}
	}
	else {
		auto f = [](LLL n) {
			if (n == 1) { return 0; }
			LLL s = 0, d = n - 1;
			while (!(d & 1))s++, d >>= 1;

			mt19937_64 rand_src(random_device{}());
			FOR(i, 0, 100) {
				const LLL a = (rand_src() % (n - 2)) + 1;
				if (power(a, n - 1, n) != 1) { return 0; }

				LLL num = power(a, d, n);
				if (num != 1) {
					bool comp = true;
					FOR(_, 0, s) {
						if (num == n - 1) {
							comp = 0;
							break;
						}
						num = mul(num, num, n);
					}
					if (comp) return 0;
				}
			}
			return 1;
		};
		if (N % 8 == 1) {
			// if N-8 prime : ans = 14 
			if (f(N - 8))ans = 14;
			else ans = 8;
		}
		else {
			ans = 8;
		}
	}



	cout << ans << "\n";

	return 0;
}
