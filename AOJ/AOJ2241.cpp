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

/* -----  2019/05/26  Problem: AOJ 2241 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2241  ----- */
struct Bingo {
	std::map<int, std::pair<int, int>> card;
	std::vector<int> row, col, diag;
	int num_bingo, size;

	Bingo(int n) :
		row(n), col(n), diag(2), num_bingo(0), size(n)
	{}

	void preset(int r, int c, int x) {
		card[x] = std::make_pair(r, c);
	}
	// 揃った数を全部返す
	int set(int x) {
		auto it = card.find(x);
		if (it == card.end())
			return num_bingo;

		const std::pair<int, int> &p = it->second;

		if (++row[p.first] == size)
			++num_bingo;

		if (++col[p.second] == size)
			++num_bingo;

		if (p.first == p.second)
			if (++diag[0] == size)
				++num_bingo;

		if (p.first + p.second + 1 == size)
			if (++diag[1] == size)
				++num_bingo;

		if (num_bingo && size == 1)
			return (num_bingo = 1);

		return num_bingo;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// やる
	int N, UsaN, NekoN, Q; cin >> N >> UsaN >> NekoN >> Q;
	// UsaN,NekoNを超えれば勝ち

	Bingo usa(N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int a; cin >> a;
			usa.preset(i, j, a);
		}
	}
	Bingo neko(N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int a; cin >> a;
			neko.preset(i, j, a);
		}
	}

	FOR(_, 0, Q) {
		// O(Qn)
		int a; cin >> a;
		int usaval = usa.set(a);
		int nekoval = neko.set(a);
		bool usawin = usaval >= UsaN;
		bool nekowin = nekoval >= NekoN;
		if (usawin&&nekowin) {
			cout << "DRAW" << endl; return 0;
		}
		else if (usawin) {
			cout << "USAGI" << endl; return 0;
		}
		else if (nekowin) {
			cout << "NEKO" << endl; return 0;
		}

	}

	cout << "DRAW" << endl;
	return 0;
}
