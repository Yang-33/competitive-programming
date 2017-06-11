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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/06/10  Problem: ARC 071 B / Link: http://arc071.contest.atcoder.jp/tasks/arc071_b  ----- */
/* ------問題------

2 次元平面上に x 軸と平行な直線が m 本と y 軸と平行な直線が n 本引いてあります。 
x 軸と平行な直線のうち下から i 番目は y=yi で表せます。 y 軸と平行な直線のうち左から i 番目は x=xi で表せます。

この中に存在しているすべての長方形についてその面積を求め、 合計を 109+7 で割ったあまりを出力してください。

つまり、1≤i<j≤n と 1≤k<l≤m を満たすすべての組 (i,j,k,l) について、 直線 x=xi, x=xj, y=yk, y=yl で囲まれる 長方形の面積を求め、
合計を 109+7 で割ったあまりを出力してください。

-----問題ここまで----- */
/* -----解説等-----

(問題) = Σ[1≦i,j≦W][1≦k,l≦H](Xj-Xj)(Yl-Yk) である。

Σ[1≦i,j≦W](Xj-Xj) * Σ[1≦k,l≦H](Yl-Yk)
の式を眺めていると左右独立に求められそうという気持ちになってくる。
また、Σ[1≦i,j≦W](Xj-Xj) についてXiの登場回数を求められそうであることに気が付く。
そこで変形してみると、
Σ[1≦i,j≦W](Xj-Xj) = Σ[1≦s≦W]( Xs(s-1) - Xs(W-s) )
と変形できる。これはXsが加算される回数と減算される回数がΣ[1≦i,j≦W]という制約からできるからである。
したがってΣの中をＯ(H)で求められるようになり、この積をかければいいことになる。

本番で解けなかった。

----解説ここまで---- */



ll W,H;
ll x[100010];
ll y[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W>>H;
	FOR(i, 1, W+1)cin >> x[i];
	FOR(i, 1, H+1)cin >> y[i];

	ll Xsum = 0;
	FOR(i, 1, W + 1) {
		Xsum += x[i] * ((i - 1) - (W - i))%MOD;
	}
	ll Ysum = 0;
	FOR(i, 1, H + 1) {
		Ysum += y[i] * ((i - 1) - (H - i))%MOD;
	}

	ans = (Xsum*Ysum)%MOD;

	cout << ans << endl;
	
	return 0;
}
