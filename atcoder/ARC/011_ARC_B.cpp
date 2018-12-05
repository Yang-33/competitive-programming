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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/14  Problem: ARC 011 B / Link: http://arc011.contest.atcoder.jp/tasks/arc011_b  ----- */
/* ------問題------

古今東西、数字の記憶には様々な方法が取り入れられてきた。
例えば日本では e の値を「鮒一鉢二鉢一鉢二鉢至極惜しい」などとして記憶するし、欧米では π の値を Yes, I know a number! として記憶する。 「不思議の国のアリス」の著者として知られるルイス・キャロル (本名:チャールズ・ラトウィッジ・ドジソン) は、子音のみを用いた独自の記憶術を作り、様々な年号を記憶していたらしい。 これによれば、次のように、文字に数字を割り当てていたという。

図：文字から数字への割り当て
この表に従い、覚えたい数字を子音に変換し、これを用いた単語をひとつ作って文にすることで、キャロルは年号などを覚えていたという。
なお、子音以外の文字 (a,e,i,o,u,y や、コンマ、ピリオド等) はすべて無視され、大文字も小文字も同じように変換される。

例えば、モーツァルトの正没年は Mozart plays magic. とし、plays を 756 に変換し、 magic を 791 に変換して、 1756 年 ~ 1791 年と覚えることができるわけ である。 この方式での記憶文が与えられるとき、それを前から順に変換し、変換した数字を出力するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

場合分けする…

----解説ここまで---- */

int f(char c) {
	c = tolower(c);
	if (c == 'b' || c == 'c')return 1;
	if (c == 'd' || c == 'w')return 2;
	if (c == 't' || c == 'j')return 3;
	if (c == 'f' || c == 'q')return 4;
	if (c == 'l' || c == 'v')return 5;
	if (c == 's' || c == 'x')return 6;
	if (c == 'p' || c == 'm')return 7;
	if (c == 'h' || c == 'k')return 8;
	if (c == 'n' || c == 'g')return 9;
	if (c == 'z' || c == 'r')return 0;
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	VS ans;
	FOR(i, 0, N) {
		string sub;
		FOR(j, 0, SZ(vs[i])) {
			int res = f(vs[i][j]);
			DD(de(res));
			if (res >= 0) {
				sub += to_string(res);
			}
		}
		DD(de(sub, SZ(vs[i])));
		if (SZ(sub))ans.push_back(sub);
	}
	FOR(i, 0, SZ(ans)) {
		if (i)cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}