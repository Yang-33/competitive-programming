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

/* -----  2018/08/02  Problem: yukicoder 204  / Link: http://yukicoder.me/problems/no/204  ----- */
/* ------問題------

巷ではゴールデンウィークらしいです。
なのでゴールデンウィークっぽい問題です。

2週間分の平日(x)と休日(o)が分かるカレンダーが与えられます。
この2週間の期間以外は、平日とします。

そして有給休暇として、連続した最大D日間の平日を休日とする権利が与えられます。
（分割してはいけません）

この有給休暇をうまく使って、あり得る最大の連休（連続の休日）数を求めてください。

日付は、後にも先にも無限にあるものとします。

-----問題ここまで----- */
/* -----解説等-----

日本語を読む+注意力

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int D; cin >> D;
	string s, s2;  cin >> s >> s2;
	s += s2;
	int ans = 0;
	auto getmax = [&ans](const string& ss) {
		int cnt = 0;
		FOR(j, 0, SZ(ss)) {
			if (ss[j] == 'o')cnt++, ans = max(ans, cnt);
			else cnt = 0;
		}
	};
	FOR(i, 0, SZ(s)) {
		string ss = s;
		FOR(d, 0, D) {
			if (i + d < SZ(s) && ss[i + d] == 'x')ss[i + d] = 'o';
			else if (i + d >= SZ(s))ss += string(1, 'o');
			else break;
		}
		getmax(ss);
	}
	{
		int pos = 0;
		FORR(i, SZ(s), 0 - 1) {
			if (s[i] == 'o')pos = i;
		}
		string ss = string(D, 'o') + s.substr(pos);
		getmax(ss);
	}
	{
		int pos = 0;
		FOR(i, 0, SZ(s)) {
			if (s[i] == 'o')pos = i;
		}
		string ss = s.substr(0, pos + 1) + string(D, 'o');
		getmax(ss);
	}

	cout << ans << "\n";

	return 0;
}
