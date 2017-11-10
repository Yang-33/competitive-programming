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

/* -----  2017/11/11  Problem: AOJ 0033 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033  ----- */
/* ------問題------

図のように二股に分かれている容器があります。1 から 10 までの番号が付けられた10 個の玉を容器の開口部 A から落とし、左の筒 B か右の筒 C に玉を入れます。板 D は支点 E を中心に左右に回転できるので、板 D を動かすことで筒 B と筒 C のどちらに入れるか決めることができます。
開口部 A から落とす玉の並びを与えます。それらを順番に筒 B 又は筒 Cに入れていきます。このとき、筒 B と筒 C のおのおのが両方とも番号の小さい玉の上に大きい玉を並べられる場合は YES、並べられない場合は NO と出力するプログラムを作成してください。ただし、容器の中で玉の順序を入れ替えることはできないものとします。また、続けて同じ筒に入れることができるものとし、筒 B, C ともに 10 個の玉がすべて入るだけの余裕があるものとします。

-----問題ここまで----- */
/* -----解説等-----

bitで書くと全探索できる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		VI in(10);
		ans = 0;
		FOR(j, 0, 10)cin >> in[j];
		FOR(k, 0, 1 << 10) {
			VI a, b;
			FOR(l, 0, 10) {
				if (k&(1 << l))a.push_back(in[l]);
				else b.push_back(in[l]);
			}
			int flag = 1;
			FOR(l, 0, SZ(a) - 1)if (a[l] >= a[l + 1])flag = 0;
			FOR(l, 0, SZ(b) - 1)if (b[l] >= b[l + 1])flag = 0;
			if (flag)ans = 1;

		}
		cout << ((ans!=0)?"YES":"NO") << endl;
	}

	return 0;
}
