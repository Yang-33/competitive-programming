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

/* -----  2018/02/14  Problem: 058_arc_a / Link: https://arc058.contest.atcoder.jp/tasks/arc058_a?lang=en ----- */
/* ------問題------

いろはちゃんはこだわりもので、嫌いな数字が K 個あり、それぞれ D1,D2,…,DK です。
いろはちゃんはお店でお買い物をしていて、 N 円の品物を買おうとしています。
もちろん、この品物は N 円以上のお金を支払えば買うことができます。
しかし、先ほど述べたようにいろはちゃんは強いこだわりがあるので、
自分がお店に支払う金額の 10 進表記にいろはちゃんの嫌いな数字が出現しないような最も少ない金額を支払おうとします。
いろはちゃんが支払う金額を求めてください。

-----問題ここまで----- */
/* -----解説等-----

N<=10^6なので適当に確認しても間に合う。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VI a(10, 1);
	FOR(i, 0, K) {
		int v; cin >> v;
		a[v] = 0;
	}

	ans = N;
	while (true)
	{

		int ok = 1;
		set<int>se;
		LL ret = N;
		while (ret) {
			se.insert(ret % 10);
			ret /= 10;
		}
		FOR(i, 0, 10) {
			if (a[i]==0&&se.count(i))ok = 0;
		}
		if (ok) {
			cout << N << endl; return 0;
		}
		N++;
	}

	return 0;
}
