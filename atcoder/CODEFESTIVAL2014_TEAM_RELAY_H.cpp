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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/19  Problem: codefestival2014_team_relay H / Link: __CONTEST_URL__  ----- */
/* ------問題------

サーバー管理者であるあなたは、サーバーへのアクセス時間をすべて記録しています。
今、サーバーへの負荷を調べるため、ある整数 n が与えられたとき、連続した n 秒間で行われたアクセス数の最大値を調べようと思いました。
そこで、m 個のアクセス時間のログが与えられるので、連続した n 秒間に行われたアクセス数の最大値を求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

つまり、無限に広い区間について、閉区間[a[i]-N,a[i]]の和がわかれば良い。
常にa[i]を加算しながら、列の先頭がa[i]-Nより小さいものを弾いていけばよく、これはqueueやしゃくとり法を用いればO(M)でできる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(M);
	FOR(i, 0, M) {
		cin >> a[i];
	}

	LL ans = 0;
	queue<LL>que;
	LL sum = 0;
	FOR(i, 0, M) {
		while (que.size() && que.front() < a[i] - N) {
			sum--;
			que.pop();
		}
		sum++;
		ans = max(ans, sum);
		que.push(a[i]);
	}
	cout << ans << endl;

	return 0;
}