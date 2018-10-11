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

/* -----  2018/10/13  Problem: ARC 039 A / Link: http://arc039.contest.atcoder.jp/tasks/arc039_a  ----- */
/* ------問題------

高橋君は次のような問題を考えました。
3 桁の整数 A、B が与えられるので A−B を求める。
しかしあまりにも簡単すぎるので、ちょっと変更して次のような問題にしました。

3 桁の整数 A、B が与えられる。
A と B のどちらかを 1 桁だけ書き換えてもよい時の、A−B の答えになり得る整数の最大値を求める。
なお、一番上の桁が 0 であるような整数へと書き換えることはできません。 例えば 123 を 023 へと書き換えたりすることはできません。
高橋君は自信満々であなたへとこの問題を出題してきました。 ぜひ挑戦してみてください。

-----問題ここまで----- */
/* -----解説等-----

実際に6箇所試す。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string A, B; cin >> A >> B;

	int ans = -10000;
	auto f = [](string a, string b) {
		int res = 0;
		res = stoi(a) - stoi(b);
		return res;
	};
	auto g = [](string s, int pos, int val) {
		s[pos] = '0' + val;
		return s;
	};
	{ // A
		FOR(i, 0, 3) {
			ans = max(ans, f(g(A, i, 9), B));
		}
	}
	{ // B
		ans = max(ans, f(A, g(B, 0, 1)));
		ans = max(ans, f(A, g(B, 1, 0)));
		ans = max(ans, f(A, g(B, 2, 0)));
	}

	cout << ans << "\n";

	return 0;
}