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

/* -----  2018/06/10  Problem: AOJ 2369 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2369  ----- */
/* ------問題------

外見からねこかどうかわからない動物がいる. あなたは, 鳴き声がねこの鳴き声であればねこであり, そうでなければうさぎであると判定することにした.

ねこの鳴き声は次のように定義される.

"" (empty string) はねこの鳴き声である.
X, Y がねこの鳴き声であれば 'm' + X + 'e' + Y + 'w' は猫の鳴き声である. ただし + は文字列の連結を表す.
以上で定義されるものだけがねこの鳴き声である.
BNF で表すとねこの鳴き声 CAT は
CAT := "" (empty string) | 'm' + CAT + 'e' + CAT + 'w'
と定義される.

鳴き声を表す文字列 S が与えられる. 鳴き声から動物が何であるか判定せよ.

-----問題ここまで----- */
/* -----解説等-----

解法がたくさんありそう。
区間DP(判定)
再帰的にcut
置換
正規表現?

今回は区間DPぽくといた

----解説ここまで---- */



string str;
int checked[600][600];
string Cat = "Cat";
string Rab = "Rabbit";

// ? [l,r] のmewが正しい状態かを確認する O(N^3)
string check(int l, int r) {
	if (l - 1 == r)return Cat;
	if (str[l] != 'm' || str[r] != 'w')return Rab;
	if (checked[l][r] != 0) {
		if (checked[l][r])return Cat;
		else return Rab;
	}
	int flag = -1;
	for (int i = l + 1; i <= r - 1; i++) {
		if (str[i] == 'e') {
			if (check(l + 1, i - 1) == Cat && check(i + 1, r - 1) == Cat)flag = 1;
		}
	}
	return (checked[l][r] = flag) == 1 ? Cat : Rab;
}

int main(void) {
	cin >> str;
	cout << check(0, str.size() - 1) << endl;
	return 0;
}