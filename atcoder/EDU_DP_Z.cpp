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

/* -----  2019/01/06  Problem: EDU_DP Z / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

C!H!T!

----解説ここまで---- */


typedef long long  Type_CHT;
typedef pair<Type_CHT, Type_CHT> PT;

struct CHT2 {

	struct L {
		Type_CHT a, b;
		L(Type_CHT a, Type_CHT b) : a(a), b(b) {}
		bool operator<(const L &rhs) const {
			return a != rhs.a ? a > rhs.a : b < rhs.b;
		}
	};

	struct CP {
		Type_CHT n, d;
		L p;
		CP(Type_CHT _n, Type_CHT _d, const L &p) :n(_n), d(_d), p(p) {
			if (d < 0) { n *= -1; d *= -1; }
		}
		bool operator<(const CP &rhs) const {
			if (n == LINF || rhs.n == -LINF) return 0;
			if (n == -LINF || rhs.n == LINF) return 1;
			return n * rhs.d < rhs.n*d;
		}
	};
	typedef set<L>::iterator It;
	set<L> S;
	set<CP> C;

public:
	CHT2() {
		// 番兵
		S.insert({ L(LINF,0), L(-LINF,0) });
		C.insert(cp(L(LINF, 0), L(-LINF, 0)));
	}
	// for debug
	void print() {
		cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
		cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
	}

	void add(Type_CHT a, Type_CHT b) {
		const L p(a, b);
		It pos = S.insert(p).first;
		if (check(*it_m1(pos), p, *it_p1(pos))) {
			// 直線(a,b)が不要
			S.erase(pos);
			return;
		}
		C.erase(cp(*it_m1(pos), *it_p1(pos)));
		{
			// 右方向の削除
			It it = it_m1(pos);
			while (it != S.begin() && check(*it_m1(it), *it, p)) --it;
			C_erase(it, it_m1(pos));
			S.erase(++it, pos);
			pos = S.find(p);
		}
		{
			// 左方向の削除
			It it = it_p1(pos);
			while (it_p1(it) != S.end() && check(p, *it, *it_p1(it))) ++it;
			C_erase(++pos, it);
			S.erase(pos, it);
			pos = S.find(p);
		}
		C.insert(cp(*it_m1(pos), *pos));
		C.insert(cp(*pos, *it_p1(pos)));
	}
	Type_CHT query(Type_CHT x) {
		const L &p = (--C.lower_bound(CP(x, 1, L(0, 0))))->p;
		return p.a*x + p.b;
	}

private:
	It it_p1(It a) { return ++a; }
	It it_m1(It a) { return --a; }
	void C_erase(It a, It b) {
		for (It it = a; it != b; ++it) C.erase(cp(*it, *it_p1(it)));
	}
	CP cp(const L &p1, const L &p2) {
		if (p1.a == LINF) return CP(-LINF, 1, p2);
		if (p2.a == -LINF) return CP(LINF, 1, p2);
		return CP(p1.b - p2.b, p2.a - p1.a, p2);
	}
	bool check(const L &p1, const L &p2, const L &p3) {
		if (p1.a == p2.a && p1.b <= p2.b) return 1;
		if (p1.a == LINF || p3.a == -LINF) return 0;
		return (p2.a - p1.a)*(p3.b - p2.b) >= (p2.b - p1.b)*(p3.a - p2.a);
	}
};
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, C;
	cin >> N >> C;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL dp(N);
	CHT2 CHT;
	dp[0] = 0;
	CHT.add(2*a.front(), a.front()*a.front());
	FOR(i, 1, N) {
		dp[i] = CHT.query(-a[i]) + a[i] * a[i] + C;
		CHT.add(2 * a[i], dp[i] + a[i] * a[i]);
	}

	ans = dp[N - 1];


	cout << ans << "\n";

	return 0;
}
