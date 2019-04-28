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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/24  Problem: ABC 123 D / Link: http://abc123.contest.atcoder.jp/tasks/abc123_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, C; cin >> A >> B >> C;
	int K; cin >> K;
	vector<LL> a(A);
	for (int i = 0; i < A; ++i) {
		cin >> a[i];
	}
	vector<LL> b(B);
	for (int i = 0; i < B; ++i) {
		cin >> b[i];
	}
	vector<LL> c(C);
	for (int i = 0; i < C; ++i) {
		cin >> c[i];
	}
	RSORT(a);
	RSORT(b);
	RSORT(c);
	using tp = tuple<LL, int, int, int>;
	priority_queue<tp>pq;
	pq.push(tp(a.front() + b.front() + c.front(), 0, 0, 0));
	set<tp>se;
	while (K) {
		LL val;
		int ai, bi, ci;
		tie(val, ai, bi, ci) = pq.top(); pq.pop();
		if (se.count(tp(val, ai, bi, ci))) {
			continue;
		}
		se.insert(tp(val, ai, bi, ci));
		K--;
		DD(de(ai, bi, ci))
			cout << val << endl;
		if (ai + 1 < A) {
			pq.push(tp(a[ai + 1] + b[bi] + c[ci], ai + 1, bi, ci));
		}
		if (bi + 1 < B) {
			pq.push(tp(a[ai] + b[bi + 1] + c[ci], ai, bi + 1, ci));
		}
		if (ci + 1 < C) {
			pq.push(tp(a[ai] + b[bi] + c[ci + 1], ai, bi, ci + 1));
		}
	}

	return 0;
}
