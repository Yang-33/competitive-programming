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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/04/13  Problem: GCJ2019_R1A B / Link: __CONTEST_URL__  ----- */

// 中国剰余定理 O(Nlogval) ただしmodの積がLLを超えるときは多倍長整数が必要
inline long long addmod(long long a, long long m) {
	return (a % m + m) % m;
}

// 拡張 Euclid の互除法
long long extGCD(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGCD(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

// 答えを x ≡ r (mod. M) として、{r, M} をリターン, 存在しない場合は {0, -1} をリターン
pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
	long long r = 0, M = 1;
	for (int i = 0; i < (int)b.size(); ++i) {
		long long p, q;
		long long d = extGCD(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
		if ((b[i] - r) % d != 0) return make_pair(0, -1);
		long long tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}
	return make_pair(addmod(r, M), M);
}

vector<int> ask(const vector<int>&a) {
	int N = SZ(a);
	FOR(i, 0, N) {
		cout << a[i];
		if (i != N - 1)cout << " ";
	}cout << endl;

	vector<int>b(N);
	FOR(i, 0, N) {
		cin >> b[i];
	}
	return b;
}

bool JUDGE(int a) {
	cout << a << endl;
	int res; cin >> res;
	return res == 1;
}

void solve(int testcasenum, int _n, int M) {

	VL mods({ 8,3,5,7,11,13,17 });// 2じゃなくても2のみで構成される最大の整数が使える
	VL b(7, 0);
	int N = 18;
	FOR(i, 0, 7) {
		VI ms(N, mods[i]);
		VI res = ask(ms);
		LL sum = accumulate(ALL(res), 0LL);
		b[i] = sum;
	}
	PLL res = ChineseRem(b, mods);
	bool judgeres = JUDGE(res.first);
	// 中央を選ぶ
	DD(de(judgeres, res.first, res.second, a[sz / 2], M));
}

int main() {

	int T; cin >> T;
	int N, M; cin >> N >> M;
	FOR(i, 0, T) {
		solve(i + 1, N, M);
	}

	return 0;
}
