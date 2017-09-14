#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/09/14  Problem: yukicoder361  / Link: https://yukicoder.me/problems/no/361  ----- */
/* ------問題------

kado くんと matsu くんが竹を分割して門松を作るゲームをします。
ゲームは次のようにして行われます。
最初、場には長さLの竹が1本ある。
手番の者が場から竹を1本選び、門松が作れるように竹を3つに分割する。 選ばれた竹は場から除かれ、分割後の3本の竹が場に追加される。
このとき分割前の竹の長さをL、分割後の竹の長さをL1,L2,L3とすると、
L1+L2+L3=L
L1≠L2,L2≠L3,L3≠L1
L1,L2,L3は正の整数
max(L1,L2,L3)−min(L1,L2,L3)≤Dを全て満たさなければならない。
分割したら、手番を交代する。 条件を満たすように竹を分割できなければ、手番の者が負けである。
負けなかった者の勝ちである。
先手はkadoくん、後手はmatsuくんです。
二人が最善を尽くしてゲームを進めた場合、どちらが勝つことになるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

各盤面の直和についてのgrundy数をxorすればいいので、各丈の長さについてgrundy数を求めればよい。
L^3logLぐらいかな？

----解説ここまで---- */

int L, D;
int memo[502];

int grundy(int a) {
	if (memo[a] != -1)return memo[a];
	set<int>s;
	FOR(i, 1, a) {
		FOR(j, i + 1, a) {
			ll k = a - (i + j);
			if (k < 1)continue;
			if (i == k || j == k)continue;
			ll M = max({ i,j,k });
			ll m = min({i,j,k});
			if (M - m <= D) {
				s.insert(grundy(i) ^ grundy(j) ^ grundy(k));
			}
		}
	}
	int ret = 0;
	while (s.count(ret))ret++;
	return memo[a] = ret;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> L>>D;
	FOR(i, 0, 502)memo[i] = -1;
	cout << ((grundy(L)!=0)?"kado":"matsu") << endl;

	return 0;
}
