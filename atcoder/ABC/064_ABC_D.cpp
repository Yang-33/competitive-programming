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

/* -----  2018/02/15  Problem: 064_abc_d / Link: https://abc064.contest.atcoder.jp/tasks/abc064_d?lang=en ----- */
/* ------問題------

( と ) で構成される N 文字の文字列 S が与えられる。S にいくつかの ( または ) を挿入することで正しい括弧列を作りたい。
ただし、正しい括弧列は次のように定義されている：

() は正しい括弧列である。
X が正しい括弧列であるとき、(、X、) をこの順につなげたものは正しい括弧列である。
X、Y が正しい括弧列であるとき、X と Y をこの順につなげたものは正しい括弧列である。
それ以外の括弧列は正しくない。
そのとき、作れる最も文字数が少ない正しい括弧列を求めなさい。このようなものが複数ある場合は、辞書順最小のものを求めなさい。

-----問題ここまで----- */
/* -----解説等-----

存在する数はDPでできるけど、辞書順最小なので前に（を、後ろに）をたくさんつけたほうがいい感じになる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s;
	cin >> s;
	stack<int>st1; // (
	stack<int>st2; // )
	FOR(i, 0, N) {
		if (s[i] == '(') {
			st1.push(1);
		}
		else { // )
			if (SZ(st1))st1.pop();
			else st2.push(1);
		}
	}
	FOR(i, 0, SZ(st2)) {
		cout << "(";
	}
	cout << s;
	FOR(i, 0, SZ(st1)) {
		cout << ")";
	}
	cout << endl;



	return 0;
}
