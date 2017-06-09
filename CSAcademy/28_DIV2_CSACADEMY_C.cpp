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

/* -----  2017/06/09  Problem: CSAcadeny 28 C / Link:  https://csacademy.com/contest/round-28/ ----- */
/* ------問題------

カード{1,2,3,...,N}がある。以下のシャッフルをK回行い最後の状態を出力せよ。

A shuffle consists of:
Bring the cards at odd positions on top of the deck, in order.
Place the first card on the table. On top of it, place the last card. Then take the first card in the remaining deck and place on top of the cards on the table, then the last one, and so on.
The cards on the table form the new deck.

-----問題ここまで----- */
/* -----解説等-----

奇数の位置にあるカードを上に持ってくる。
その後上のカード、下のカード、を順に下に積んでいく。
愚直にやると絶対に間に合わないが、何度も繰り返すとこれは同じ動きを繰り返すことが偶奇にわけて証明できる。
実際には4回やればいいので4回だけ移動させる。

----解説ここまで---- */

ll N,K;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>K;
  int a[100010];
  int b[100010];
  FOR(i, 0, N) {
	  a[i] = i + 1;
  }
  int k = 0;
  for (;;) {
	  FOR(i, 0, N) {
		  if (i % 2 == 0)b[(i) / 2] = a[i];
		  else b[(N+1)/2+i/2] = a[i];
	  }
	  FOR(i, 0, N) {
		  a[i] = b[i];
	  }


	  int r = N - 1;
	  int l = 0;
	  FOR(i, 0, N) {
		  if (i % 2 == 0) {
			  b[N - 1 - i] = a[l];
			  l++;
		  }
		  else {
			  b[N - 1 - i] = a[r];
			  r--;
		  }
	  }
	  FOR(i, 0, N) {
		  a[i] = b[i];
	  }
	  k++;
	  if(K%4==k)
	  break;
	  if (k == 4)break;
  }
  FOR(i, 0, N) {
	  cout << a[i];
	  if (i != N - 1)cout << " ";
  }
  cout << endl;

  return 0;
}
