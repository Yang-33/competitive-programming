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

/* -----  2019/06/15  Problem: diverta2019-2 C / Link: https://atcoder.jp/contests/diverta2019-2  ----- */


// 操作をしても変わらない要素に着目する

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	SORT(a);
	vector<int> minus, plus;
	FOR(i, 1, N - 1) {
		if (a[i] <= 0) {
			minus.push_back(a[i]);
		}
		else {
			plus.push_back(a[i]);
		}
	}

	//minus.push_back(a.back());
	//plus.push_back(a.front());
	vector<PII>ans;
	int L = a.front();
	for (auto it : plus) {
		ans.push_back(PII(L, it));
		L = L - it;
	}
	DD(de(L));
	int R = a.back();
	for (auto it : minus) {
		ans.push_back(PII(R, it));
		R = R - it;
	}
	DD(de(R));
	ans.push_back(PII(R, L));
	cout << R - L << endl;
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}

	return 0;
}
