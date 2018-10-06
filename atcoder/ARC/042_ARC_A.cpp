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

/* -----  2018/10/06  Problem: ARC 042 A / Link: http://arc042.contest.atcoder.jp/tasks/arc042_a  ----- */
/* ------問題------

1 から N までの番号がついたスレッドのある掲示板があります。 スレッドは書き込みがあると一番上に来ます。 書き込み前のスレッドは上から順に 1 から N の順に並んでいました。 M 個の書き込みが書き込まれた順で与えられるので、全ての書き込みが終わった後のスレッドの順番を出力してください。
例えば、3 個のスレッドがある掲示板に 2、3、1 の順で書き込みがあると、以下のようになります。
従って、書き込み後のスレッドの順番は 1、3、2 となります。

-----問題ここまで----- */
/* -----解説等-----

後ろからやっていけば良くて、書き込みが無かったものは昇順にやっていけばよい

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VI a(M);
	VI b(N, 0);
	FOR(i, 0, M) {
		cin >> a[i];
		a[i]--;
	}

	reverse(ALL(a));
	FOR(i, 0, M) {
		if (!b[a[i]])
			cout << a[i] + 1 << endl;
		b[a[i]] = 1;
	}
	FOR(i, 0, N) {
		if (!b[i]) {
			cout << i + 1 << endl;
		}
	}

	return 0;
}