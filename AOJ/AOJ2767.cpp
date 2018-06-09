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

/* -----  2018/06/09  Problem: AOJ 2767 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2767  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

アルファベットにつく係数を分解することが最適になることはない。
したがって、まずアルファベットにつく係数で分ける。
+の数は係数の種類-1個である。
あとはある係数について、アルファベットが2つ以上あるかどうかを見て()をつければよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string s; cin >> s;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	int cnt[30] = {};
	FOR(i, 0, N) {
		if (s[i] == '+') continue;
		cnt[s[i] - 'a'] += 1;
	}
	int ans = 0;
	set<int>se;
	FOR(i, 0, 30) {
		if (cnt[i])se.insert(cnt[i]);
	}
	ans = SZ(se) - 1; // ただしい
	int apcnt[30] = {};
	int flag = 0;
	FOR(i, 0, 30) {
		if (cnt[i] == 1) { // あるアルファベットの長さが1のとき
			if (flag)
				ans += 2;
			else flag = 1, ans += 1;

		}
		else if (cnt[i]) {
			apcnt[cnt[i]]++;
		}
	}
	FOR(i, 0, 30) { // apcnt
		if (apcnt[i] == 1) {// ながさiの出現回数が一回
			ans += 3;
		}
		else if (apcnt[i] == 2) {
			ans += 7;
		}
		else if (apcnt[i]) {
			ans += 2 * apcnt[i] + 3;
		}
	}
	cout << ans << endl;

	return 0;
}
