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

/* -----  2017/09/14  Problem: codeforces 417 div2 E  LINK: http://codeforces.com/contest/812/problem/E  ----- */
/* ------問題------

A,Bが根1の木のノード上にあるリンゴを使ってゲームを行う。
ノードの上にリンゴがあるものを選択し、任意の個数を以下の操作に従って移動させる
・ノードが葉ならリンゴを取り除く
・ノードに子があるならリンゴを移動させる
後手のプレイヤーはゲーム開始前にこっそり任意の2頂点を交換できる。
このときこの2頂点の選び方は何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

高さ2、根のリンゴが0のときを考えると完全にNim。
1-2のような木では根から下ってきたリンゴは葉で取り除けるので根のリンゴはNimには関係しなさそう出ることが分かる
同様に他の高さ2の木でも同じことがいえる
1-2-3のような木では葉の手前でこれが成り立っていたことが分かる
この時は3を葉とすれば1のノードを操作することに意味があるので、帰納的に1-3のように葉からの距離が偶数のノードの値がgrundy数を変えることが分かる。
したがってまずこの木のgrundy数を求め、奇数の距離のノードと、grundy(xor)EVENnode[i]==ODDnode[j]となるような数を求めればよい。
これはmap等の配列で前計算ができる。
grundy==0のときは交換したくない気持ちになるので、ノードの対を計算する。

----解説ここまで---- */

ll N;
int a[100005];
ll ans = 0LL;
vector<vector<int>>G;
int mad;
int dep[100005];

void dfs(int cur,int d) {
	mad = max(mad, d);
	dep[cur] = d;
	FOR(i, 0, G[cur].size()) {
		dfs(G[cur][i], d + 1);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	G = vector<vector<int>>(N, vector<int>());
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N - 1) {
		int c; cin >> c;
		G[c-1].pb(i+1);
	}

	dfs(0, 0); // nodeの深さを記録
	map<int, int>ma;
	int grundy = 0;
	FOR(i, 0, N) {
		if (dep[i] % 2 == mad % 2) {
			grundy ^= a[i];
		}
		else {
			ma[a[i]]++;
		}
	}

	ans = 0;
	
	if (grundy == 0) { //a[i]!=0なのでゲーム値が0なら交換可能な組を求める n(n+1)/2
		ll num[2] = {};
		FOR(i, 0, N) {
			if (dep[i] % 2 == mad % 2) ans += num[0], num[0]++;
			else ans += num[1], num[1]++;
		}
	}
	else {
		FOR(i, 0, N) {
			if (dep[i] % 2 == mad % 2) {
				ans += ma[grundy^a[i]];
			}
		}
	}


	cout << ans << endl;

	return 0;
}
