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

/* -----  2017/11/01  Problem: AOJ 0555 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0555  ----- */
/* ------問題------

あなたは N 個の指輪を持っている．どの指輪にも，アルファベットの大文字 10 文字からなる文字列が刻印されている．
指輪には文字列の最初と最後がつながった形で文字が刻印されている．指輪に刻印された文字列を逆順に読む心配はない．
探したい文字列が与えられたとき，その文字列を含む指輪が何個あるかを求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

周回するのはめんどくさいのでいつもの2倍するやつでOK

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string target; cin >> target;
	cin >> N;
	FOR(i, 0, N) {
		string str; cin >> str;
		str += str;
		if (str.find(target) < str.size())ans++;
	}
	cout << ans << "\n";

	return 0;
}
