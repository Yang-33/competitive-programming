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

/* -----  2018/03/05  Problem: 066_arc_b / Link: https://arc066.contest.atcoder.jp/tasks/arc066_b?lang=en  ----- */
/* ------問題------

正の整数 N が与えられます。 2 つの整数 u,v(0≦u,v≦N) であって、ある非負整数 a,b が存在して、a xor b=u、a+b=v となるようなものが何通りあるかを求めてください。 ここで、xor はビットごとの排他的論理和を表します。 なお、答えは非常に大きくなることがあるので、109+7 で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

OEISさん…(A007729)
を使ってまずO(N logN)の部分和を求めることができる。
部分和と数列からいい感じに部分和を作り出すことができる。
変形によって部分和は再帰的に求めることができるので、O(logN)で解ける。

部分和のサイズをn+1にしてハマった。
部分和から部分和みたいなときは関係性が知りたいので数字は気にしなくてもいいかも…

----解説ここまで---- */

LL ans = 0LL;

//LL solve(int u, int v) {
//	FOR(a, 0, 1000) {
//		FOR(b, 0, 1000) {
//			if ((a^b) == u && (a + b == v)) {
//				return 1;
//			}
//		}
//	}
//
//	return 0;
//}


LL solve(LL x ) {
	if (x < 2)return x;
	if (x % 2 == 0) {
		return solve(x / 2);
	}
	else {
		return( solve((x - 1) / 2) + solve((x + 1) / 2))%MOD;
	}
 }

LL solvesum(LL x) {
	LL ret = 0;
	FOR(i, 0, x+2) {
		ret += solve(i);
	}

	return ret;
}


map<LL, LL >memo;
map<LL, int >look;
LL solveQ(LL x) {
	if (x < 2)return (x);
	if (look[x])return memo[x];
	LL & ret = memo[x];
	ret = ( solveQ((x)/2) + solveQ((x-1) / 2)+ solveQ((x +1) / 2)) % MOD;
	look[x] = 1;
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	//FOR(N, 1, 20) {
	//	LL ret = 0;
	//	FOR(u, 0, N + 1) {
	//		FOR(v, 0, N + 1) {
	//			ret += (solve(u, v));
	//		}
	//	}
	//	debug(ret);
	//}
	//VI test({ 1, 2, 4, 5, 8, 10, 13, 14, 18, 21, 26, 28, 33, 36, 40, 41, 46, 50, 57, 60 });
	//FOR(i, 0, 10000) {
	//	assert(solvesum(i) == solveQ(1 + i));
	//	if (i % 10 == 0)cout << i << endl;
	//	//cout<< test[i]<<", "<<solvesum(i) << ", "<<solveQ(1+i)<< endl;
	//}
	LL N; cin >> N;
	ans = solveQ(N+1);
	cout << ans << "\n";

	return 0;
}
