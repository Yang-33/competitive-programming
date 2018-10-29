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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/28  Problem: ARC 043 C / Link: http://arc043.contest.atcoder.jp/tasks/arc043_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

https://beta.atcoder.jp/contests/arc043/submissions/981943
むずかしい

----解説ここまで---- */
template<typename type>
struct BIT {
	int N;
	vector<type> data;
	BIT(int n) : N(n), data(n + 1, 0) {}
	void add(int i, type w) {
		for (int x = i; x < N; x |= x + 1) {
			data[x] += w;
		}
	}
	type sum(int i) {
		type ret = 0;
		for (int x = i - 1; x >= 0; x = (x&(x + 1)) - 1) {
			ret += data[x];
		}
		return ret;
	}
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	VI dict(N + 1), rev_dict(N + 1);
	FOR(i, 0, N) {
		dict[a[i]] = i + 1;
		rev_dict[i + 1] = a[i];
		a[i] = i + 1;
	}
	FOR(i, 0, N) {
		b[i] = dict[b[i]];
	}

	BIT<LL>bit(N + 1);
	LL inversion = 0;
	FOR(i, 0, N) {
		inversion += i - bit.sum(b[i] + 1);
		bit.add(b[i] + 1, 1);
	}

	if (inversion % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	BIT<LL>bitc(N + 1);
	LL inversionC = inversion;
	int ub = N;

	FOR(i, 0, N) {
		int sub = i - bitc.sum(b[i] + 1);
		if (inversionC - sub < inversion / 2) {
			ub = i;
			break;
		}
		else {
			inversionC -= sub;
			bitc.add(b[i] + 1, 1);
		}
	}
	VI c = b;
	sort(c.begin(), c.begin() + ub);

	for (int i = ub - 1; i >= 0; i--) {
		if (inversionC == inversion / 2)break;
		if (c[i] > c[i + 1]) {
			inversionC--;
			swap(c[i], c[i + 1]);
		}

	}

	FOR(i, 0, N) {
		cout << rev_dict[c[i]] << " \n"[i == N - 1];
	}

	return 0;
}
