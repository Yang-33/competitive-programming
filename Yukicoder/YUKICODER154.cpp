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

/* -----  2018/05/05  Problem: yukicoder 154  / Link: http://yukicoder.me/problems/no/154  ----- */
/* ------問題------

京都の市バスは，いくつかの系統のバスが走っています．
各系統ごとに，その日の最終バスと最終バスの 1 つ前のバスは，表示板のライトの色が通常と違います．
通常のライトの色は白ですが，最終バスの1つ前のバスのライトの色は緑，最終バスのライトの色は赤になります．
yukiさんは始発から終バスまで，とある道路で通る全てのバスのライトの色をチェックして，ライトの色を見た順番にメモに残しました．
yukiさんはメモを間違えて取ってないかを心配です．
このメモが示すライトの色の順番があり得るパターンなのかどうかをチェックするプログラムを書いてください．
ただし，全ての系統の市バスは毎日 3 本以上走っており，1 日を通じて同じ経路を通るとする．

-----問題ここまで----- */
/* -----解説等-----

Wをたくさん持っても一つ持ってもよいのがちょっと面倒なので、  
2つパラメーターをもてばいいかんじになった。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(kim, 0, T) {
		string s; cin >> s;
		int W = 0;// count
		int WW = 0;// 回収したか
		int G = 0;
		int ok = 1;
		FOR(i, 0, SZ(s)) {
			if (s[i] == 'W') {
				W++;
				WW++;
			}
			else if (s[i] == 'G') {
				WW = 0;
				W--;
				G++;
			}
			else {
				G--;
			}
			if (W < 0 || G < 0)ok = 0;
		}

		ok &= (G == 0 && WW == 0);

		cout << (ok ? "possible" : "impossible") << "\n";
	}

	return 0;
}
