#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/09/20  Problem: ACPC2017_day3_c  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

カウントはする必要がなく、前から貪欲に、後ろから貪欲に文字列のindexを保存して、これが異なる場合はuniqueではないことになる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	VI a, b;
	int idx = 0;
	FOR(i, 0, SZ(s)) {
		if (t[idx] == s[i]) {
			a.push_back(i);
			++idx;
		}
	}
	idx = SZ(t) - 1;
	FORR(i, SZ(s) - 1, -1) {
		if (t[idx] == s[i]) {
			b.push_back(i);
			--idx;
		}
	}
	reverse(ALL(b));
	int flag = 0;
	if (SZ(a) == SZ(b) && SZ(a) == SZ(t)) {
		FOR(i, 0, SZ(a)) {
			if (a[i] != b[i])break;
			if (i == SZ(a) - 1)flag = 1;
		}

	}
	cout << ((flag==1)?"yes":"no") << "\n";

	return 0;
}