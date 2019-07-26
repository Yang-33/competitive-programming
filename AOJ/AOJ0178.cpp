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

/* -----  2019/07/24  Problem: AOJ 0178 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0178  ----- */

// field:先に全部確保しておく
// pino:ブロックの最小bounding box(0/1)
// sl:落とすブロックの左端(pinoが左に詰まっているとする)
int fall(vector<vector<int>>&field, vector<vector<int>>&pino, int sl) {
	int y = 0; {
		for (y = 0; y < field.size() - pino.size(); ++y) {
			bool ok = true;
			for (int i = 0; i < pino.size(); ++i) {
				for (int j = 0; j < pino[i].size(); ++j) {
					if (pino[i][j]) {
						if (field[y + i + 1][sl + j])ok = false;
					}
				}
			}
			if (!ok) {
				break;
			}
		}
	}
	for (int i = 0; i < pino.size(); ++i) {
		for (int j = 0; j < pino[i].size(); ++j) {
			if (pino[i][j]) {
				assert(!field[y + i][sl + j]);
				field[y + i][sl + j] = true;
			}
		}
	}
	int delline = 0;
	for (int i = y + pino.size() - 1; i >= y; --i) {
		while (all_of(field[i].begin(), field[i].end(), [](const int a) {return a == 1; })) {
			transform(field[i].begin(), field[i].end(), field[i].begin(), [](const int a) {return false; });
			for (int j = i - 1; j >= 0; --j) {
				swap(field[j], field[j + 1]);
			}
			delline += 1;
		}
	}
	return delline;
}

void solve_AOJ0178() {
	int N;
	while (cin >> N, N) {
		int sum = 0;
		VVI field(5 * N, VI(5));
		FOR(_, 0, N) {
			int d, p, q; cin >> d >> p >> q;
			q--;
			sum += p;
			VVI pino(d == 1 ? 1 : p, VI(d == 2 ? 1 : p, 1));
			sum -= fall(field, pino, q) * 5;
		}
		cout << sum << endl;
	}
}

int main() {
	solve_AOJ0178();
	return 0;
}
