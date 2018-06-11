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

/* -----  2018/06/10  Problem: AOJ ALDS1_6_D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_D  ----- */
/* ------問題------

重さ wi(i=0,1,...,n−1) の n 個の荷物が１列に並んでいます。
これらの荷物をロボットアームを用いて並べ替えます。
１度の操作でロボットアームは荷物 i と荷物 j を持ち上げ、それらの位置を交換することができますが、
wi+wj のコストがかかります。ロボットアームは何度でも操作することができます。
与えられた荷物の列を重さの昇順に整列するコストの総和の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

噂になっていたので解いた。
交換すべきgroupのサイズについて考える。1,2のときは交換の選択肢は1つしか無い。
一方3つ以上のときは、順序によってコストが変化する。起点を考える。
起点はgroup内での最小または、全体の最小のどちらかである。(クソでかいgroupは1とかを使ったほうが良い)
group内では、sum[w] + min([w])*(SZ([w])-2),
全体では,sum[w]+ min([w])*(SZ([w])-2)
+ 2*(min([w])+globalmin(W)) 
- (SZ([w])-2)+1)*(min([w])-grobalmin(W))
= sum[w] + min([w])+(SZ([w])+1)*grobalmin(W)
となる。どっちか小さい方を選択すれば良い。

これ時間かかったけど良い問題かも…

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL w(N);
	FOR(i, 0, N) {
		cin >> w[i];
	}
	int grobalMin = *min_element(ALL(w));
	VL a = w;
	SORT(a);
	VI groupNext(1e4 + 1, 0);
	VI visit(N, 0);
	FOR(i, 0, N) {
		groupNext[a[i]] = i;
	}
	FOR(i, 0, N) {
		if (visit[i])continue;
		int index = i;
		LL wSum = 0;
		LL groupMin = INF;
		int wSize = 0;
		while (!visit[index]) {
			wSize++;
			visit[index] = 1;

			groupMin = min(groupMin, w[index]);
			wSum += w[index];

			index = groupNext[w[index]];
		}
		ans += min(wSum + (wSize - 2)*groupMin, 
				   groupMin + wSum + (wSize + 1)*grobalMin);
	}
	cout << ans << "\n";

	return 0;
}
