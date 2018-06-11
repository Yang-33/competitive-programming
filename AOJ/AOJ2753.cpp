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

/* -----  2018/06/10  Problem: AOJ 2753 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2753  ----- */
/* ------問題------

R 大学情報理工学部 1 回生の学生 n 人が， プログラミング演習 1 という講義の期末試験を受験する． 試験は m 点満点である．つまり，1 人の学生の取りうる点数は 0 以上 m 以下の整数である．

担当の先生は意地が悪いので，平均値と中央値の差が最大になるような点数分布が気になっている．そのような点数の取り方を 1 つ出力せよ．

注 : 平均値とは点数の和を n で割ったものであり，中央値とは点数を昇順に並べたとき，n が奇数なら前から (n+1)/2 番目 (1 − indexed) の点数， 偶数なら前から n/2 番目と n/2+1 番目の点数を足して 2 で割った点数である．

-----問題ここまで----- */
/* -----解説等-----

0とmでつくる。中央値を0側に寄せれば良い

----解説ここまで---- */
using ll = LL;
void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> ans;
	if (n % 2) {
		for (int i = 0; i < n / 2; i++) ans.push_back(0);
		for (int i = n / 2; i < n; i++) ans.push_back(m);
	}
	else {
		double dif1, dif2;
		dif1 = m * (n / 2 - 1) / (double)n;
		dif2 = m * (n / 2) / (double)(n);
		dif2 = abs(dif2 - m / 2.);
		if (dif1 > dif2) {
			for (int i = 0; i <= n / 2; i++)ans.push_back(0);
			for (int i = n / 2 + 1; i < n; i++) ans.push_back(m);
		}
		else {
			for (int i = 0; i < n / 2; i++)ans.push_back(0);
			for (int i = n / 2; i < n; i++) ans.push_back(m);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i != n - 1)cout << " ";
		else cout << endl;
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	//cout << solve() << endl;
	return 0;
}