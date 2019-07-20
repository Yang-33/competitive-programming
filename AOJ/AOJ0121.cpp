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

/* -----  2019/07/20  Problem: AOJ 0121 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0121  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}

const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
int main() {
	const VI com({ 0,1,2,3,4,5,6,7 });
	map<VI, int>m;
	using PVII = tuple<VI, int, int>;
	queue<PVII>q;
	auto IFPUSH = [&](const VI&a, int d, int zp) {
		if (m.find(a) != m.end()) {
			if (m[a] > d) {
				m[a] = d;
				q.emplace(a, d, zp);
			}
		}
		else {
			m[a] = d;
			q.emplace(a, d, zp);
		}
	};
	IFPUSH(com, 0, 0);
	while (!q.empty()) {
		VI a; int d, zp;
		tie(a, d, zp) = q.front(); q.pop();
		FOR(k, 0, 4) {
			int ny = zp / 4 + DY[k], nx = zp % 4 + DX[k];
			if (is_in(0, ny, 2) && is_in(0, nx, 4)) {
				int nzp = ny * 4 + nx;
				swap(a[zp], a[nzp]);
				IFPUSH(a, d + 1, nzp);
				swap(a[zp], a[nzp]);
			}
		}
	}

	string in;
	while (getline(cin, in)) {
		auto input = deletecommma(in);
		VI a(8); {
			FOR(i, 0, 8) {
				input >> a[i];
			}
		}
		LL ans = m[a];
		cout << (ans) << "\n";
	}

	return 0;
}
