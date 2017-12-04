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

/* -----  2017/12/04  Problem: codefestival2017_team_relay G / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_g  ----- */
/* ------問題------

英小文字からなる二つの文字列 s, t と整数 L が与えられます。
s, t を任意の順に一個以上並べて長さ L の文字列を生成することを考えます。このとき、同じ文字列を複数回用いることもできます。
例えば、s= at, t= code, L=6 のとき、文字列 atatat, atcode, codeat を生成することができます。
このようにして生成される長さ L の文字列のうち、辞書順最小のものを求めてください。なお、入力として与えられるケースでは、長さ L の文字列を生成することは必ず可能です。

-----問題ここまで----- */
/* -----解説等-----

最初は辞書順に最小を並べればおしまいと思ったが、これは嘘。
S = "aba"
T = "ab"
=> S+T = "abaab" , T+S = "ababa"
と、目的としている形に対して、S+T < T+S だが T < S が存在する。
S+T < T+S  となるように s < t と並べ、
求めたいのは、As+Btみたいな文字列なのであとはコレの長さがLとなるように並べる。

----解説ここまで---- */

LL L;

string ans = "";

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> L;
	string s, t;
	cin >> s >> t;
	LL ssize = SZ(s);
	LL tsize = SZ(t);
	if (s + t > t + s)swap(s, t); // sのほうがちいさい
	ssize = SZ(s);
	tsize = SZ(t);
	FORR(i, L, 0 - 1) {
		LL left = ssize * i;
		if ((L - left) >= 0 && (L - left) % tsize == 0) {
			FOR(k, 0, i)ans += s;
			FOR(k, 0, (L - left) / tsize)ans += t;
			break;
		}
	}
	assert(L == SZ(ans));

	cout << ans << "\n";

	return 0;
}
