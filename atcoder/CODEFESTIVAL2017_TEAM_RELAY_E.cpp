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

/* -----  2017/12/04  Problem: codefestival2017_team_relay E / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_e  ----- */
/* ------問題------

りんご王国議会で、ある法案の採決が行われています。
N 人の議員が出席しており、i 人目の議員 (1≤i≤N) は wi 枚の白票と bi 枚の青票を持っています。それぞれの議員 i は、法案に賛成であれば持っている wi 枚の白票すべてを投票箱に入れ、法案に反対であれば持っている bi 枚の青票すべてを投票箱に入れます。これら以外の行為は認められていません。例えば、議員は投票を放棄したり、持っている白票の一部または青票の一部のみを投票箱に入れてはなりません。
すべての議員の投票後に、投票箱に入っている票のうち P パーセント以上が白票であれば法案が可決され、白票が P パーセント未満であれば否決されます。
法案が可決されるためには、少なくとも何人の議員の賛成が必要でしょうか？

-----問題ここまで----- */
/* -----解説等-----

simga b(i) in S / (sigma b(i) in S + sigma w(i) in ~S ) >= P /100
が求める式である。
S + ~S = ALL であるから、これを利用することで以下の式に変形できる。
sigma (100 - P) * w(i) + P * b(i)  in S >= P * (ALL(b))
この式を満たすような最小の集合Sを求めればいいので、これは貪欲でよい。

こういう数式を普段書いていないので良くない…ちゃんと書こう！

----解説ここまで---- */


LL N, P;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> P;
	VL w(N, 0);
	VL b(N, 0);
	LL bsum = 0;
	FOR(i, 0, N) {
		cin >> w[i] >> b[i];
		bsum += b[i];
	}

	VL a(N, 0);
	FOR(i, 0, N) {
		a[i] = (100 - P)*w[i] + P*b[i];
	}
	RSORT(a);
	LL ret = 0; int id = 0;
	while (ret < P*bsum) {
		ret += a[id];
		id++;
	}

	ans = id;

	cout << ans << "\n";

	return 0;
}
