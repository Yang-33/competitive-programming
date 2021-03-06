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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/19  Problem: CodeForces505 A div2 / Link: http://codeforces.com/contest/1025/problem/A  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

|S|=1に注意

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	string s; cin >> s;
	int f = 0;
	VI col(26, 0);
	FOR(i, 0, SZ(s)) {
		col[s[i] - 'a']++;
	}
	FOR(i, 0, 26) {
		if (col[i] >1)f = 1;
	}
	if (SZ(s) == 1)f = 1;


	cout << (f ? "Yes" : "No") << endl;

	return 0;
}
