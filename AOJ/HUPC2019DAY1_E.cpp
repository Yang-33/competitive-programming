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

/* -----  2019/07/14  Problem: HUPC2019day1 E / Link: __CONTEST_URL__  ----- */


int main() {

	auto ask = [&](int a, int b) {
		cout << "? " << a + 1 << " " << b + 1 << endl;
		int res; cin >> res;
		return res;
	};

	int N, S, T; cin >> N >> S >> T;
	S--, T--;
	int optD = ask(S, T);
	vector<PII>edge;
	map<PII, int> M;
	FOR(i, 0, N) {
		if (i == S || i == T)continue;
		int si = ask(S, i);
		int it = ask(i, T);
		if (si + it == optD) {
			edge.push_back(PII(si, i));
			M[PII(S, i)] = si;
			M[PII(i, T)] = it;
		}
	}
	SORT(edge);
	// 2N回きいた
	// ふくげんする
	VI ans;
	ans.push_back(S);
	ans.push_back(edge.front().second);
	int pre = edge.front().second;
	FOR(i, 1, SZ(edge)) {// <=2N-2
		int nx = edge[i].second;
		int di = ask(pre, nx);
		if (M[PII(S, pre)] + di == M[PII(S, nx)]) {
			ans.push_back(nx);
			pre = nx;
		}
	}
	ans.push_back(T);
	cout << "! ";
	FOR(i, 0, SZ(ans)) {
		cout << ans[i] + 1;
		if (i + 1 != SZ(ans))cout << " ";
	}
	cout << endl;

	return 0;
}
