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

/* -----  2019/07/23  Problem: AOJ 0171 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0171  ----- */


using uLL = unsigned long long;

const uLL MOD = 1e9 + 7;
//BEGIN CUT HERE
struct Dice {
	int s[6];
	void roll(char c) {
		//the view from above
		// N
		//W E
		// S
		//va[0]:top
		//va[1]:south
		//va[2]:east
		//va[3]:west
		//va[4]:north
		//va[5]:bottom
		int b;
		if (c == 'E') {
			b = s[0];
			s[0] = s[3];
			s[3] = s[5];
			s[5] = s[2];
			s[2] = b;
		}
		if (c == 'W') {
			b = s[0];
			s[0] = s[2];
			s[2] = s[5];
			s[5] = s[3];
			s[3] = b;
		}
		if (c == 'N') {
			b = s[0];
			s[0] = s[1];
			s[1] = s[5];
			s[5] = s[4];
			s[4] = b;
		}
		if (c == 'S') {
			b = s[0];
			s[0] = s[4];
			s[4] = s[5];
			s[5] = s[1];
			s[1] = b;
		}

		// migi neji 
		if (c == 'R') {
			b = s[1];
			s[1] = s[2];
			s[2] = s[4];
			s[4] = s[3];
			s[3] = b;
		}

		if (c == 'L') {
			b = s[1];
			s[1] = s[3];
			s[3] = s[4];
			s[4] = s[2];
			s[2] = b;
		}

	}
	int top() {
		return s[0];
	}
	int south() {
		return s[1];
	}
	int east() {
		return s[2];
	}
	int west() {
		return s[3];
	}
	int north() {
		return s[4];
	}
	int bottom() {
		return s[5];
	}
	uLL hash() {
		uLL res = 1;
		for (int i = 0; i < 6; i++) res = res * (MOD)+s[i];
		return res;
	}
	bool operator < (const Dice &x)const {
		FOR(i, 0, 6)if (x.s[i] < s[i])return true;
		return false;
	}

};
vector<Dice> makeDices(Dice d) {
	vector<Dice> res;
	for (int i = 0; i < 6; i++) {
		Dice t(d);
		if (i == 1) t.roll('N');
		if (i == 2) t.roll('S');
		if (i == 3) t.roll('S'), t.roll('S');
		if (i == 4) t.roll('L');
		if (i == 5) t.roll('R');
		for (int k = 0; k < 4; k++) {
			res.push_back(t);
			t.roll('E');
		}
	}
	return res;
}

template<typename F>
struct FixPoint : F {
	FixPoint(F&& f) noexcept :F(forward<F>(f)) {}
	template<typename... Args>
	constexpr decltype(auto) operator()(Args&&... args) const noexcept {
		return F::operator()(*this, forward<Args>(args)...);
	}
};

template<typename F>
static inline constexpr decltype(auto) FUNC(F&& f) noexcept {
	return FixPoint<F>{forward<F>(f)};
}

int main() {
	string in;
	while (cin >> in, in != "0") {
		vector<vector<Dice>>ds; {
			VS vs(8); vs.front() = in;
			FOR(i, 1, 8) {
				cin >> in;
				vs[i] = in;
			}
			FOR(i, 0, 8) {
				Dice d; {
					FOR(j, 0, 6) {
						d.s[j] = vs[i][j];
					}
				}
				ds.emplace_back(makeDices(d));
			}
		}
		auto alphacheck = [](int a, int b) {
			bool small_big = (!!islower(a)) ^ (!!islower(b));
			bool same = tolower(a) == tolower(b);
			return !!(small_big & same);
		};
		assert(alphacheck('a', 'A') == true);
		assert(alphacheck('B', 'b') == true);
		assert(alphacheck('a', 'B') == false);

		Dice pos[2][2][2];
		auto check = [&](int id, int z, int y, int x, const Dice &d) {
			pos[z][y][x] = d;
			if (id == 0)return true;
			else if (id == 1) {
				return alphacheck(pos[0][0][0].east(), pos[0][0][1].west());
			}
			else if (id == 2) {
				return alphacheck(pos[0][0][0].south(), pos[0][1][0].north());
			}
			else if (id == 3) {
				return alphacheck(pos[0][0][1].south(), pos[0][1][1].north())
					&& alphacheck(pos[0][1][0].east(), pos[0][1][1].west());
			}
			else if (id == 4) {
				return  alphacheck(pos[0][0][0].bottom(), pos[1][0][0].top());
			}
			else if (id == 5) {
				return alphacheck(pos[1][0][0].east(), pos[1][0][1].west())
					&& alphacheck(pos[0][0][1].bottom(), pos[1][0][1].top());
			}
			else if (id == 6) {
				return alphacheck(pos[1][0][0].south(), pos[1][1][0].north())
					&& alphacheck(pos[0][1][0].bottom(), pos[1][1][0].top());
			}
			else if (id == 7) {
				return alphacheck(pos[0][1][1].bottom(), pos[1][1][1].top())
					&& alphacheck(pos[1][0][1].south(), pos[1][1][1].north())
					&& alphacheck(pos[1][1][0].east(), pos[1][1][1].west());
			}
			// N
			//W E
			// S
		};
		auto func = FUNC([&](auto f, int idx, int S)->bool {
			if (S == (1 << 8) - 1)return true;
			FOR(i, 0, 8) {
				if (S & 1 << i)continue;
				FOR(j, 0, 24) {
					if (check(idx, idx / 4, (idx % 4) / 2, idx % 2, ds[i][j])
						&& f(idx + 1, S | (1 << i)))return true;
				}
			}
			return false;
		});
		cout << (func(0, 0) ? "YES" : "NO") << "\n";
	}

	return 0;
}