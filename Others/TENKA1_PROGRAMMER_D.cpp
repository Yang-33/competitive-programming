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

/* -----  2017/09/30  Problem: Tenka1_programmer D  / Link: http://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_d  ----- */
/* ------問題------

非負整数専門店「せいすうや」には、N 個の非負整数が売られています。i 個目の非負整数は Ai で、その価値は Bi です。 価値の異なる同じ非負整数が複数売られていることもあります。

高橋君は、「せいすうや」でいくつかの整数を買うことにしました。高橋君は、買う整数たちの bitwise or が K 以下になるような 任意の組み合わせで、整数を買うことができます。高橋君は、買った整数たちの価値の総和をできるだけ大きくしたいです。

高橋君が達成できる、価値の総和の最大値を求めてください。ただし、bitwise or とは、ビットごとの論理和を表します。

-----問題ここまで----- */
/* -----解説等-----

各1の立つbitを0にした際、それ以下の数でより1のbitが立っている方がうれしい。
したがってこれを全探索する。
全bitを見る必要なんかないね

----解説ここまで---- */

ll N, K;

ll ans = 0LL;
ll ansdown = 0LL;
ll up;
ll down;
string to_binString(unsigned int val) //二進数表示
{
	const int size = 30;
	int index = size - 1;
	string str(size, '0');
	while (val != 0) {
		if ((val & 1) == 0)  // val は偶数か？
			str[index] = '0';  //  偶数の場合
		else
			str[index] = '1';  //  奇数の場合
		val >>= 1, index--;
	}
	return str;
}
void print_bin(int a) {
	cout << to_binString(a) << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	int n = 1;
	while (2 * n < K)n *= 2;
	n--;
	down = n;
	up = K;
	vector<pll>p(N);
	print_bin(down);
	print_bin(up);
	FOR(i, 0, N) {
		cin >> p[i].first >> p[i].second;
	}

	FOR(i, 0, N) {//K以下の最大の11111...11
		if (down >= p[i].first) {
			ansdown += p[i].second;
		}
	}
	ans = max(ans, ansdown);
	FOR(i, 0, 31) {//downの下からみる
		ll num = 0;
		ll ret = 0;

		if (K&(i << 1) == 0)continue;
		FOR(j, 0, i) {
			num |= 1 << j;
		}
		FOR(j, i + 1, 31) {
			if (K&(1 << j))num |= 1 << j;
		}
		FOR(i, 0, N) {
			if ((num | p[i].first) <=num)ret += p[i].second;
		}

		ans = max(ans, ret);
	}

	cout << ans << endl;
	return 0;
}
