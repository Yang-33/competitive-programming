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

/* -----  2017/07/09  Problem: AGC 017 B / Link: http://agc017.contest.atcoder.jp/tasks/agc017_b  ----- */
/* ------問題------

N 個のマスが一列に並んでいます． 一番左のマスには整数 A が，一番右のマスには整数 B が書かれており，他のマスには何も書かれていません．

青橋君は，何も書かれていないマスに整数を書き込み，次の条件を満たすようにしたいです：

どの隣接する 2 マスについても，書かれている整数の差は C 以上 D 以下である．
青橋君は，この条件を満たす限り，いくらでも大きい整数や小さい整数を書き込むことができます．
青橋君が条件を満たすように整数を書き込むことができるかを判定してください．

-----問題ここまで----- */
/* -----解説等-----

制約が大きいので数を記録するのは困るなあという気持ちになる。
しかし、作った値の範囲についてかんがえれば、i回目での作成した値の上限から加減は全て連続している。
N回目について考えれば、[0,N)のうちのiを選択し値の変更の上限はDをi回足したものからCをN-i回引いたものになる。
したがってこれの中にBがあるかを判定すればよい。

----解説ここまで---- */

ll N,A,B,C,D;


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>A>>B>>C>>D;
  bool f = 0;

  FOR(i, 0, N - 1) {
	 ll u = A + (N - 1 - i)*D - C*i;
	  ll d = A + (N - 1 - i)*C - D*i;
	  if (u >= B&&d <= B)f = 1;
  }
  FOR(i, 0, N - 1) {
	  ll u = A  -(N - 1 - i)*C + D*i;
	  ll d = A  -(N - 1 - i)*D + C*i;
	  if (u >= B&&d <= B)f = 1;
  }
  

  if(f)
	  cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
