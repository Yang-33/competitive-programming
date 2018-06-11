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

/* -----  2018/06/10  Problem: AOJ 2312 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2312  ----- */
/* ------問題------

世の中の少女たちはキュゥべえと契約し願いを叶えてもらい，それとひきかえに魔法少女となる．使う魔法の形・効果は願いに強く影響を受ける．魔法少女さやかちゃんは最近キュゥべえと契約した新米魔法少女である．さやかの願いは「事故のため指が動かなくなり，音楽を演奏するのを諦めていた男の子を助けること」であったので，作る魔方陣は音符が輪の上に並んだ形をしている．
さやかは N 個の音符を持っており，それらを輪の上に並べることによって魔方陣を作る．音符をどのような順番で並べるかは彼女の自由である．魔方陣を作るために精神力が消費され，その量は音符の配置によって以下のように決まる．
まず， M 個の正の整数からなる音楽的美しさ S1, …, SM が定められている，
各音符は音程を持っており，音程は 1 から M の整数 K1, …, KN で表される．
音程が a, b (a≤b) であるような 2 つの音符の間の反発力とは， [(Sa + … + Sb)⁄L] で定められる量である．ここで，L は入力で与えられる定数であり，実数 x に対して [x] は x を越えない最大の整数を表すものとする．
さやかの消費する精神力は，各2つの隣り合う音符 (N 組存在する) の間の反発力の合計値である．
例えば音楽的美しさがそれぞれ {100, 200, 300, 400, 500} で，音程が {1, 3, 5, 4} である音符をこの順番で並べて魔方陣を作った時，消費される精神力は 37 (=[(100+200+300)⁄99]+[(300+400+500)⁄99]+[(500+400)⁄99]+[(400+300+200+100)⁄99]) となる．

使うべき音符の音程の組み合わせと各音程の音楽的美しさが与えられるので，消費される精神力の最小値を求めよ．

-----問題ここまで----- */
/* -----解説等-----

明らかに円環でDPなので、これはバイトニック巡回セールスマン問題っぽく解ける。
根からの左右の点から一個進める動作は、max(L,R)+1でできる。
あとは遷移を書けば良い。(注意として、先の遷移からO(1)しか無い)
O(N)で書くけどO(N^2)になるとかいう謎思考をしてしたのでハマってしまった(最悪)

----解説ここまで---- */
using ll = LL;
ll N, M, L;

ll cost(ll l, ll r, vector<ll>& cusum) {
	if (l > r) swap(l, r);
	return (cusum[r] - cusum[l - 1]) / L;
}
ll memo[2050][2050];
ll rec(ll v1, ll v2, vector<ll>& K, vector<ll>& cusum) {
	ll& ret = memo[v1][v2];
	if (~ret) return ret;
	ret = LINF;

	int nx = max(v1, v2) + 1; // nxを選択すれば遷移幅は1

	if (nx == N) {
		return cost(K[nx], K[v1], cusum) + cost(K[nx], K[v2], cusum);
	}
	ret = min(ret, rec(nx, v2, K, cusum) + cost(K[v1], K[nx], cusum));
	ret = min(ret, rec(v1, nx, K, cusum) + cost(K[v2], K[nx], cusum));
	return ret;
}

ll solve() {

	fill(*memo, *memo + 2050 * 2050, -1);
	ll res = LINF;
	cin >> N >> M >> L;
	vector<ll> K(N + 1), S(M);
	for (int i = 1; i <= N; i++) cin >> K[i];
	for (auto& in : S) { cin >> in; }
	sort(K.begin(), K.end());
	vector<ll> cusum(M + 1);
	for (int i = 0; i < M; i++) {
		cusum[i + 1] = cusum[i] + S[i];
	}
	res = rec(1, 1, K, cusum);

	return res;
}
int main() {
	cout << solve() << endl;
	return 0;
}