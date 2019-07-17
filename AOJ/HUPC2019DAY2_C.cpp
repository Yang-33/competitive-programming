#define _GLIBCXX_DEBUG
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

/* -----  2019/07/15  Problem: HUPC2019day2 C / Link: __CONTEST_URL__  ----- */


const int bssize = 100 + 1; // !!
using BS = bitset<bssize>;
template<size_t sz> struct bitset_comparer {
	bool operator() (const bitset<sz> &x, const bitset<sz> &y) const {
		for (int i = sz - 1; i >= 0; i--) {
			if (x[i] ^ y[i]) return y[i];
		}
		return false;
	}
};

map<BS, unsigned int, bitset_comparer<bssize>>memo;
const bool WIN = false;
const bool LOSE = true;
int A, B, C;

vector<int>selectable_UE(const BS& bb) {
	vector<int>res;
	FOR(i, 0, B) {
		FOR(j, 0, A) {
			int p = i * A + j;
			if (!bb[p])res.emplace_back(p);
		}
	}
	return res;
}


vector<int>selectable_TEMAE(const BS& bb) {
	vector<int>res;
	int base = B * A;
	FOR(i, 0, C) {
		FOR(j, 0, A) {
			int p = i * A + j + base;
			if (!bb[p])res.emplace_back(p);
		}
	}
	return res;
}

vector<int>selectable_MIGI(const BS& bb) {
	vector<int>res;
	int base = B * A + C * A;
	FOR(i, 0, C) {
		FOR(j, 0, B) {
			int p = i * B + j + base;
			if (!bb[p])res.emplace_back(p);
		}
	}
	return res;
}



BS fill_UE(const BS& bb, int pp) {
	int y = pp / A;
	int x = pp % A;
	auto res = bb;
	res[pp] = 1;
	{ // TEMAE
		int base = B * A;
		FOR(i, 0, C) {
			int p = base + x + i * A;
			res[p] = 1;
		}
	}

	{ // MIGI
		int migix = B - 1 - y;
		int base = B * A + C * A;
		FOR(i, 0, C) {
			int p = base + migix + i * B;
			res[p] = 1;
		}
	}
	return res;
}

BS fill_TEMAE(const BS& bb, int pp) {
	auto res = bb;
	res[pp] = 1;
	pp -= B * A;
	int y = pp / A;
	int x = pp % A;

	{ // UE
		FOR(i, 0, B) {
			int p = x + A * i;
			res[p] = 1;
		}
	}

	{ // MIGI
		int migiy = y;
		int base = B * A + C * A;
		FOR(i, 0, B) {
			int p = base + migiy * B + i;
			res[p] = 1;
		}
	}
	return res;
}

BS fill_MIGI(const BS& bb, int pp) {
	auto res = bb;
	res[pp] = 1;
	pp -= B * A + C * A;
	int y = pp / B;
	int x = pp % B;

	{ // UE
		int uey = B - 1 - x;
		FOR(i, 0, A) {
			int p = uey * A + i;
			res[p] = 1;
		}
	}

	{ // TEMAE
		int temaey = y;
		int base = B * A;
		FOR(i, 0, A) {
			int p = base + temaey * A + i;
			res[p] = 1;
		}
	}
	return res;
}




bool f(BS bb, bool turn) {
	bb[99] = turn;
	if (memo.count(bb))return memo[bb];
	bool gotolose = 0;
	{ // 上
		VI seue = selectable_UE(bb);
		for (auto p : seue) {
			if (f(fill_UE(bb, p), !turn) == LOSE) {
				gotolose = 1;
			}
		}
	}

	{ // 手前
		VI seue = selectable_TEMAE(bb);
		for (auto p : seue) {
			if (f(fill_TEMAE(bb, p), !turn) == LOSE) {
				gotolose = 1;
			}
		}

	}

	{ // 右
		VI seue = selectable_MIGI(bb);
		for (auto p : seue) {
			if (f(fill_MIGI(bb, p), !turn) == LOSE) {
				gotolose = 1;
			}
		}

	}

	return memo[bb] = (gotolose ? WIN : LOSE);
}

void test() {
	FOR(a, 1, 5) {
		FOR(b, 1, 5) {
			FOR(c, 1, 5) {
				BS s;
				FOR(i, 0, 100)s[i] = 0;
				memo.clear();
				A = a, B = b, C = c;
				bool res = f(s, 0);
				cout << a << "," << b << "," << c << ":=" << "WL"[res == LOSE] << endl;
				//return;
			}
		}
	}
}
int main() {
	//test();

	int A, B, C; cin >> A >> B >> C;
	int evencnt = (A % 2 == 0) + (B % 2 == 0) + (C % 2 == 0);
	if (evencnt < 2) {
		cout << "Hom" << endl;
	}
	else {
		cout << "Tem" << endl;
	}

	return 0;
}
