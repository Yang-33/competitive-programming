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

/* -----  2017/12/10  Problem: ARC 086 B / Link: http://arc086.contest.atcoder.jp/tasks/arc086_b  ----- */
/* ------問題------

すぬけ君は長さN の数列a を持っています。
a の (1-indexedでの)i 番目の数はai です。

すぬけ君は以下の操作を何度でも行うことができます。
操作：1 以上N 以下の整数x,y を選び、ay にax を加算する。
すぬけ君はこの操作を0 回以上2N 回以下行ってa が下記の条件を満たすようにしたいです。そのような操作手順の一例を示してください。 なお、この問題の制約下で、条件を満たすような操作の手順が必ず存在することが証明できます。
条件：単調増加列

-----問題ここまで----- */
/* -----解説等-----

まず値の正負が一致すれば嬉しいなあという気持ちになる。
どちらかに揃えるため、絶対値が大きな値がどちらにあるかを探す。
先に大きな値を作って、これを2倍しながら、小さい方に加算していけば良い。
2N回あれば必ずできる。
思いつくのにとてもじかんがかかった。

累積和の解法は賢いなあと思うなど。
こちらはならしてから順に足していけば良い。

----解説ここまで---- */

LL N, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<LL>v(N);
	L = 0;
	R = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		L = min(L, v[i]);
		R = max(R, v[i]);
	}
	vector<pair<int, int>>ans;
	if (abs(R) > abs(L)) {
		int index = 0;
		for (int i = 1; i < N; i++) {// +
			if (v[i] > v[index]) {
				index = i;// + max
			}
		}
		ans.push_back({ index,N - 1 });
		ans.push_back({ index,N - 1 });
		ans.push_back({ index,N - 1 });
		for (int i = 1; i < N - 1; i++) {
			ans.push_back({ N - 1,N - 1 });
			ans.push_back({ N - 1,i });
		}
		ans.push_back({ N - 1,N - 1 });
	}
	else {
		int index = 0;
		for (int i = 1; i < N; i++) {
			if (v[i] < v[index]) {
				index = i;
			}
		}
		ans.push_back({ index,0 });
		ans.push_back({ index,0 });
		ans.push_back({ index,0 });
		for (int i = N - 2; i >= 1; i--) {
			ans.push_back({ 0,0 });
			ans.push_back({ 0,i });
		}
		ans.push_back({ 0,0 });
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << endl;
	}
	return 0;
}