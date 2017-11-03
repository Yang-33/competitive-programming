#include "bits/stdc++.h"
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
 
/* -----  2017/11/03  Problem: DDCC2017_final B / Link: http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b ----- */
/* ------問題------
 
高橋君は N 台のロボットを持っています。ロボットには番号 1,2,…,N がついています。
ロボットにはそれぞれ正整数が 1 つ書かれており、番号 i のロボットには ai が書かれています。
番号 i のロボットは、正整数 X,Y を渡すと、gcd(X,ai)=gcd(Y,ai) ならば「似てる」、そうでないならば「似てない」と言います。なお、この問題では gcd(X,Y) は X と Y の最大公約数とします。
正整数 X,Y について、N 台のロボット全てが「似てる」と言った時、X と Y はそっくりさんだとすることにします。
正整数 Z が与えられるので、Z とそっくりさんな数のうち、もっとも小さいものを求めてください。
 
-----問題ここまで----- */
/* -----解説等-----
 
gcd + lcm 
思いついて♡
 
----解説ここまで---- */
 
LL N;
 
LL ans = 0LL;
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long lcm(LL a, LL b){
	return a/gcd(a,b)*b;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL Z;
	cin >> N >> Z;
	VL a(N);
	FOR(i, 0, N)cin >> a[i];
	VL v;
	map<LL, LL>m;
	LL c7 = 1;
	FOR(i, 0, N) {
		LL ret = gcd(a[i], Z);
		c7 = lcm(c7, ret);
		m[ret] = 1;
		v.push_back(ret);
	}
	SORT(v);
	UNIQ(v);
 
	ans = 1;
	FOR(i, 0, SZ(v)) {
		if (ans%v[i] != 0)ans *= v[i];
	}
	FOR(i, 0, SZ(v)) {
		if (ans % (v[i] * v[i]) == 0)ans /= v[i];
	}
	//debug(ans);
 
 
 
	//for (auto it = m.begin(); it != m.end(); it++) {
	//	if(it->second>=1)ans *= it->first;
	//	for (auto it2 =it; it2 != m.end(); it2++) {
 
	//		if (it2->first % it->first==0)it2->second = 0;
	//	}
 
	//}
 
 
	cout << c7 << "\n";
 
	return 0;
}