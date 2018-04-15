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

/* -----  2018/04/15  Problem: yukicoder 065  / Link: http://yukicoder.me/problems/no/065  ----- */
/* ------問題------

1個のサイコロを何回か振って目の合計をK以上にしたい。
サイコロを振る回数の期待値を求めよ。

なお、今回のサイコロの場合に回数の期待値(E(x)の公式は以下であることが知られている
E(x) := これまでの目の合計が x のとき、合計が K に達するまでにあと振ることになる回数の期待値
E(x)=E(x+1)∗1/6+E(x+2)∗1/6+E(x+3)∗1/6+E(x+4)∗1/6+E(x+5)∗1/6+E(x+6)∗1/6+1

-----問題ここまで----- */
/* -----解説等-----

よくわからないけどそのまま書きます。  
[漸化式の説明](http://garnacha.techblog.jp/archives/39168955.html)

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K; cin >> K;
	vector<double>E(21, 0);
	FORR(i, K-1, 0 - 1) {
		double ret = 0;
		FOR(j, i + 1, i + 6 + 1) {
			ret += E[j];
		}
		E[i] = 1 + (ret) / 6.0;
	}

	double ans = E[0];
	cout <<fixed<<setprecision(5)<< ans << "\n";

	return 0;
}
