#include <bits/stdc++.h>
#include <unordered_map>
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

/* -----  2018/08/19  Problem: CodeForces505 B div2 / Link: http://codeforces.com/contest/1025/problem/B  ----- */
/* ------問題------

WSDを求める

-----問題ここまで----- */
/* -----解説等-----

定数倍高速化やめてくれ

----解説ここまで---- */

LL N;
vector<LL> getdivisor(LL n) {
	vector<LL> res;
	res.push_back(n);
	for (long long i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	UNIQ(res);
	return res;
}

int main() {
	scanf("%lld", &N);
	vector<PLL>a(N);
	PLL b(LINF, LINF);
	FOR(i, 0, N) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
		if (a[i].first > a[i].second)swap(a[i].first, a[i].second);
		b = min(b, PLL(a[i].first, a[i].second));
	}
	SORT(a);
	UNIQ(a);
	N = SZ(a);
	VL bs = getdivisor(b.first);
	VL bc = getdivisor(b.second);
	set<LL> s;
	FOR(i, 0, SZ(bs))if (bs[i] != 1)s.insert(bs[i]);
	FOR(i, 0, SZ(bc))if (bc[i] != 1)s.insert(bc[i]);

	for (auto it : s) {

		int f = 1;
		FOR(i, 0, N) {
			if(a[i].first%it==0 || a[i].second%it==0){}
			else { f = 0; break; }
		}
		if (f) { cout << it << endl; return 0; }
	}

	cout << -1 << "\n";

	return 0;
}
