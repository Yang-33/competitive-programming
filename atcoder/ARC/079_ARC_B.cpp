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

/* -----  2017/07/29  Problem: ARC 079 B / Link: http://arc079.contest.atcoder.jp/tasks/arc079_b  ----- */
/* ------問題------

長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。
数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。
ここで、整数 K が与えられるので、この操作を行う回数がちょうど K 回になるような数列 ai を 1 つ求めてください。
なお、この問題の入出力の制約下では、かならず 1 つは条件を満たすような数列が存在することが示せます。

-----問題ここまで----- */
/* -----解説等-----

A(i)について選択する回数をP(i)とすると、N>A(i)-P(i)*N+(K-P(i))>=0でなくてはならない。
これを整理するとA(i)は
P(i)*(N+1)-K <= A(i) < P(i)*(N+1)-K+N　を満たす。
これはNを固定ればP(i)を定めることができる。
P(i)の中でも上の方の値をとれば安心。（証明して）
あとは制約に従うように値を出力すればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
		ll K;
		cin >> K;
		N = 50;
		ll lef = K%N;
		ll div = K / N;

		assert(lef + div*N == K);

		cout << N << endl;
		FOR(i, 0, N) {
			ans = div;
			if (i <lef)ans +=1;
			ll sita = ans*(N + 1) - K;
			ll ue = ans*(N + 1) - K + N;
			ll x = sita;
			ll shi = 1;// ue - sita;
			while (shi * 2 < ue - sita)shi *= 2; shi *= 2;
			while (1) {
				if (shi == 0)break;
				if (x + shi < ue/*&&(x+shi<=(1e16+1000))*/) {
					x += shi;
				}
				shi /= 2;
			}
			assert(x >= 0 && x <= (1e16 + 1000));
			cout << x << " ";
		}
		cout << endl;
	return 0;
}
