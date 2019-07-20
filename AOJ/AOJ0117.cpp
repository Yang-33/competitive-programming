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

/* -----  2019/07/20  Problem: AOJ 0117 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0117  ----- */


stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}
int main() {
	LL N; cin >> N;
	LL M; cin >> M;
	VVL dist(N, VL(N, LINF));
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(i, 0, M) {
		string in; cin >> in;
		auto input = deletecommma(in);
		LL a, b, c, d; input >> a >> b >> c >> d;
		a--, b--;
		dist[a][b] = c;
		dist[b][a] = d;
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	string in; cin >> in;
	auto input = deletecommma(in);
	LL S, T, V, P; input >> S >> T >> V >> P;
	S--, T--;
	LL ans = V - P - dist[S][T] - dist[T][S];
	cout << (ans) << "\n";

	return 0;
}
