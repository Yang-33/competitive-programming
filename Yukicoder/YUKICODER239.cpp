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

/* -----  2018/08/25  Problem: yukicoder 239  / Link: http://yukicoder.me/problems/no/239  ----- */
/* ------問題------

宮内れんげ(通称れんちょん)はいついかなる時も「nyanpass」と挨拶するという。
転じて、いついかなる時も「nyanpass」と挨拶する人を「れんちょんっぽい」と言う。

村には村民が N 人いて、1～N までの村民番号が振られている。
N人の挨拶履歴が N×N の行列 A で与えられる。Aij は村民番号 i 番と j 番が挨拶したときの j 番の発言を表す。

N人の中にれんちょんっぽい人物がただ1人だけいる時、これをれんちょんを「特定」できたと言う。
れんちょんを特定できた場合はその村民番号を、特定出来なかった場合は-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

[昔の提出かわいい](https://yukicoder.me/submissions/70450)


----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<VS> vs(N, VS(N));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> vs[i][j];
		}
	}
	int id = -1;
	int cnt = 0;
	FOR(i, 0, N) {
		int ok = 1;
		FOR(j, 0, N) {
			if (i == j)continue;
			ok &= vs[j][i] == "nyanpass";
		}
		if (ok)cnt++, id = i + 1;

	}
	int ans = cnt == 1 ? id : -1;
	cout << ans << "\n";

	return 0;
}
