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

/* -----  2018/02/23  Problem: 085_abc_d / Link: https://abc085.contest.atcoder.jp/tasks/abc085_d?lang=en  ----- */
/* ------問題------

あなたが散歩していると、突然一体の魔物が出現しました。幸い、あなたは N 本の刀、刀 1、刀 2、…、刀 N を持っていて、次の二種類の攻撃を自由な順番で行うことができます。
持っている刀のうち一本を振る。刀 i (1≤i≤N) を振ると、魔物は ai ポイントのダメージを受ける。同じ刀を何度振ることもできる。
持っている刀のうち一本を投げつける。刀 i (1≤i≤N) を投げつけると、魔物は bi ポイントのダメージを受け、あなたはその刀を失う。すなわち、あなたは以後その刀を振ることも投げつけることもできなくなる。
魔物は、受けたダメージの合計が H ポイント以上になると消滅します。魔物を消滅させるには、最小で合計何回の攻撃が必要でしょうか。

-----問題ここまで----- */
/* -----解説等-----

刀の使用は順序を必要としないので、これは貪欲に強いものを使用していけば良い。
Aは最大値のみ、Bはこれを比較していけばいいので降順にみていけばよい。

----解説ここまで---- */

LL N,H;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>H;
	VL a(N), b(N);
	priority_queue<LL>pqa;
	priority_queue<LL>pqb;

	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		pqa.push(a[i]);
		pqb.push(b[i]);
	}

	while (true){

		LL A = pqa.top();
		if (pqb.empty()) {
			ans += (H + A - 1) / A;
			break;
		}
		LL B = pqb.top();
		if (A >= B) {
			ans += (H+A-1) / A;
			break;
		}
		else {
			ans++;
			H -= B; if (H <= 0)break;
			pqb.pop();
		}
	}

	cout << ans << "\n";

	return 0;
}
