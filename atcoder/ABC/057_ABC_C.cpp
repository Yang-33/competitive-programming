#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const int INF = 1e9;

/* -----  2017/03/27  Problem: ABC 057 C / Link:
 * http://abc057.contest.atcoder.jp/tasks/abc057_d ----- */
/* -----  2017/03/27  Problem: ABC 057 C / Link: http://abc057.contest.atcoder.jp/tasks/abc057_d ----- */
/* ------蝠城｡---

整数 N が与えられます。
ここで、2 つの正の整数 A,B に対して、F(A,B) を「10 進表記における、A の桁数と B の桁数のうち大きい方」と定義します。
例えば、F(3,11) の値は、3 は 1 桁、11 は 2 桁であるため、F(3,11)=2 となります。
2 つの正の整数の組 (A,B) が N=A×B を満たすように動くとき、F(A,B) の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

いわれたとおりに実装する。
Nの約数を列挙し、A*Bを復元したら各数の桁について調査し、
その最大値の中から最小のものを選べばよい。

----解説ここまで---- */

ll N;

ll ans = INF;

ll sss(ll a) {
  ll cnt = 0;
  while (a > 0) {
    a /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  vector<ll> v;
  FOR(i, 1, sqrt(N) + 1) {
    if (N % i == 0) {
      v.push_back(i);
    }
  }
  FOR(i, 0, v.size()) {
    ll a = v[i];
    ll b = N / a;
    ll aa = sss(a);
    ll bb = sss(b);
    ll temp = max(aa, bb);
    ans = min(temp, ans);
  }

  cout << ans << endl;

  return 0;
}
