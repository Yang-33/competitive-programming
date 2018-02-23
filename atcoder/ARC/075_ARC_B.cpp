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

/* -----  2018/02/23  Problem: 075_arc_b / Link: https://abc063.contest.atcoder.jp/tasks/arc075_b?lang=en  ----- */
/* ------問題------

あなたが散歩していると、突然 N 体の魔物が出現しました。それぞれの魔物は 体力 という値を持ち、i 体目の魔物の出現時の体力は hi です。体力が 0 以下となった魔物は直ちに消滅します。
幸い、あなたは熟練の魔法使いであり、爆発を引き起こして魔物を攻撃できます。一回の爆発では、以下のように魔物の体力を減らすことができます。
生存している魔物を一体選び、その魔物を中心に爆発を引き起こす。爆発の中心となる魔物の体力は A 減り、その他の魔物の体力はそれぞれ B 減る。ここで、A と B はあらかじめ定まった値であり、A>B である。
すべての魔物を消し去るためには、最小で何回の爆発を引き起こす必要があるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

A>Bなので攻撃回数xがわかればB*xのダメージを与えることができる。
のこったHPは削らないと行けないので中心として選択することでA-Bだけ減らすことができる。
回数が大きいほど倒しやすく、これには単調性があるので解について二分探索できる。
解空間は(L,R].

----解説ここまで---- */

LL N,A,B;

LL ans = 0LL;


bool f(LL x, VL &h) {// x回で倒せるか
	LL cnt = 0;
	FOR(i, 0, N) {
		LL lefth = h[i] - x*B;
		LL atk = (lefth+A-B-1)/(A-B);
		if(lefth>0)cnt += atk;
	}
	return cnt <= x;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>A>>B;
	VL h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	RSORT(h);

	LL L = 0; LL R = INF;
	FOR(i, 0, 50) {
		LL mid = (L + R) / 2;
		if (f(mid, h)) {
			R = mid;
		}
		else L = mid;
	}
	cout << R << endl;

	return 0;
}
