#include <bits/stdc++.h>
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

/* -----  2017/11/29  Problem: 071_abc_b / Link: https://abc071.contest.atcoder.jp/tasks/abc071_b  ----- */
/* ------問題------

英小文字からなる文字列 S が与えられます． S に現れない英小文字であって，最も辞書順（アルファベット順）で小さいものを求めてください． ただし，S にすべての英小文字が現れる場合は，代わりに None を出力してください．

-----問題ここまで----- */
/* -----解説等-----

ない文字があったらそれが最小。
全部使ってたらNone.

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI a(26,0);
	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		a[s[i] - 'a']++;
	}
	FOR(i, 0, 26) {
		if (a[i] == 0) {
			cout << (char)('a' + i) << endl;
			return 0;
		}
	}
	cout << "None" << "\n";

	return 0;
}
