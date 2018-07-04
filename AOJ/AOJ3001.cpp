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

/* -----  2018/07/05  Problem: AOJ 3001 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3001  ----- */
/* ------問題------

GPAとは「Galaxy Point of Aizu」の略で、0から4までの実数値を取る。
GPAじゃんけんは二人で行うゲームである。各々が「じゃんけん、ぽん（ほい）」の合図で互いにグー、チョキ、パーのどれか好きな手を出した後、GPAが高い人が勝者となり、低い人が敗者となる。同じ場合は引き分けとなる。

N 人のGPAのデータが与えられるので、総当たり戦をした時のそれぞれの勝ち点を出力せよ。
ただし、勝ち点は勝ちの時3、引き分けの時1、負けの時0とする。

総当たり戦とはすべての参加者が自分以外の参加者と丁度一回ずつ対戦する方式である。

-----問題ここまで----- */
/* -----解説等-----

そう…

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<float, int>> a;
	vector<pair<int, int>> result(n);
	for (int i = 0; i < n; ++i) {
		pair<float, int> tmp;
		cin >> tmp.first;
		tmp.second = i;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		auto l = lower_bound(a.begin(), a.end(), pair<float, int>(a[i].first, -1)) - a.begin();
		auto r = upper_bound(a.begin(), a.end(), pair<float, int>(a[i].first, INF)) - a.begin();

		result[i].second = l * 3 + (r - l - 1) * 1;
		result[i].first = a[i].second;
	}
	sort(result.begin(), result.end());
	for (auto i : result) {
		cout << i.second << endl;
	}

	return 0;
}