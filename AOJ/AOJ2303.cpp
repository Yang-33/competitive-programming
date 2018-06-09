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

/* -----  2018/06/10  Problem: AOJ 2303 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2303  ----- */
/* ------問題------

N人いる。M個の休憩所がある。それぞれの人はP[i]の確率で各休憩所で休憩をする。休憩の際は、T[i]秒だけ休む。
v[i]の速さで移動し、ゴールまでの距離はLである。
同着は1位としないとき、それぞれの人が勝つ確率を求めよ。

-----問題ここまで----- */
/* -----解説等-----

全探索可能。
iさんがk回休んで、それ以外の人jがk[j]回休むとして条件を満たすものを計算すれば良い。
確率は組み合わせと合体させればO(1)になる。

コーナーケースはv[i]=0.
ICPCっぽい.

----解説ここまで---- */

vector<double>p, t, v;
int N, M, L;

vector<double> fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1];
	}
}

double nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] / fact[n - r] / fact[r];
}

double modpow(double a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a, b / 2) * (b & 1 ? a : 1);
}

inline double pf(int i, int k) {// iさんがk回休憩する
	return pow(p[i], k)*pow(1 - p[i], M - k)* nCr(M, k);
}
inline double Len(int i, int k) {// iさんがk回休憩する
	return 1.*L / v[i] + 1.*t[i] * k;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> L;
	init_fact(101);
	p = vector<double>(N);
	t = p, v = p;
	FOR(i, 0, N) {
		cin >> p[i] >> t[i] >> v[i];
		p[i] /= 100;
	}
	// NMNM
	FOR(i, 0, N) { // iさん
		double ans = 0;
		if (v[i] < 1e-8) {
			cout << 0 << endl;
			continue;
		}
		FOR(k, 0, M + 1) {//k回休憩
			double ret = pf(i, k);
			double Mintime = Len(i, k);
			FOR(j, 0, N) {
				if (i == j)continue;
				//if (v[j] < 1e-8)continue;
				double sum = 0;
				FOR(m, 0, M + 1) { // j さんがm回休憩
					double Time = Len(j, m);
					if (Time < Mintime + 1e-8)continue;
					//cout << "P->(" << j << "," << m << ")=" << pf(j, m) << endl;
					sum += pf(j, m);
				}
				ret *= sum;
			}
			ans += ret;
		}
		cout << fixed << setprecision(10) << ans << endl;
	}

	return 0;
}

