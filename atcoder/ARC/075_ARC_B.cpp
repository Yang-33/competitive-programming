#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/06/03  Problem: ARC 075 B / Link: http://arc075.contest.atcoder.jp/tasks/arc075_b  ----- */
/* ------問題------

N(≦10^5)体の敵がいてそれぞれの体力がh(i)(≦10^9)である。
あなたは魔法で直接選択した敵1体に対してA、それ以外の敵にBのダメージを与えることができ、この動作を合わせて一回の攻撃とする。
(10^9>)A>Bのとき、最小の攻撃回数で倒すには何回攻撃をすればいいか。

-----問題ここまで----- */
/* -----解説等-----

敵を選択しなくても確定でBの攻撃、一体に限ってA-Bのダメージを与えると考えれば、何回攻撃をするかを決めた際に
敵の体力を一様にBだけ削ってからA-Bの攻撃をして倒せるかを判定すればいいことになる。
また選択する前の残りの体力についてみれば何回攻撃をすればいいかわかるので、必要な攻撃回数について二分探索をすればうれしくなる。
探索は大きい回数で必ず倒せるので、(l,r]で探索し、答えについて ans = r となる。

----解説ここまで---- */

ll N,A,B;
ll h[100010];
ll a[100011];

ll ans = 0LL;



// x回で倒せるか
bool f(ll x) {
	FOR(i, 0, N)a[i] = h[i];
	ll s = x;
	FOR(i, 0, N)a[i] -= B*s;


	ll cnt = 0;;
	FOR(i, 0, N) {
		if (a[i] <= 0)continue;
		cnt += (a[i]+A-B-1) / (A - B);
	}

	if (cnt > s)return 0;
	else return 1;
	

}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>A>>B;
  FOR(i, 0, N)cin >> h[i];

  sort(h, h + N);

  ll l = 0; ll r = 1e10;
  FOR(i, 0, 150) {
	  ll mid = (r + l) / 2;
	  if (f(mid))r = mid;
	  else l = mid;
  }

//  cout << r << " " << l << endl;
  ans = r;
  cout << ans << endl;

  return 0;
}
