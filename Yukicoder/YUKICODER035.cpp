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

/* -----  2018/04/10  Problem: yukicoder 035  / Link: http://yukicoder.me/problems/no/035  ----- */
/* ------問題------

高橋くんは高速なプログラミングにはタイピング力が不可欠と考えています。
そこで、タイピングゲームでタイピング力を鍛えます。
この問題では簡単のために、タイピングする文字列はアルファベット小文字のみからなる文字列を考えます。
あるタイピングゲームでは、1 ゲームは N 個の区間に分かれており、区間 k では、Tk ミリ秒以内に Sk という文字列をタイピングしなければいけません。
高橋くんは 1 秒あたり 12 文字まで正しくタイプすることができます。
これは、1000 ミリ秒では 12 文字まで、999 ミリ秒では 11 文字までタイプできるということで、m ミリ秒では ⌊12m/1000⌋ 文字までタイプできることになります。（⌊x⌋ は x を超えない最大の整数を表します）

高橋くんはできるだけ多くの文字をタイプするとして、1 ゲーム全体で、高橋くんが正しくタイプできる文字数、および、タイプできずに逃してしまう文字数を求めるプログラムを書いてください。

-----問題ここまで----- */
/* -----解説等-----

t*12/1000って書いてあるので、これより多くあふれた文字数が打てなかった文字列。
これをカウントすればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int sum = 0;
	int size = 0;
	FOR(i, 0, N) {
		int t; string s;
		cin >> t >> s;
		size += SZ(s);
		sum += min(SZ(s),t*12/1000 );
	}
	cout << sum << " " << size - sum << endl;

	return 0;
}
