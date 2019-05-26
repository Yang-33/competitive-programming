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

/* -----  2019/05/26  Problem: AOJ 2534 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2534  ----- */
template<typename T>
vector<T> topological_sort(const vector<vector<T>> &g) {
	int n = (int)g.size(), k = 0;
	vector<T> ord(n, 0), in(n, 0);
	for (int i = 0; i < (int)g.size(); i++)
		for (int j = 0; j < (int)g[i].size(); j++)
			in[g[i][j]]++;//入次数

	queue<T> q;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0) q.push(i);//0なら先頭

	while (q.size()) {
		int v = q.front(); q.pop();
		ord[k++] = v;//番号付けと緩和
		for (int i = 0; i < (int)g[v].size(); i++)
			if (--in[g[v][i]] == 0) q.push(g[v][i]);
	}
	return *max_element(in.begin(), in.end()) == 0 ? ord : vector<T>();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// isdag?
	int N;
	while (cin >> N, N) {
		// n:500, s:10
		// prefixが同じやつの次に対して定義
		// 隣だけみても問題ない
		VS a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		bool ok = 1;
		VVI G(26);// s<t : s->t
		FOR(i, 0, N - 1) {
			string s = a[i];
			string t = a[i + 1];
			DD(de(s, t));
			bool diff = 0;
			FOR(x, 0, min(SZ(s), SZ(t))) {
				if (s[x] == t[x])continue;
				else {
					diff = 1;
					s[x] -= 'a';
					t[x] -= 'a';
					G[s[x]].push_back(t[x]);
					DD(de(int(s[x]), "->", int(t[x])));
					break;
				}
			}
			if (!diff && (SZ(s) > SZ(t))) {
				ok = 0;
			}
		}
		DD(de(ok));
		ok &= topological_sort(G) != VI();
		auto print_yesno = [](LL yes, int mode = 0) {
			if (mode == 0) {
				cout << (yes ? "yes" : "no") << endl;
			}
			else if (mode == 1) {
				cout << (yes ? "Yes" : "No") << endl;
			}
			else if (mode == 2) {
				cout << (yes ? "YES" : "NO") << endl;
			}
			else assert(0);
		};
		print_yesno(ok, 0);
	}

	return 0;
}
