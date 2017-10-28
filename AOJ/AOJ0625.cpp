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

/* -----  2017/10/29  Problem:  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0625  ----- */
/* ------問題------

オレンジの出荷(Oranges)
あなたはJuicy Orange Industry 社を知っているだろうか? この会社の業務は美味しいオレンジを栽培して出荷することである．ここでは略してJOI 社と呼ぶ．
JOI 社では，収穫された N 個のオレンジを箱詰めして出荷することになった．オレンジは工場にあるベルトコンベアの上に並べられており，ベルトコンベアの前から順番に 
1 から N までの番号が付けられている．オレンジは大小さまざまであり，オレンジ (1≤i≤N) の大きさは Ai である．
これらのオレンジを前から順番にいくつかの箱に分けて詰める．ひとつの箱には連続した番号のオレンジしか詰めることができない．
ひとつの箱には最大で M 個までのオレンジを詰めることができる．ある箱にいくつかのオレンジを詰めるためにかかるコストは，箱に詰める最大のオレンジの大きさを 
a，箱に詰める最小のオレンジの大きさを b，箱に詰めるオレンジの個数をs としたときに，K+s×(a−b) で求めることができる．
ここで，K は箱にかかるコストであり，すべての箱で共通の値である．
適切な個数の箱を用意して，すべてのオレンジを適切に箱詰めすることで，箱詰めにかかるコストの総和をできるだけ小さくしたい．
課題
ベルトコンベア上に並んでいるオレンジの情報と，ひとつの箱に詰められるオレンジの個数の最大値および，箱にかかるコストが与えられたとき，箱詰めにかかるコストの総和の最小値を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

dp[s] := s個入れ終えたときの最小値
でdp。添え字に注意？

----解説ここまで---- */

ll N,M,K;
ll a[20010];
ll dp[20010];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>M>>K;
  FOR(i, 1, N+1)cin >> a[i];
  FOR(i, 0, 20010)dp[i] = LINF;
  dp[0] = 0;
  FOR(i, 1, N+1) {
	  ll mn = LINF; ll mx = -LINF;
	  FOR(j, 0, M) {//詰めた状態が最適になればよい
		  if (i + j > N)break;
		  mn = min(mn, a[j + i]);
		  mx = max(mx, a[i + j]);
		  dp[i + j] = min(dp[i + j], dp[i-1] + K + (j + 1)*(mx - mn));
	  }
  }

  ans = dp[N];
  cout << ans << endl;

  return 0;
}
