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

/* -----  2018/04/09  Problem: yukicoder 022  / Link: http://yukicoder.me/problems/no/022  ----- */
/* ------問題------

Orinoは、テキストの括弧の対応箇所を見つけるプログラムを書きたいと思っている。
括弧の対応とは、
1.与えられた文字列から、「(」の直後に「)」が来る文字があるとき、文字列からその２つの文字を削除する。
2.削除された文字を新たな文字列として、1.の処理を繰り返し、文字列が空になるまで繰り返す。

そして、初めに与えられた文字列として考えた時のi番目文字と一緒に削除されるj番目に対応する文字が「括弧の対応」であるとする。
「(」と「)」のみで構成されるN文字の文字列が与えられ、
さらに整数値K (1≤K≤N)が与えられる。

このとき、K番目の文字と対応する文字の箇所の番目を求めてください。
与えられる文字列は、すべての文字で括弧の対応があると保証されるとする。

-----問題ここまで----- */
/* -----解説等-----

ある括弧に対応する括弧の位置はstackでわかるので、
K番目のものだけ色付けをして発見すればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int  K; cin >> N >> K;
	string s; cin >> s;


	if (s[K-1] == '(') {
		stack<int>st;
		FOR(i, 0, SZ(s)) {
			if (s[i] == '(') {
				if (K - 1 == i)st.push(1);
				else st.push(0);
			}
			else {
				if (SZ(st)) {
					int a = st.top(); st.pop();
					if (a)ans = i+1;
				}
			}
		}
	}
	else {
		stack<int>st;
		FORR(i, SZ(s)-1, 0-1) {
			if (s[i] == ')') {
				if (K - 1 == i)st.push(1);
				else st.push(0);
			}
			else {
				if (SZ(st)) {
					int a = st.top(); st.pop();
					if (a)ans = i+1;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
