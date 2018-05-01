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

/* -----  2018/05/01  Problem: yukicoder 125  / Link: http://yukicoder.me/problems/no/125  ----- */
/* ------問題------

綺麗で大きい花を人工的に作るために花びらを作りました．
それぞれの花びらは形は同じですが，色が違います．
色は 1 から K までの K 色あり，色 i の花びらは Ci 枚あります．
この花びら全部を円形に並べて花を作ります．
作れる花として何通り存在するかを求めるプログラムを書いて下さい．
ただし，回転することで一致するものは同じ花とみなします．
上下をひっくり返して一致する場合でも，回転で一致しないのであれば，違う花とみなします．
答えは大きくなるので，109+7 で割った余りを出力して下さい．

-----問題ここまで----- */
/* -----解説等-----

蟻本読んでた
solve1: p271の２つ目の式っぽくやるm^d ->同じやつを並べる数え上げ
solve2: ポリアの定理をやる。グループの考えが一般的？ではないことに注意
solve3: 普通に数え上げる(moebius関数がないだけで包除をがんばる)

あるグループにおけるちょうどdな並べ方が分かって、小さい計算量の方を見つけられれば勝ちっぽい。
今回は
solve1: O( d(n)^2 + N )
solve2: O( d(n)*K + N )
何故かsolve2のほうがはやい。

----解説ここまで---- */

/////////////////// solve 2
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % MOD, b / 2) * (b & 1 ? a : 1) % MOD;
}

long long modinv(long long a) {
	return modpow(a, MOD - 2);
}

vector<long long> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;
	}
}
int Euler_Phi(int n) {
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1); // n (1 - 1/pk) = n - n/pk
			while (n /= i, n % i == 0); //n を素因数分解
		}
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}

VI getdivisor(int n) {
	VI res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	SORT(res);
	return res;
}
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K; cin >> K;
	VI c(K);
	int GCD = 0;
	FOR(i, 0, K) {
		cin >> c[i];
		GCD = gcd(GCD, c[i]);
	}

	N = accumulate(ALL(c), 0);
	init_fact(N + 1);
	VI divd = getdivisor(GCD);
	for (int div : divd) {
		// div*d = N枚
		// f(div)*φ(N/div)
		LL ret = fact[N/div];
		FOR(i, 0, K) {
			ret *= inv_fact[c[i]/div];//同じものを含む数え上げ
			ret %= MOD;
		}
		ret *= Euler_Phi(div);
		ret %= MOD;
		ans += ret;
		ans %= MOD;
	}

	ans *= modinv(N);
	ans %= MOD;
	cout << ans << "\n";

	return 0;
}


//////////////////// solve 1
map<int, int>MapMoebius(int n) {
	map<int, int>res;
	vector<int>primes;

	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			primes.push_back(i);
			while (n%i == 0)n /= i;
		}
	}
	if (n != 1)primes.push_back(n);

	int m = (int)primes.size();
	for (int i = 0; i < (1 << m); i++) {//logn個も無いので余裕?
		int mu = 1, d = 1;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				mu *= -1;
				d *= primes[j];
			}
		}
		res[d] = mu;
	}
	return res;
}


long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % MOD, b / 2) * (b & 1 ? a : 1) % MOD;
}

long long modinv(long long a) {
	return modpow(a, MOD - 2);
}

vector<long long> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;
	}
}
VI getdivisor(int n) {
	VI res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	SORT(res);
	return res;
}
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K; cin >> K;
	VI c(K);
	FOR(i, 0, K) {
		cin >> c[i];
	}
	N = accumulate(ALL(c), 0);
	map<int, int>moebious = MapMoebius(N);
	init_fact(N + 1);
	VL unit_c(N + 1, 0);
	VI divN = getdivisor(N);
	for (int i : divN) {
		int ok = 1;
		int d = N / i;//groupのサイズi,グループの個数d
		FOR(j, 0, K) {
			if (c[j] % d)ok = 0;
		}
		if (!ok)continue;
		LL comb = fact[i];
		FOR(j, 0, K) {
			comb *= inv_fact[c[j] / d];
			comb %= MOD;
		}
		unit_c[i] = comb;// 1unit i個で環が作れるときの組み合わせ数
	}

	for (int i : divN) {
		int ok = 1;
		int d = N / i;//groupのサイズi,グループの個数d
		FOR(j, 0, K) {
			if (c[j] % d)ok = 0;
		}
		if (!ok)continue;
		VI divs = getdivisor(i);
		LL ret = 0;
		for (int div : divs) { // arihon p271 2個目の式
			ret += (unit_c[div] * moebious[i / div]) % MOD;
			(ret += MOD) %= MOD;
		}
		ans += ret*(d);
		ans %= MOD;
	}
	ans *= modinv(N); // ans/=N
	ans %= MOD;
	cout << ans << "\n";

	return 0;
}
