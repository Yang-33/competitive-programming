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

/* -----  2018/02/14  Problem: 065_arc_a / Link: https://arc065.contest.atcoder.jp/tasks/arc065_a?lang=en  ----- */
/* ------問題------

英小文字からなる文字列 S が与えられます。 Tが空文字列である状態から始め、以下の操作を好きな回数繰り返すことで S=T とすることができるか判定してください。

T の末尾に dream dreamer erase eraser のいずれかを追加する。

-----問題ここまで----- */
/* -----解説等-----

ケツから見たときのsubstrはindexが危険なので、反転するといい感じになった

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;
	reverse(ALL(S));
	string t[4] = { "dream","erase","eraser","dreamer" };
	FOR(i, 0, 4)reverse(ALL(t[i]));
	FOR(i, 0, SZ(S)) {
		if (S.substr(i, 5) == t[0] || S.substr(i, 5) == t[1]) {
			i += 4;
		}
		else if (S.substr(i, 6) == t[2]) {
			i += 5;
		}
		else if (S.substr(i, 7) == t[3]) {
			i += 6;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout <<"YES" << "\n";

	return 0;
}
