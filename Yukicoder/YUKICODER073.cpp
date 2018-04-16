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

/* -----  2018/04/16  Problem: yukicoder 073  / Link: http://yukicoder.me/problems/no/073  ----- */
/* ------問題------

A君は、helloworldを愛してやまない． 文字列Sのhelloworld数を次を満たす組(i0,⋯,i9)の個数とする．

S[i0]S[i1]⋯S[i9]="helloworld"
i0<i1<⋯<i9 アルファベットの個数が与えられるので、 それぞれのアルファベットをちょうどその個数だけ使ってできる文字列におけるhelloworld数の最大値を求めよ．

-----問題ここまで----- */
/* -----解説等-----

"O","L"の配置のみ考えればよく、他の文字は一箇所に配置しないとそもそも選択できない。  
Oは二箇所に配置するので、[x][y]のように配置すると考える。これはx+y=O,max{xy}なのでO(1)で求められる。  
Lも二箇所に配置する。[xy][z]のように配置なので、これはx+y+z=L,max{xyz}で一見大変そうだが、xyは連続なので、max{comb(x+y,2)*z}となり、簡単に求められる。  
極値も取れそうだけど、面倒なので計算させれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI cnt(26, 0);
	for (int&i : cnt) {
		cin >> i;
	}
	string s = "hewrd";
	ans = 1;
	FOR(i, 0, SZ(s)) {
		ans *= cnt[s[i] - 'a'];
	}
	int O = (cnt['o' - 'a']);
	int x = (O + 1) / 2;
	ans *= (-x*x + O*x);
	int ret = 0;
	int L = (cnt['l' - 'a']);
	FOR(i, 1, L) {
		int leftL = L - i;
		int comb = leftL*(leftL-1) / 2;
		ret = max(ret, i*comb);
	}

	ans *= ret;
	cout << ans << "\n";

	return 0;
}
