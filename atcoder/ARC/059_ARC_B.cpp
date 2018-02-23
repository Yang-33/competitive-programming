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

/* -----  2018/02/23  Problem: 059_arc_b / Link: https://abc043.contest.atcoder.jp/tasks/arc059_b?lang=en  ----- */
/* ------問題------

文字列 t について、t の長さが 2 以上であり、かつ t の中の文字のうち過半数が同じ文字であるとき、t をアンバランスであると呼ぶことにします。例えば、voodoo や melee はアンバランスであり、noon や a はアンバランスではありません。
小文字のアルファベットからなる文字列 s が与えられます。s にアンバランスな (連続する) 部分文字列が存在するか判定してください。存在する場合は、s の中でそのような部分文字列が存在する位置を一つ示してください。

-----問題ここまで----- */
/* -----解説等-----

例えば長さ4のアンバランスな文字列があったとき、この中には長さ2か3のアンバランスな文字列を含んでいる。
同様にアンバランスな文字列の中には2,3の長さのアンバランスな文字列が含まれているのでこれを判定するだけでよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	FOR(i, 0, SZ(s) - 1) {
		if (s[i] == s[i + 1]) {
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	FOR(i, 0, SZ(s) - 2) {
		if (s[i] == s[i + 2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}
