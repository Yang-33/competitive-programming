#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/03/03  Problem: tenka1-procon-2017_d / Link: https://tenka1-2017-beginner.contest.atcoder.jp/tasks/tenka1_2017_d?lang=en  ----- */
/* ------問題------

非負整数専門店「せいすうや」には、N 個の非負整数が売られています。i 個目の非負整数は Ai で、その価値は Bi です。 価値の異なる同じ非負整数が複数売られていることもあります。
高橋君は、「せいすうや」でいくつかの整数を買うことにしました。高橋君は、買う整数たちの bitwise or が K 以下になるような 任意の組み合わせで、整数を買うことができます。高橋君は、買った整数たちの価値の総和をできるだけ大きくしたいです。
高橋君が達成できる、価値の総和の最大値を求めてください。ただし、bitwise or とは、ビットごとの論理和を表します。

-----問題ここまで----- */
/* -----解説等-----

あるbitを使用しないとしたとき、それ以下のbitは1にしてもいいよ、としたほうが嬉しい。
したがってこれらを全探索

----解説ここまで---- */

LL N,K;

LL ans = 0LL;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	VL val(N), cost(N);
	FOR(i, 0, N) {
		cin >> val[i] >> cost[i];
	}


	// K 以下の bin, 000010/11111をつくる
	FOR(i, 0, 30) {
		LL num = 0;
		LL ret = 0;
		if ((K&(1 << i)) == 0) {
			continue;
		}
		// Kのあるビットをへし折ったときはK以下になる
		FOR(j, 0, i) {
			num |= (1 << j);
		}
		FOR(j, i + 1, 31) {
			if (K&(1 << j))num |= (1 << j);
		}
		//print_bin(num);
		FOR(j, 0, N) {
			if ((num | val[j]) == num) {
				ret += cost[j];
			}
		}
		ans = max(ans, ret);
	}
	{ // Kのとき
		LL ret = 0;
		LL num = K;
		FOR(j, 0, N) {
			if ((num | val[j]) == num) {
				ret += cost[j];
			}
		}
		ans = max(ans, ret);

	}
	cout << ans << "\n";

	return 0;
}
