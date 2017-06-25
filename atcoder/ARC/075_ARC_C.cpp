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

/* -----  2017/06/03  Problem: ARC 075 C / Link: http://arc075.contest.atcoder.jp/tasks/arc075_c  ----- */
/* ------問題------

長さ N の整数列 a= {a1,a2,…,aN} と、整数 K が与えられます。

a の空でない連続する部分列 {al,al+1,…,ar} (1≤l≤r≤N) は N(N+1)⁄2 個存在します。これらのうち、算術平均が K 以上であるものは何個あるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

数列の各項からKを引くとこの問題は部分列の総和が0以上になる区間の数を求めるという問題になる。
さらに、部分列は累積和をもつことで管理できる。
これをsum[i]としたときに区間[L,R]をみると、sum(R)-sum(L)≧0を求めることになる。
これはさらにsum(R)≧sum(L)となる区間を見つけると言い換えることができる。
区間のある一定以上の値を見つける際には範囲クエリとみなすことができ、セグ木なりBITでこれを線形時間ではなく対数時間で求めることができる。
BITはお借りしました。
値が大きすぎるので座標圧縮をして、出てきた数字を区間上で1加算する。
その後自分より小さい値の数の総和を求め、答えに加算すればいい。

----解説ここまで---- */

ll N,K;
ll a[200010];
ll ans = 0LL;
ll sum[200010];

template<class V, int ME> class BIT {
public:
	V bit[1 << ME], val[1 << ME];
	V total(int e) { V s = 0; e++; while (e) s += bit[e - 1], e -= e&-e; return s; }
	V add(int e, V v) { val[e++] += v; while (e <= 1 << ME) bit[e - 1] += v, e += e&-e; }
	V set(int e, V v) { add(e, v - val[e]); }
	int lower_bound(V val) {
		V tv = 0; int i, ent = 0;
		for (i = ME - 1; i >= 0; i--) if (tv + bit[ent + (1 << i) - 1]<val) tv += bit[ent + (1 << i) - 1], ent += (1 << i);
		return ent;
	}
};


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>K;
  FOR(i, 0, N)cin >> a[i];
  FOR(i, 0, N)a[i] -= K;
  
  vector < ll >v;
  v.push_back(-1LL<<60);
  v.push_back(0);
  FOR(i, 1, N + 1) {
	  sum[i] += sum[i - 1] + a[i-1];
	  v.push_back(sum[i]);
  }
  sort(v.begin(), v.end());
  
  
  int added = 0;
  BIT<int, 20>bit;
  for (int i = N - 1; i >= 0; i--) {
	  int x = lower_bound(v.begin(), v.end(), sum[i + 1]) - v.begin();
	  added++;
	  bit.add(x, 1);
	  int y = lower_bound(v.begin(), v.end(), sum[i]) - v.begin();
	  ans += added - bit.total(y - 1);
  }

  cout << ans << endl;

  return 0;
}
