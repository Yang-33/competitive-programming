#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/05/02  Problem: yukicoder 136  / Link: http://yukicoder.me/problems/no/136  ----- */
/* ------問題------

正整数の配列Aに対して、Aの総和がちょうどxであるとき、Aをxの分割であると呼ぶ。

整数の配列Aに対して、gcd(A)=gcd(A1,A2,…,A|A|)と定義する。

整数N,Kが与えられる。2≤|A|≤KとなるNの分割Aに対し、gcd(A)を最大化せよ。

-----問題ここまで----- */
/* -----解説等-----

2<S回で最大値が出たとする。ある要素をまとめていってもgcdは変化しないため、最終的に2つに分割でも答えは一緒であることがわかる。
したがって分割2回を試せば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	int ans = 0LL;
	FORR(i, N / 2, 1-1) {
		ans = max(ans,__gcd(i,N-i));
	}
	cout << ans << "\n";

	return 0;
}
