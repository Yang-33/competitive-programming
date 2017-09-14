#include "bits/stdc++.h"
#include<unordered_set>
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

/* -----  2017/09/14  Problem: yukicoder153  / Link: https://yukicoder.me/problems/no/153  ----- */
/* ------問題------

石の山が一つある。これを分割可能であれば2つか3つに分割する。
このとき最適な動きをした際に最後に動かせなくなったプレイヤーの負けである。
勝つプレイヤーはどちらか。

-----問題ここまで----- */
/* -----解説等-----

grundy数を愚直に出す+メモ化。
setでも変わらず全然間に合いそう。(unordered_setの響きが好き/mapでもよい)

----解説ここまで---- */

ll N;
int g[102];
int grundy(ll x) {
	if (g[x] != -1)return g[x];
	
	unordered_set<int>s;
	s.insert(grundy(x / 2) ^ grundy((x + 1) / 2));
	s.insert(grundy(x / 3) ^ grundy((x + 1) / 3) ^ grundy((x + 2) / 3));
	
	int id = 0;
	while (s.count(id))id++;
	
	return g[x] = id;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, 102)g[i] = -1;
	g[0] = g[1] = 0;
	g[2] = 1;
	cout << ((grundy(N) != 0) ? "A" : "B") << endl;

	return 0;
}
