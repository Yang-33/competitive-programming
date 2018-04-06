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

/* -----  2018/03/12  Problem: 081_arc_c / Link: https://arc081.contest.atcoder.jp/tasks/arc081_c?lang=en  ----- */
/* ------問題------

文字列 S に対して，その文字列を構成する文字を 0 文字以上取り除き，残った文字を元の順番で並べて得られる文字列を S の部分列と呼びます． たとえば，arc や artistic や (空文字列) は artistic の部分列ですが，abc や ci は artistic の部分列ではありません．
英小文字からなる文字列 A が与えられます． このとき，英小文字からなる文字列で，A の部分列ではないようなもののうち，最も短いものを求めてください． ただし，そのようなものが複数ある場合には，辞書順で最小のものを求めてください．

-----問題ここまで----- */
/* -----解説等-----

後ろからやる。
長さ最小を考えたとき、アルファベットが全種出てくる回数＋１文字必要。
このとき、登場していないものが最小のものとなる。
これを後ろから記録していき、復元すれば良い。
復元は登場するまでスキップできる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	// 長さが最小
	VI alinfo(26, 0);
	VI premin(SZ(s) + 1, 0);
	ans = 1;
	FORR(i, SZ(s) - 1, 0 - 1) {

		LL ret = 0;
		alinfo[s[i] - 'a'] = 1;
		premin[i] = premin[i+1];
		FOR(al, 0, 26) {
			if (alinfo[al])ret++;
			else break;
		}
		if (ret == 26) {
			FOR(al, 0, 26) {
				alinfo[al] = 0;
			}
			ans++;
		}
		premin[i] = ret % 26;

	}
	//FOR(i, 0, 26) {
	//	cout << alinfo[i] << " ";
	//}cout << endl;	
	//debug(ans);
	FOR(i, 0, SZ(s)) {
		char c = 'a' + premin[i];
		cout << c;
		while (i < SZ(s) && s[i] != (c))i++;
	}
	cout << "\n";

	return 0;
}
