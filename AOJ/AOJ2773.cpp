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

/* -----  2018/06/10  Problem: AOJ 2773 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2773  ----- */
/* ------問題------

H大学の教授を務めているPeriod博士は、万物に潜むとされる周期と呼ばれる性質を研究している。一般的に知られている基本的な周期としては、数列に潜む周期が考えられるだろう。すなわち、長さNの数列S=S1,S2, ... ,SNが以下の性質を満たすならば、周期t (t≤N) を持つという事実である。
1≤i≤N−tについて、Si=Si+tである。
今、Period博士が着目しているのは、周期を用いてより簡易な記述ができる数列である。例えば、長さNの数列が周期t (≤N) を持つとき、ある整数kを用いてN=ktと書けるならば、その数列は長さtの数列S1, ... ,Stがk個連続したものである、と記述できる。Period博士は数列を例のように記述できたとき、その数列はk-partであると言うことにした。
Period博士は、kが最も大きいk-partに興味を示している。そこで助手であるあなたは、入力として数列を受け取り、それがk-partであるとき最も大きいkを出力するプログラムの作成を任されることとなった。Period博士の要求に正確に応えるプログラムを作成しよう。

-----問題ここまで----- */
/* -----解説等-----

約数の個数を考えると、O(N√N)未満で解ける。

----解説ここまで---- */

using ll = LL;
void solve() {
	ll N; cin >> N;
	vector<ll> S(N);
	for (auto& in : S) cin >> in;

	ll res = 1;
	for (ll t = 1; t <= N; t++) {
		if (N%t != 0) continue;
		bool f = false;
		for (ll i = 0; i < N - t; i++) {
			if (S[i] == S[i + t]) continue;
			f = true;
			break;
		}
		if (f) continue;
		res = N / t;
		break;
	}
	cout << res << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}