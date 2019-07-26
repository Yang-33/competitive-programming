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

/* -----  2019/07/24  Problem: AOJ 0179 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0179  ----- */


int main() {
	string s;
	while (cin >> s, s != "0") {
		auto color = [](char a, char b) {
			string rbg = "rbg";
			FOR(i, 0, 3) {
				char c = rbg[i];
				if (c != a && c != b)return c;
			}
		};
		auto nextnode = [&color](const string&s) {
			VS res;
			FOR(i, 0, SZ(s) - 1) {
				if (s[i] != s[i + 1]) {
					string t = s;
					int l = i; 
					int r = i + 1; 
					//[l..r]は同じ色に
					char c = color(s[i], s[i + 1]);
					FOR(x, l, r + 1) {
						t[x] = c;
					}
					res.emplace_back(t);
				}
			}
			return res;
		};

		using tp = tuple<int, string>;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		map<string, int>dist;
		const string allr = string(SZ(s), 'r');
		const string allg = string(SZ(s), 'g');
		const string allb = string(SZ(s), 'b');
		auto IFPUSH = [&](const string&nx, int c) {
			if (dist.count(nx)) {
				if (dist[nx] > c) {
					dist[nx] = c;
					q.emplace(c, nx);
				}
			}
			else {
				dist[nx] = c;
				q.emplace(c, nx);
			}
		};
		IFPUSH(s, 0);
		while (!q.empty()) {
			int d; string t;
			if (t == allr || t == allg || t == allb)continue;
			tie(d, t) = q.top(); q.pop();
			for (auto nx : nextnode(t)) {
				IFPUSH(nx, d + 1);
			}
		}
		LL ans = LINF; {
			for (auto it : { allr,allg,allb }) {
				if (dist.count(it))ans = min(ans, (LL)dist[it]);
			}
		}
		if (ans == LINF)puts("NA");
		else cout << (ans) << "\n";
	}

	return 0;
}
