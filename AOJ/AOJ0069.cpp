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

/* -----  2019/07/14  Problem: AOJ 0069 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0069  ----- */


typedef pair<int, int>P;

char s[30][11];
int main() {
	int n;
	while (scanf("%d", &n), n) {
		int m, h, d; scanf("%d%d%d", &m, &h, &d);
		m--; h--;
		FOR(i, 0, d)scanf("%s", s[i]);
		{
			vector<P>v;
			FOR(k, 0, d)FOR(t, 0, n - 1) {
				if (s[k][t] == '1')v.push_back(P(t, t + 1));
			}
			int pos = m;
			for (P p : v) {
				if (p.first == pos)pos = p.second;
				else if (p.second == pos)pos = p.first;
			}
			if (pos == h) {
				puts("0");
				goto g;
			}
		}
		FOR(i, 0, d)FOR(j, 0, n - 1) {
			if (s[i][j] == '1' || (j&&s[i][j - 1] == '1') || (j + 1 < n - 1 && s[i][j + 1] == '1'))continue;
			vector<P>v;
			s[i][j] = '1';
			FOR(k,0, d)FOR(t, 0,n - 1) {
				if (s[k][t] == '1')v.push_back(P(t, t + 1));
			}
			int pos = m;
			for (P p : v) {
				if (p.first == pos)pos = p.second;
				else if (p.second == pos)pos = p.first;
			}
			if (pos == h) {
				printf("%d %d\n", i + 1, j + 1);
				goto g;
			}
			s[i][j] = '0';
		}
		puts("1");
	g:;
	}
}