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

/* -----  2018/04/12  Problem: yukicoder 052  / Link: http://yukicoder.me/problems/no/052  ----- */
/* ------問題------

文字列Sが与えられる。
文字列Sの「先頭」または「末尾」から１文字ずつ文字をとってきて、
取った文字列とは別に、取った文字を順番につなげて新たに文字列を作る。
Sは、文字を取った後の文字列を新たなSとしてSの文字列がなくなるまで繰り返す。

この時、新たにできる文字列は何通りの文字列ができるか？

-----問題ここまで----- */
/* -----解説等-----

愚直に全探索する。

----解説ここまで---- */

LL N;

LL ans = 0LL;

void search(string s, set<string>& se, string res = "") {
	if (SZ(s) == 0) {
		se.insert(res);
		return;
	}
	search(s.substr(1, SZ(s) - 1), se, res + s.front());
	search(s.substr(0, SZ(s) - 1), se, res + s.back());
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	set<string> se;
	search(s, se);
	ans = SZ(se);
	cout << ans << "\n";


	return 0;
}
