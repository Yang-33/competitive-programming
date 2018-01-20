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
#define debug(x) cout<< #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/20  Problem: colcon_final_2017 C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

式変形したあと何すればいいのかわからず
ConvexHullTrickを学ぶと線分集合の最小値とかが取れるのでできる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

/*-------------------------
ConVex Hull Trick
https://colopl2018-final.contest.atcoder.jp/tasks/colopl2018_final_c
ランダムクエリに対応したやつ
追加 O(logN)

--------------------------*/

struct ConvexHullTrick {
	ConvexHullTrick() {
		S.insert({ Line(INF,0), Line(-INF,0) });
		C.insert(cp(Line(INF, 0), Line(-INF, 0)));
	}

	void Debug() {
		cout << "S : "; for (auto it : S) printf("(%lld,%lld)", it.a, it.b); puts("");
		cout << "C : "; for (auto it : C) printf("(%lld,%lld)", it.n, it.d); puts("");
	}

	// |ab| < LLONG_MAX/4 ???
	void add(long long a, long long b) {
		const Line p(a, b);
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
	long long query(long long x) {
		const Line &p = (--C.lower_bound(CP(x, 1, Line(0, 0))))->p;
		return p.a*x + p.b;
	}

private:

	template<class T> T it_p1(T a) { return ++a; }
	template<class T> T it_m1(T a) { return --a; }
	struct Line {
		long long  a, b;
		Line(long long a, long long  b) : a(a), b(b) {}
		bool operator<(const Line &rhs) const {
			return a != rhs.a ? a > rhs.a : b < rhs.b;
		}
	};

	struct CP {
		long long n, d;
		Line p;
		CP(long long _n, long long _d, const Line &p) : n(_n), d(_d), p(p) {
			if (d < 0) { n *= -1; d *= -1; }
		};
		bool operator<(const CP &rhs) const {
			if (n == INF || rhs.n == -INF) return 0;
			if (n == -INF || rhs.n == INF) return 1;
			return n * rhs.d < rhs.n * d;
		}
	};
	set<Line> S;
	set<CP> C;

	typedef set<Line>::iterator It;

	void C_erase(It a, It b) {
		for (It it = a; it != b; ++it)
			C.erase(cp(*it, *it_p1(it)));
	}
	CP cp(const Line &p1, const Line &p2) {
		if (p1.a == INF) return CP(-INF, 1, p2);
		if (p2.a == -INF) return CP(INF, 1, p2);
		return CP(p1.b - p2.b, p2.a - p1.a, p2);
	}
	bool check(const Line &p1, const Line &p2, const Line &p3) {
		if (p1.a == p2.a && p1.b <= p2.b) return 1;
		if (p1.a == INF || p3.a == -INF) return 0;
		return (p2.a - p1.a)*(p3.b - p2.b) >= (p2.b - p1.b)*(p3.a - p2.a);
	}
};




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ConvexHullTrick C;
	C.add(2, 2);
	C.add(-1, 10);
	C.add(1, 3);
	C.print();
	FOR(i, 0, 10) {
		cout << i << " "; debug(C.query(i));
	}


	return 0;
}
